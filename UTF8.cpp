
// UTF8.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "UTF8.h"
#include "UTF8Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUTF8App

BEGIN_MESSAGE_MAP(CUTF8App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CUTF8App construction

CUTF8App::CUTF8App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	int rc;
	rc = SetThreadUILanguage(1252);
	rc = SetThreadUILanguage(932);
	rc = SetThreadUILanguage(65001);

}


// The one and only CUTF8App object

CUTF8App theApp;

#include <windows.h>
#include <afxwin.h>
#include <string>
#include <windows.h>
#include <afxwin.h>
#include <string>



bool SetProcessCodePage()
{
	int rc;

	LCID lcid = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);
	if (SetThreadLocale(lcid) == 0) {
		DWORD errorCode = GetLastError();
		CString errorMessage;
		errorMessage.Format("SetThreadLocale(%d) Failed to set process locale to English (US). Error code: %d", lcid, errorCode);
		AfxMessageBox(errorMessage);
		return false;
	}

	rc = SetThreadUILanguage(65001);
	system("chcp 65001");
	
	UINT codePage = GetACP();
	if (codePage == 65001) {
		AfxMessageBox(_T("Process code page is set to UTF-8 (CP 65001)"));
		return true;
	}
	else {
		AfxMessageBox(_T("Failed to set process code page to UTF-8 (CP 65001)"));
		return false;
	}
}

BOOL CUTF8App::InitInstance()
{
	CWinApp::InitInstance();
	CoInitialize(NULL);

	SetProcessCodePage();
	InitCommonControls();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CUTF8Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}


	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

