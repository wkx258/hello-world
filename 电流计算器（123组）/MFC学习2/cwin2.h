#pragma once
#include "afxdialogex.h"


// cwin2 对话框

class cwin2 : public CDialogEx
{
	DECLARE_DYNAMIC(cwin2)

public:
	cwin2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~cwin2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_win2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAbort();
};
