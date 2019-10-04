
// FreeCellDlg.h : header file
#pragma once
#include "cell.h"

// CFreeCellDlg dialog
class CFreeCellDlg : public CDialogEx
{
// Construction
public:
	CFreeCellDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FREECELL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	void shuffle();


// Implementation
protected:
	
	int mSelected = -1; // No cells clicked yet

	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Cell* mCells[16]; //why I have 16 pointers to Cells.
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
