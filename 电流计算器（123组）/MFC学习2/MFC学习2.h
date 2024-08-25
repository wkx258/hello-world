
// MFC学习2.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CMFC学习2App:
// 有关此类的实现，请参阅 MFC学习2.cpp
//

class CMFC学习2App : public CWinApp
{
public:
	CMFC学习2App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFC学习2App theApp;
