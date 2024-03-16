
// MFCHW_GRIMDlg.h: 헤더 파일
//
#include "DlgImage.h"
#pragma once


// CMFCHWGRIMDlg 대화 상자
class CMFCHWGRIMDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCHWGRIMDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	CDlgImage* m_pDlgImage;
	CDlgImage* m_pDlgImgResult;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCHW_GRIM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();

	void callFunc(int n);
	
	afx_msg void OnBnClickedProcess();
	afx_msg void OnBnClickedMakepattern();
	afx_msg void OnBnClickedTest();

	afx_msg void OnBnClickedGetdata();
	int processImg(CRect rect);
	afx_msg void OnBnClickedMakeCircle();
	afx_msg void OnBnClickedGetdata2();
};
