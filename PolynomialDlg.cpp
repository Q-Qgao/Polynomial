
// PolynomialDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Polynomial.h"
#include "PolynomialDlg.h"
#include "afxdialogex.h"
#include"PolynomialClass.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPolynomialDlg 对话框



CPolynomialDlg::CPolynomialDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POLYNOMIAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPolynomialDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_mEDIT, mEdit);
	DDX_Control(pDX, IDC_nEDIT, n_Edit);
	DDX_Control(pDX, IDC_COMBO1, combox);
}

BEGIN_MESSAGE_MAP(CPolynomialDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CPolynomialDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPolynomialDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_mEDIT, &CPolynomialDlg::OnEnChangemedit)
	ON_BN_CLICKED(IDC_BUTTON33, &CPolynomialDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON4, &CPolynomialDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPolynomialDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPolynomialDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CPolynomialDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CPolynomialDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CPolynomialDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CPolynomialDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTONpoint, &CPolynomialDlg::OnBnClickedButtonpoint)
	ON_BN_CLICKED(IDC_BUTTON_back, &CPolynomialDlg::OnBnClickedButtonback)
	ON_BN_CLICKED(IDC_BUTTONclear, &CPolynomialDlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTONenter, &CPolynomialDlg::OnBnClickedButtonenter)
	ON_BN_CLICKED(IDC_BUTTONchange, &CPolynomialDlg::OnBnClickedButtonchange)
	ON_BN_CLICKED(IDC_BUTTONnext, &CPolynomialDlg::OnBnClickedButtonnext)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CPolynomialDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CPolynomialDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPolynomialDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CPolynomialDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPolynomialDlg 消息处理程序

BOOL CPolynomialDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString str;
	combox.ResetContent();

	str= "加法";
	combox.AddString(str);
	str = "减法";
	combox.AddString(str);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPolynomialDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPolynomialDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPolynomialDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPolynomialDlg::OnBnClickedButton2()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("2");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton1()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("1");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnEnChangemedit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton33()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("3");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton4()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("4");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton5()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("5");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton6()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("6");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton7()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("7");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton8()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("8");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}

//一个计算器按钮示范
void CPolynomialDlg::OnBnClickedButton9()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("9");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButton0()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("0");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButtonpoint()
{
	CString str;
	mEdit.GetWindowTextW(str);
	if (str != "")
	{
		if (str.GetAt(str.GetAllocLength() - 1) >= '0'&&str.GetAt(str.GetAllocLength() - 1) <= '9')
		{
			str = str + _T(".");
			mEdit.SetWindowTextW(str);
		}
		else AfxMessageBox(_T("输入违法！"));
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButtonback()
{
	CString str;
	mEdit.GetWindowTextW(str);
	str = str.Left(str.GetLength() - 1);
	mEdit.SetWindowTextW(str);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButtonclear()
{
	mEdit.SetWindowTextW(_T(""));
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButtonenter()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T(" ");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码

}


void CPolynomialDlg::OnBnClickedButtonchange()
{
	UpdateData(true);
	CString str;
	mEdit.GetWindowTextW(str);
	str = str + _T("-");
	mEdit.SetWindowTextW(str);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnBnClickedButtonnext()
{
	CString str;
	CString temp, temp1, temp2, temp3;
	mEdit.GetWindowTextW(str);
	double c = 0; int e = 0;
	int j;	int i;
	//Term* rear;
	//if (flag) rear = y.getHead();
//	else rear = x.getHead();
	for (j = 0; j < str.GetLength(); j++)
	{
		temp = temp1 = temp2 = temp3 = "";
		if (str[j] == ' ')continue;
		c = 0; e = 0;
		while (str[j] != ' '&&j < str.GetLength()) { temp += str[j]; j++; }
		for (i = 0; i < temp.GetLength(); i++)
		{
			if (temp[i] != '.')temp1 += temp[i];
			else break;
		}
		c += _ttof(temp1);//CString转double
		i++;
		for (i; i < temp.GetLength(); i++)
			temp2 += temp[i];
		if(c<0)
		c -= _ttof(temp2) / pow(10, temp2.GetLength());
		else c += _ttof(temp2) / pow(10, temp2.GetLength());
		 while(str[j]==' ')j++;
		while (str[j] != ' '&&j < str.GetLength()) { temp3 += str[j]; j++; }
		e = _ttoi(temp3);
		//输入，尾插法建立多项式
	//	if (flag)
	//rear = rear->InsertAfter(c, e);
		if (!flag)x.inser_order(c, e);
		else y.inser_order(c, e);
		//	rear->InsertAfter(c, e, y.first);
	//	else rear = rear->InsertAfter(c, e,x.first);
		//  else rear->InsertAfter(c, e, x.first);
	}
	if(!flag)
	AfxMessageBox(_T("第一个表达式建立完毕！"));
	else AfxMessageBox(_T("第二个表达式建立完毕！"));
	mEdit.SetWindowTextW(_T(""));
	flag = !flag;
	// TODO: 在此添加控件通知处理程序代码
}


void CPolynomialDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CPolynomialDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CString temp;
	int index = combox.GetCurSel();
	//combox.GetLBText(index, temp);
	CString str;
	
		Polynomial C;
		if (index == 0)
		C = x + y;
		else 
			C = x-y;
		Term*current = C.getHead()->link;//头指针为空，不输出
	//	cout << "多项式:" << endl;
		bool h = true;
		while (current != NULL)
		{
			if (h == false && current->coef > 0)str+='+';
			h = false;
			//str+= *current;
			if (current->coef == 0.0)
				continue;
			CString strr, str0;
			if (current->coef == 1.0&&current->exp!=0);
			else
			{
				
				strr.Format(_T("%3f"), current->coef);
				int len = strr.GetLength();
				int i;
				for (i = len - 1; i >= 0; i--)
				{
					if (strr[i] == '0' || strr[i] == '.');
					else break;
				}
				for (int j = 0; j <= i; j++)
					str += strr[j];
			}
			switch (current->exp)
			{
			case 0:break;
			case 1:str+="X"; break;
			default: {str += "X"; strr.Format(_T("%d"), current->exp); str += strr; }
				break;
			}
			current = current->link;
		}
		n_Edit.SetWindowTextW(str);
		
	
}



void CPolynomialDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	// CDialogEx::OnCancel();
	n_Edit.SetWindowTextW(_T(""));
	  x.first = new Term(0, -1);
	  y.first = new Term(0, -1);
}


void CPolynomialDlg::OnBnClickedButton3()
{
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}
