
#include "pch.h"
#include "cell.h"
#include "WindowsCards.h"
#include <windows.h>
#include "FreeCellDlg.h"


Cell::Cell(double left, double top, double right, double bottom){
	mLeft = left;
	mTop = top;
	mRight = right;
	mBottom = bottom;
}
void Cell::Draw(CDC& dc)
{
	// drawing a rectungle
	CBrush cellBackgroundColor(RGB(51, 186,255));
	dc.SelectObject(cellBackgroundColor);
	dc.Rectangle(mLeft, mTop, mRight, mBottom);
	if (mCards.size() > 0) {
		DrawCard(dc, mLeft + 2, mTop + 2, mCards[mCards.size() - 1]);
	}
}

void Cell::AddCard(int index)
{
	mCards.push_back(index);
}

void Cell::RemoveCard()
{
	mCards.pop_back();
}

int Cell::CardCount() {
	return mCards.size();
}

int Cell::GetTopCard() {
	return mCards[mCards.size() - 1];
}


bool Cell::CanRemovedCard() {
	if (mCards.size() > 0) {
		return true;
	}
	else {
		MessageBox(NULL, L"Can't perform the action!", L"MessageBox caption", MB_OK);
		return false;
	}

}
bool Cell::CanAcceptCard(int index) {
	return TRUE;
}


bool Cell::IsClicked(int x, int y) {
	return (x >= mLeft && x <= mRight && y >= mTop && y <= mBottom);
}
void Cell::SetSelected(bool selected) {
	mSelected = selected;
};


//===================================================================================

StartCell::StartCell(double left, double top, double right, double bottom)
	:Cell(left, top, right, bottom) {
}

void StartCell::Draw(CDC& dc) {
	CBrush cellBackgroundColor(RGB(51, 186,255));
	dc.SelectObject(cellBackgroundColor);
	dc.Rectangle(mLeft, mTop, mRight, mBottom);
	if (mCards.size() > 0) {
		for (int i = 0; i < mCards.size(); i++) {
			DrawCard(dc, mLeft + 2, mTop + 2+ i*25, mCards[i], mSelected);
		}
	}
}

bool StartCell::CanRemovedCard() {
	return TRUE;
}
bool StartCell::CanAcceptCard(int index) {

	//int firstRedRank = index / 4;
	//int firstRedSuit = index % 4;

	//int secondRedRank = this->GetTopCard() / 4;
	//int secondCarddSuit = this->GetTopCard() % 4;


	//if (  firstCardRank == 1 || ) {
	//	return TRUE;
	//}



	if (mCards.size() == 0) {
		return TRUE;
	}
	int topCard = this->GetTopCard();
	switch (topCard % 4) {
	case(0):
		if (index == topCard - 2 || index == topCard - 3) {
			return TRUE;
		}
	case(1):
		if (index == topCard - 2 || index == topCard - 5) {
			return TRUE;
		}
	case(2):
		if (index == topCard - 3 || index == topCard - 6) {
			return TRUE;
		}
	case(3):
		if (index == topCard - 5 || index == topCard - 6) {
			return TRUE;
		}
	}
	return FALSE;
}

//===================================================================================

FreeCell::FreeCell(double left, double top, double right, double bottom)
	:Cell(left, top, right, bottom) {
}

bool FreeCell::CanRemovedCard() {
	if (mCards.size() > 0) {
		return true;
	}
}
bool FreeCell::CanAcceptCard(int index) {
	if (mCards.size() == 0) {
		return TRUE;
	}
	
	int topCard = this->GetTopCard();
	switch (topCard % 4) {
	case(0):
		if (index == topCard - 2 || index == topCard - 3) {
			return TRUE;
		}
	case(1):
		if (index == topCard - 2 || index == topCard - 5) {
			return TRUE;
		}
	case(2):
		if (index == topCard - 3 || index == topCard - 6) {
			return TRUE;
		}
	case(3):
		if (index == topCard - 5 || index == topCard - 6) {
			return TRUE;
		}
	}
	return FALSE;
}

//===================================================================================


EndCell::EndCell(double left, double top, double right, double bottom)
	:Cell(left, top, right, bottom) {
}

bool EndCell::CanRemoveCard() {
	return FALSE;
}

bool EndCell::CanAcceptCard(int index) {

	if (mCards.size() == 0) {
		if (index == 0 || index == 1 || index == 2 || index == 3) {
			return TRUE;
		}
		return FALSE;
	}

	int topCard = this->GetTopCard();
	if (index == topCard + 4) {
		return TRUE;
	}
	return FALSE;
}
