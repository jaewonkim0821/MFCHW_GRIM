
// MFCHW_GRIMDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCHW_GRIM.h"
#include "MFCHW_GRIMDlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCHWGRIMDlg 대화 상자



CMFCHWGRIMDlg::CMFCHWGRIMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCHW_GRIM_DIALOG, pParent)
{
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMFCHWGRIMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCHWGRIMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(Process, &CMFCHWGRIMDlg::OnBnClickedProcess)
	ON_BN_CLICKED(MakePattern, &CMFCHWGRIMDlg::OnBnClickedMakepattern)
	ON_BN_CLICKED(Test, &CMFCHWGRIMDlg::OnBnClickedTest)
	ON_BN_CLICKED(GetData, &CMFCHWGRIMDlg::OnBnClickedGetdata)
	ON_BN_CLICKED(MakeCircle, &CMFCHWGRIMDlg::OnBnClickedMakeCircle)
	ON_BN_CLICKED(GetData2, &CMFCHWGRIMDlg::OnBnClickedGetdata2)
END_MESSAGE_MAP()


// CMFCHWGRIMDlg 메시지 처리기

BOOL CMFCHWGRIMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCHWGRIMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCHWGRIMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCHWGRIMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCHWGRIMDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pDlgImage)		delete m_pDlgImage;
	if (m_pDlgImgResult)	delete m_pDlgImgResult;
}

void CMFCHWGRIMDlg::OnBnClickedTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);

	for (int k = 0; k < MAX_POINT; k++) {
		int x = rand() % nWidth;
		int y = rand() % nHeight;
		fm[y * nPitch + x] = rand() % 0xff;
		//m_pDlgImgResult->m_nDataCount = k;
		//m_pDlgImgResult->m_ptData[k].x = x;
		//m_pDlgImgResult->m_ptData[k].y = y;
	}

	int nIndex = 0;
	int nTh = 100;
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j * nPitch + i] > nTh) {
				if (m_pDlgImgResult->m_nDataCount < MAX_POINT) {
					//cout << nIndex << ":" << i << "," << j << endl;
					m_pDlgImgResult->m_ptData[nIndex].x = i;
					m_pDlgImgResult->m_ptData[nIndex].y = j;
					m_pDlgImgResult->m_nDataCount = ++nIndex;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();

}

#include "Process.h"
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
using namespace chrono;

void CMFCHWGRIMDlg::OnBnClickedProcess()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	auto start = system_clock::now();

	CProcess process;
	int nTh = 0;
	int nRet = process.getStarInfo(&m_pDlgImage->m_image, nTh);
	//	Sleep(1000);
	//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	auto end = system_clock::now();
	auto millisec = duration_cast<milliseconds>(end - start);

	cout << nRet << "\t" << millisec.count() * 0.001 << "sec" << endl;
}


void CMFCHWGRIMDlg::OnBnClickedMakepattern()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);

	CRect rect(100, 100, 200, 200);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			fm[j * nPitch + i]  =100;
		}
	}
	m_pDlgImage->Invalidate();
}

void CMFCHWGRIMDlg::callFunc(int n)
{
	std::cout << n << std::endl;
}





void CMFCHWGRIMDlg::OnBnClickedGetdata()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	int nTh = 0;
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	CRect rect(0, 0, nWidth, nHeight);
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			if (fm[j * nPitch + i] > nTh) {
				nSumX += i;
				nSumY += j;
				
				nCount++;
			}
		}
	}
	double dCenterX = 0.0;
	double dCenterY = 0.0;
	
	// 픽셀 개수가 0이 아닌 경우 무게 중심 계산
	if (nCount >= 0) {
		dCenterX = (double)nSumX / nCount;
		dCenterY = (double)nSumY / nCount;
	}
	else {
		// 무게 중심을 계산할 수 없는 경우 처리
		// 예: 메시지 출력 또는 특정 값으로 설정
		cout << "무게 중심을 계산할 수 없습니다." << endl;
		dCenterX = -1.0;
		dCenterY = -1.0;
	}
	

	cout << dCenterX << "\t" << dCenterY << endl;

	
}
int radius = rand() % 150 + 50; // 최소 반지름 50, 최대 반지름 200




void CMFCHWGRIMDlg::OnBnClickedMakeCircle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 랜덤 크기 및 위치 계산
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);
	int x = rand() % nWidth;
	int y = rand() % nHeight;
	// 랜덤 크기의 원 생성
	if (x > 450) {
		x = 450;
	}

	// y의 최대값 설정
	if (y > 350) {
		y = 350;
	}
	

	CRect rect(x - radius, y - radius, x + radius, y + radius);

	// 원을 그리는 for 루프
	for (int j = rect.top; j < rect.bottom; j++) {
		for (int k = rect.left; k < rect.right; k++) {
			if ((j - y) * (j - y) + (k - x) * (k - x) <= radius * radius) {
				if (j < 0 || j >= nHeight || k < 0 || k >= nWidth) {
					// 배열 범위 벗어남 처리
					continue;
				}
				fm[j * nPitch + k] = 255;
			}


			m_pDlgImage->Invalidate();
		}


	}
}

void CMFCHWGRIMDlg::OnBnClickedGetdata2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();


	int nThreshold = 0;

	// 원의 중심 좌표
	int x = rand() % nWidth;
	int y = rand() % nHeight;
	// 랜덤 크기의 원 생성
	if (x > 450) {
		x = 450;
	}

	// y의 최대값 설정
	if (y > 350) {
		y = 350;
	}
	
	CRect rect(x - radius, y - radius, x + radius, y + radius);
	// 픽셀 개수
	int nCount = 0;
	int nSumOfX = 0;
	int nSumOfY = 0;

	for (int j = rect.top; j < rect.bottom; j++) {
		for (int i = rect.left; i < rect.right; i++) {
			// 임계값보다 높은 픽셀만 처리
			if (fm[j * nPitch + i] > nThreshold) {
				// 픽셀 좌표를 무게 중심 계산에 반영
				nSumOfX += i;
				nSumOfY += j;
				nCount++;
			}
		}
	}

	// 무게 중심 계산
	double dCenterOfMassX = 0.0;
	double dCenterOfMassY = 0.0;

	// 픽셀 개수가 0이 아닌 경우 무게 중심 계산
	if (nCount >= 0) {
		dCenterOfMassX = (double)nSumOfX/nCount;
		dCenterOfMassY = (double)nSumOfY/nCount;
	}
	else {
		// 무게 중심을 계산할 수 없는 경우 처리
		// 예: 메시지 출력 또는 특정 값으로 설정
		cout << "무게 중심을 계산할 수 없습니다." << endl;
		dCenterOfMassX = -1.0;
		dCenterOfMassY = -1.0;
	}

	// 결과 출력
	cout << dCenterOfMassX << "\t" << dCenterOfMassY << endl;
}

