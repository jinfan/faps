// MyTabTwo.cpp : implementation file
//

#include "stdafx.h"
#include "MyTabTwo.h"
#include "afxdialogex.h"
#include "OpenGLControl.h"
//#include "Tdsloader"

//hh
// MyTabTwo dialog

IMPLEMENT_DYNAMIC(MyTabTwo, CDialog)

MyTabTwo::MyTabTwo(CWnd* pParent /*=NULL*/)
	: CDialog(MyTabTwo::IDD, pParent)
{

}

MyTabTwo::~MyTabTwo()
{
}

void MyTabTwo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyTabTwo, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &MyTabTwo::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &MyTabTwo::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON2, &MyTabTwo::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyTabTwo::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &MyTabTwo::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &MyTabTwo::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &MyTabTwo::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyTabTwo::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &MyTabTwo::OnBnClickedButton7)
	ON_EN_CHANGE(IDC_EDIT2, &MyTabTwo::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON9, &MyTabTwo::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &MyTabTwo::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_LoadTexture, &MyTabTwo::OnBnClickedLoadtexture)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_AgeProgress, &MyTabTwo::OnNMCustomdrawAgeprogress)
	ON_EN_CHANGE(IDC_EDIT3, &MyTabTwo::OnEnChangeEdit3)
	//ON_EN_CHANGE(IDC_EDIT1, &MyTabTwo::OnEnChangeEdit1)
END_MESSAGE_MAP()


// MyTabTwo message handlers


void MyTabTwo::OnBnClickedRadio1()
{
	//MessageBox("Points");
	//modify();
	//display(c);
	//COpenGLControl::m_type=GL_POINTS;
changeMode(GL_POINTS);
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedRadio2()
{
	//COpenGLControl::m_type=GL_TRIANGLES;
changeMode(GL_TRIANGLES);

	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton2()
{
	
	CString s;
	GetDlgItemText(IDC_EDIT1, s);
	float x = atof( s );
	modify(x);
		
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton3()
{
	reset();// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton1()
{
	move('l');
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton6()
{
	move('r');
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton4()
{
	move('u');// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton5()
{
	move('d');
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton7()
{
	scaleTex();
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnEnChangeEdit2()
{
	CString s;
	GetDlgItemText(IDC_EDIT1, s);
	int x = atoi( s );
	markVertex(x);
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton9()
{
makeLine();
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedButton10()
{
	test();
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnBnClickedLoadtexture()
{
	this->DragAcceptFiles(true);
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL,
	OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,
	_T("image files (*.bmp; *.jpg) |*.bmp;*.jpg|All Files (*.*)|*.*||"),NULL);
 
	dlg.m_ofn.lpstrTitle= _T("Open Image");
 
	if (dlg.DoModal() == IDOK) {
 
		CString path= dlg.GetPathName();
		//setTexture(path);
		LoadImage2(path,255,0,1);
		//display();
	}
	// TODO: Add your control notification handler code here
}


void MyTabTwo::OnNMCustomdrawAgeprogress(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void MyTabTwo::OnEnChangeEdit3()
{

	CString s;
	GetDlgItemText(IDC_EDIT3, s);
	float x = atof( s );
	changeContrast(x);
	
}


