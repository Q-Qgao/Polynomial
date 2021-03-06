
// PolynomialDlg.h: 头文件
//

#pragma once


// CPolynomialDlg 对话框
class CPolynomialDlg : public CDialogEx
{
// 构造
public:
	CPolynomialDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POLYNOMIAL_DIALOG };
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangemedit();
	CEdit mEdit;
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonpoint();
	afx_msg void OnBnClickedButtonback();
	afx_msg void OnBnClickedButtonclear();
	CEdit n_Edit;
	afx_msg void OnBnClickedButtonenter();
	afx_msg void OnBnClickedButtonchange();
	afx_msg void OnBnClickedButtonnext();
	CComboBox combox;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
};
