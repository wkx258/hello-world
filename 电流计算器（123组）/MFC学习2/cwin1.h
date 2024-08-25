#pragma once
#include "afxdialogex.h"


// cwin1 对话框

class cwin1 : public CDialogEx
{
	DECLARE_DYNAMIC(cwin1)

public:
	cwin1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~cwin1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_win1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAbort();
	
};
