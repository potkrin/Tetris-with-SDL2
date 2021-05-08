* [面白そうなサイト](http://utsukemononi.gozaru.jp/gc/sdl/index.html)

## Visual Studio 2019 で 環境構築
* [参考にしたサイト](https://papersloth.hatenablog.com/entry/2019/01/22/225257)

1. SDL2 の準備
  * 公式からDL&解答
  * 適当なフォルダに配置

2. 新規プロジェクト -> コンソールアプリ

3. 上部のプロジェクト -> プロパティ

4. 構成: すべての構成  プラットフォーム: 適切に設定

5. C/C++ -> 全般 -> 追加のインクルードディレクトリ
   C:\work_space\org\SDL2-2.0.14\include

6. リンカー -> 全般 -> 追加のライブラリディレクトリ
   C:\work_space\org\SDL2-2.0.14\lib\x64 or
   C:\work_space\org\SDL2-2.0.14\lib\x86

7. リンカー -> 入力 -> 追加の依存ファイル
   SDL2.lib
   SDL2main.lib

8. ビルドイベント -> ビルド後のイベント
   xcopy "(SDLへのパス)\x86\*.dll" "$(OutDir)" /i /s /y   または
   xcopy "(SDLへのパス)\x64\*.dll" "$(OutDir)" /i /s /y

9. main関数を修正
   SDLを使用する際の注意点
    まず、SDLを使用する際に下記の記述をするとエラーになってしまいます。

    ```
    #include "SDL.h"

    int main()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        // メイン処理
        SDL_Quit();
        return 0;
    }
    ```
    エラーメッセージを見てみると
    LNK2019 未解決の外部シンボル _SDL_main が関数 _main_getcmdline で参照されました。
    と出てきます。

    これはSDL_main.h内でmainでdefineが定義されているからです。

    #if defined(SDL_MAIN_NEEDED) || defined(SDL_MAIN_AVAILABLE)
    #define main    SDL_main
    #endif
    また、SDL_main.h内にはメイン関数は次のように定義してくださいと書かれています。

    int main(int argc, char *argv[])

    そのため、SDLを使用する際には引数付きのメイン関数を定義する必要があります。

    ```
    void main() // NG!
    int main() // NG!
    int main(int argc, char* argv[]) // OK
    int main(int argc, char** argv) // OK
    ```