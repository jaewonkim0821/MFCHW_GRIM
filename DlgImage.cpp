// DlgImage.cpp : 구현 파일입니다.
//


#include "stdafx.h"
#include "MFCHW_GRIM.h"
#include "DlgImage.h"
#include "afxdialogex.h"
#include <afxwin.h>

// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
	
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	
	ON_WM_PAINT()
	
	ON_BN_CLICKED(Parent, &CDlgImage::OnBnClickedParent)
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.

#include "MFCHW_GRIMDlg.h"

void CDlgImage::OnBnClickedParent()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static int n = 100;
	CMFCHWGRIMDlg* pDlg = (CMFCHWGRIMDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(_T("Image"));
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage()
{
	int nWidth = 4096;
	int nHeight = 4096;
	int nBpp = 8;
	int m_nWidth = 400;
	int m_nHeight = 300;
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	if (m_image)
		m_image.Draw(dc, 0, 0);

	drawData(&dc);
}


void CDlgImage::drawData(CDC* pDC)
{
	CRect rect;
	CPen pen;

	pen.CreatePen(PS_SOLID, 2, RGB(255,0,0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(1, 1);
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);
}




