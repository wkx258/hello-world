// cwin2.cpp: 实现文件
//

#include "pch.h"
#include "MFC学习2.h"
#include "afxdialogex.h"
#include "cwin2.h"


// cwin2 对话框

IMPLEMENT_DYNAMIC(cwin2, CDialogEx)

cwin2::cwin2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_win2, pParent)
{

}

cwin2::~cwin2()
{
}

void cwin2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cwin2, CDialogEx)
	ON_BN_CLICKED(IDABORT, &cwin2::OnBnClickedAbort)
END_MESSAGE_MAP()


// cwin2 消息处理程序


void cwin2::OnBnClickedAbort()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1;
	CString str2;
	CString str3;
	CString str4;
	CString str5;
	CString str6;
	double i = 0;
	double c = 0, d = 0, e = 0, f = 0, r0 = 0;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	double b = _ttof(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	double r1 = _ttof(str2);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str3);
	double r2 = _ttof(str3);
	GetDlgItem(IDC_EDIT4)->GetWindowText(str4);
	double r3 = _ttof(str4);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str5);
	double r4 = _ttof(str5);

	c = r1 * r2 / (r1 + r2 + r3);
	d = r1 * r3 / (r1 + r2 + r3);
	e = r2 * r3 / (r1 + r2 + r3);
	f = (e + r4) * c / (e + r4 + c);
	r0 = d + f;
	i = b / r0;

	if (b > 0 && r1 > 0 && r2 > 0 && r3 > 0 && r4 > 0)
	{
		str6.Format(_T("%.3f"), i);

		GetDlgItem(IDC_EDIT6)->SetWindowText(str6);

	}
	else
	{
		MessageBox(_T("您输入了无法识别的数。"), _T("Information"), MB_OK);
	}
}
