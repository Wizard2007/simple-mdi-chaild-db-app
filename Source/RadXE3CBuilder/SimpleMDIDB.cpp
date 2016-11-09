//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include "dmMain.h"

//---------------------------------------------------------------------------
USEFORM("dmMain.cpp", dtmMain); /* TDataModule: File Type */
USEFORM("fmMain.cpp", frmMain);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TdtmMain), &dtmMain);
		dtmMain->LoadParams();
		if (dtmMain->connMain->Connected) {
			Application->CreateForm(__classid(TfrmMain), &frmMain);
			Application->Run();
		}
		else {
			ShowMessage("Can not connect to datadase!");
			Application->Terminate();
		}
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
