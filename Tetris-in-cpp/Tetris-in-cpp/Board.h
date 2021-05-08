#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

// ---- Defines ----

#define BOARD_LINE_WIDTH 6  // board ����؂�2�{�̃��C����
#define BLOCK_SIZE 16       // piece block �� width & height
#define BOARD_POSITION 320  // board �̒����ʒu, �X�N���[���̍�����̋���
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define MIN_VERTICAL_MARGIN 20   // board ���E�̍ŏ��}�[�W��
#define MIN_HORIZONTAL_MARGIN 20 
#define PIECE_BLOCKS 5           // piece �s��̏c���u���b�N��

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
	enum { POS_FREE, POS_FILLED }; //POS_FREE = board ��̋󂢂Ă�ӏ�; POS_FILLED = board ��̖��܂��Ă�ӏ�
	int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
	Pieces* mPieces;
	int mScreenHeight;
	void InitBoard();
	void DeleteLine(int pY);

};

#endif // _BOARD_
