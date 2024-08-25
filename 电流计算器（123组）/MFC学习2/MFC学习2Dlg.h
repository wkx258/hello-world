﻿
// MFC学习2Dlg.h: 头文件
//

#pragma once
#include "cwin1.h"
#include "cwin2.h"

// CMFC学习2Dlg 对话框
class CMFC学习2Dlg : public CDialogEx
{
// 构造
public:
	CMFC学习2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

private:
	cwin1 cw1;
	cwin2 cw2;

public:
	afx_msg void OnBnClickedButton2();
};
