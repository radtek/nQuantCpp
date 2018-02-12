// nQuantDlg.h : header file
//

#pragma once
#include <memory>
using namespace std;
#include "afxwin.h"
#include "../nQuantCpp/Dl3Quantizer.h"
#include "../nQuantCpp/PnnQuantizer.h"
#include "../nQuantCpp/NeuQuantizer.h"
#include "../nQuantCpp/WuQuantizer.h"

// CQuantDlg dialog
class CQuantDlg : public CDialogEx
{
// Construction
public:
	CQuantDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NQUANTCPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	LPCTSTR GetInitialDir();
	CString GetFileType();
	Bitmap* Load(LPCTSTR pszPathName);
	Bitmap* ConvertTo(Bitmap* pSource, PixelFormat format);

// Implementation
protected:
	HICON m_hIcon;
	TCHAR szInitDir[MAX_PATH];
	CString m_FileTypes;
	unique_ptr<Bitmap> m_pImage;
	unique_ptr<Bitmap> m_pImage256Color;

	Dl3Quant::Dl3Quantizer dl3Quantizer;
	PnnQuant::PnnQuantizer pnnQuantizer;
	NeuralNet::NeuQuantizer neuQuantizer;
	nQuant::WuQuantizer wuQuantizer;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFileOpen();
	afx_msg void OnBnClickedRetry();	
	
};