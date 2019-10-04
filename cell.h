#pragma once
#include <vector>
class Cell
{
public:
	Cell(double left, double top, double right, double bottom);
	virtual void Draw(CDC& dc);

	void AddCard(int index);
	void RemoveCard();

	int Cell::CardCount();
	int Cell::GetTopCard();


	virtual bool CanRemovedCard();
	virtual bool CanAcceptCard(int index);


	bool IsClicked(int x, int y);
	void SetSelected(bool selected);
	std::vector<int> mCards;
	

protected:

	int mLeft, mTop, mRight, mBottom;
	bool mSelected = false;
	int mLastCard = -1;
	
};



class StartCell : public Cell {
public:
	StartCell(double left, double top, double right, double bottom);
	virtual void Draw(CDC& dc);
	virtual bool CanRemovedCard();
	virtual bool CanAcceptCard(int index);


private:
	double mCardHeight;
};


class FreeCell : public Cell {
public:
	FreeCell(double left, double top, double right, double bottom);
	virtual bool CanRemovedCard();
	virtual bool CanAcceptCard(int index);

};


class EndCell : public Cell {
public:
	EndCell(double left, double top, double right, double bottom);
	virtual bool CanRemoveCard();
	virtual bool CanAcceptCard(int index);

};

