#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

// ---- Defines ----

#define BOARD_LINE_WIDTH 6  // board を区切る2本のライン幅
#define BLOCK_SIZE 16       // piece block の width & height
#define BOARD_POSITION 320  // board の中央位置, スクリーンの左からの距離
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20   // board 限界の最小マージン
#define MIN_HORIZONTAL_MARGIN 20 
#define PIECE_BLOCKS 5           // piece 行列の縦横ブロック数

// ---- Board

class Board
{
public:
	Board(Pieces* pPieces, int pScreenHeight);

	int GetXPosInPixels(int pPos);
	int GetYPosInPixels(int pPos);
	bool IsFreeBlock(int pX, int pY);
	bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
	void StorePiece(int pX, int pY, int pPiece, int pRotation);
	void DeletePossibleLines();
	bool IsGameOver();

private:
	enum { POS_FREE, POS_FILLED }; //POS_FREE = board 上の空いてる箇所; POS_FILLED = board 上の埋まってる箇所
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
	Pieces* mPieces;
	int mScreenHeight;
	void InitBoard();
	void DeleteLine(int pY);

};

#endif // _BOARD_
