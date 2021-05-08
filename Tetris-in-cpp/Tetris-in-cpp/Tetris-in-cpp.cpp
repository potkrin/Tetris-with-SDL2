// Tetris-in-cpp.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

#include <iostream>
#include "SDL.h"

#include "Pieces.h"
#include "Board.h"
#include "Game.h"

using namespace std;

char mPieces[7][4][5][5] = {
  //square
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //I
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 1, 2, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 2, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 1, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //L
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 1, 2, 1, 0},
      {0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 1, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0},
      {0, 1, 2, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //L mirrored
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 1, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0},
      {0, 1, 2, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 1, 2, 1, 0},
      {0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //N
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 1, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 1, 2, 0, 0},
      {0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 1, 2, 0, 0},
      {0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 1, 1, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //N-mirrored
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 1, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0},
      {0, 1, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0},
      {0, 1, 2, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
  },
  //T
  {
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 2, 1, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 1, 2, 1, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 1, 2, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0},
    },      
    {
      {0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0},
      {0, 1, 2, 1, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    },
  },
};

int mPiecesInitialPosition[7][4/* rotation */][2/* position */] =
{
  //square
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -3},
  },
  //I
  {
    {-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3},
  },
  //L
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2},
  },
  //L-mirrored
  {
    {-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3},
  },
  //N
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2},
  },
  //N-mirrored
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2},
  },
  //T
  {
    {-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2},
  },
};

int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY]; 
}

int Pieces::GetXInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][0]; 
}

int Pieces::GetYInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][1]; 
}

// from Board.h

// board constractor
Board::Board(Pieces* pPieces, int pScreenHeight)
{
    // Get the screen height
    mScreenHeight = pScreenHeight;

    // Get the pointer to the pieces class
    mPieces = pPieces;

    //Init the board blocks with free positions
    InitBoard();
}


// Init the board blocks with POS_FREE
void Board::InitBoard()
{
    for (int i = 0; i < BOARD_WIDTH; i++) 
        for (int j = 0; j < BOARD_HEIGHT; j++) 
            mBoard[i][j] = POS_FREE;
}

/* store a piece in the board by filling the blocks
parameters
pX: Horizontal position in blocks
pY: Vertical position in blocks
pPiece: Piece to draw
pRotation: 1 of 4 possible rotations
*/

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (mPieces->GetBlockType(pPiece, pRotation, i2, j2) != 0)
                mBoard[i1][j1] = POS_FILLED;
        }
    }
}

// if there are blocks in first row, the game is over.
bool Board::IsGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (mBoard[i][0] == POS_FILLED)
            return true;
    }
    return false;
}

void Board::DeleteLine(int pY)
{
    for (int j = pY; j > 0; j--) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            mBoard[i][j] = mBoard[i][j - 1];
        }
    }
}

void Board::DeletePossibleLines()
{
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while (i < BOARD_WIDTH) {
            if (mBoard[i][j] != POS_FILLED)
                break;
            i++;
        }
        if (i == BOARD_WIDTH) DeleteLine(j);
    }
}

bool Board::IsFreeBlock(int pX, int pY) {
    if (mBoard[pX][pY] == POS_FREE)
        return true;
    else
        return false;
}

/* returns the horizontal position (in pixels) of the block given like parameter 
pPos: Horizontalposition of the block in the board
*/
int Board::GetXPosInPixels(int pPos)
{
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

/* returns the vertical position (in pixels) of the block given like parameter 
pPos: Horizontalposition of the block in the board
*/
int Board::GetYPosInPixels(int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * (BOARD_HEIGHT/ 2))) + (pPos * BLOCK_SIZE));
}


/* check if the piece can be stored at this position without any collision
*  return true if possible
pX: Horizontal position in blocks
pY: Vertical position in blocks
pPiece: Piece to draw
pRotation: 1 of 4 possible rotation
*/
bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (i1<0 || i1>BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT) {
                if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
                    return false;
            }

            // check if the piece have collision with blocks already stored on board
            if (j1 >= 0) {
                if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1)))
                    return false;
            }
        }
    }
    //no collision
    return true;
}

// ---- from Game.h ----
//
Game::Game(Board * pBoard, Pieces * pPieces, IO * pIO, int pScreenHeight)
{
    mScreenHeight = pScreenHeight;

    // Get the pointer to the Board and Pieces classes
    mBoard = pBoard;
    mPieces = pPieces;
    mIO = pIO;

    // Game initialization
    InitGame();
}

// returns a random number between two boundaries
int Game::GetRand(int pA, int pB)
{
    return rand() % (pB - pA -1) + pA;
}

// init parameters of the game
void Game::InitGame()
{
    //init random numbers
    srand((unsigned int)time(NULL));

    //first piece
    mPiece = GetRand(0, 6);
    mRotation = GetRand(0, 3);
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetXInitialPosition(mPiece, mRotation);

    //next piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
    mNextPosX = BOARD_WIDTH+5;
    mNextPosY = 5;
}

// create a random piece
void Game::CreateNewPiece()
{
    // the new piece
    mPiece = mNextPiece;
    mRotation = mNextRotation;
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetXInitialPosition(mPiece, mRotation);

    //next piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}

/* draw a piece
pX: Horizontal position in blocks
pY: Vertical position in blocks
pPiece: Piece to draw
pRotation: 1 of 4 possible rotations
*/

void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
    color mColor;

    // obtain the position in pixel in the screen of the block we want to draw
    int mPixelsX = mBoard->GetXPosInPixels(pX);
    int mPixelsY = mBoard->GetYPosInPixels(pY);

    // travel the matrix of blocks of the piece and draw the blocks that are filled
    for (int i = 0; i < PIECE_BLOCKS; i++) {
        for (int j = 0; j < PIECE_BLOCKS; j++) {
            switch (mPieces->GetBlockType(pPiece, pRotation, j, i))
            {
				case 1: mColor = GREEN; break;
				case 2: mColor = BLUE; break;  // for the pivot
            }

            if ((mPieces->GetBlockType(pPiece, pRotation, j, i)) != 0) {
                mIO->DrawRectangle(
                    mPixelsX + i * BLOCK_SIZE,
                    mPixelsY + j * BLOCK_SIZE,
                    (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    mColor
                    );
            }
        }
    }
}

// draw board 
void Game::DrawBoard()
{
    //calculate the limits of the board in pixels
    int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
    int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
    int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

    mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRectangle(mX2 , mY, mX2+BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

    // drawing the blocks stored in the board
    mX1 += 1;
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            //check if the block is filled
            if (!mBoard->IsFreeBlock(i, j)) {
                mIO->DrawRectangle(
                    mX1 + i * BLOCK_SIZE,
                    mY + j * BLOCK_SIZE,
                    (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
                    RED);

            }
        }
    }
}

// Draw all
void Game::DrawScene()
{
    DrawBoard();
    DrawPiece(mPosX, mPosY, mPiece, mRotation);
    DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}




int main(int argc, char** argv)
{
    /*
    SDL_Init(SDL_INIT_EVERYTHING);
    std::cout << "Hello World!\n";

    SDL_Window* window;

    window = SDL_CreateWindow("Subsc!",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        400, // window_width
        200, // window_height
        SDL_WINDOW_RESIZABLE);

    if (window = NULL) {
        cout << "There was error initializing the window! " << endl
            << SDL_GetError() << endl;
    }

    SDL_Delay(5000);
    SDL_DestroyWindow(window);

    SDL_Quit();
    */

    // class for drawing staff, it uses SDL for the rendering
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;
    
    Board mBoard(&mPieces, mScreenHeight);

    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    unsigned long mTime1 = SDL_GetTicks();
    
    //---- Main loops ----
    while (!mIO.IsKeyDown(SDLK_ESCAPE))
    {
        //---- Draw ----
        mIO.ClearScreen();
        mGame.DrawScene();
        mIO.UpdateScreen();

        //---- Input ----
        int mKey = mIO.Pollkey();
        switch (mKey) {
			case (SDLK_RIGHT):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX++;
				break;
			}

			case (SDLK_LEFT):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
					mGame.mPosX--;
				break;
			}

			case (SDLK_DOWN):
			{
				if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
					mGame.mPosY++;
				break;
			}        
            case (SDLK_x):
            {
                // Check collision from up to down
                while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

                mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

                mBoard.DeletePossibleLines();

                if (mBoard.IsGameOver())
                {
                    mIO.Getkey();
                    exit(0);
                }

                mGame.CreateNewPiece();

                break;
            }
            case (SDLK_z):
            {
                if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
                    mGame.mRotation = (mGame.mRotation + 1) % 4;

                break;
            }
            
        }
		// ----- Vertical movement -----

		unsigned long mTime2 = SDL_GetTicks();

		if ((mTime2 - mTime1) > WAIT_TIME)
		{
			if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
			{
				mGame.mPosY++;
			}
			else
			{
				mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

				mBoard.DeletePossibleLines();

				if (mBoard.IsGameOver())
				{
					mIO.Getkey();
					exit(0);
				}

				mGame.CreateNewPiece();
			}

			mTime1 = SDL_GetTicks();
		}
    }

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
