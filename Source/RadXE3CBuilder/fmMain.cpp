//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmMain.h"
#include "dmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmMain *frmMain;
//---------------------------------------------------------------------------
void __fastcall TfrmMain::RefreshDatasetOnMDI()
{   // по хорошему это надо реализовать в общей форме что бы обновление могло позиционироваться сразу на нужный курсор
	TADODataSet *adoDataset;

	for(int j = 0; j < MDIChildCount; j++ )
	{
		for (int i = 0; MDIChildren[j]->ComponentCount; i++)
		{
			adoDataset = dynamic_cast<TADODataSet*>(MDIChildren[j]->Components[i]);
			if (adoDataset) {
				if (adoDataset->DataSource != NULL) {
				    // refresh only master datasets
					adoDataset->Close();
					adoDataset->Open();
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::SetEnableToMDI(Boolean AEnable)
{
	for( int i = 0; i < MDIChildCount; i++ )
	{
		MDIChildren[i]->Enabled = AEnable;
	}
}
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	DLL = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::aExitExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::aNewWindowExecute(TObject *Sender)
{
	typedef  void __declspec(dllimport) ShowMDIFormType(TApplication *ParentApp
	  , TdtmMain *AMain);
	ShowMDIFormType *ShowMDIForm;
	if (!DLL) {
		DLL = LoadLibraryA("MDIChild.dll");
	}
	if (DLL) {
		ShowMDIForm = (ShowMDIFormType *)GetProcAddress(DLL,"ShowMDIForm");
		if (ShowMDIForm) {
			ShowMDIForm(Application, dtmMain);
		}
		else
		{
			FreeLibrary(DLL);
		}
	}
	else {
		ShowMessage("Unable load MDIChild.dll !\r\n" +SysErrorMessage(GetLastError()));
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	while (MDIChildCount)
		MDIChildren[0]->Free();
	FreeLibrary(DLL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	 CanClose = ( MessageBox(NULL, L"Do you want to close the application?"
	   , L"Confirm",  MB_OKCANCEL ) == idOK);
}
//---------------------------------------------------------------------------




void __fastcall TfrmMain::aeHandleDisconnectException(TObject *Sender, Exception *E)

{
  if (!tReconectScheduler->Enabled) {
	  try
	  {
		  dtmMain->connMain->Execute("select 1");
	  }
	  catch(const Exception& e)
	  {   //connection lost
		  SetEnableToMDI(false);
		  tReconectScheduler->Enabled = True;
	  }

  }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::tReconectSchedulerTimer(TObject *Sender)
{
   try
   {    // try to restore connection
   		Application->ProcessMessages();
		dtmMain->connMain->Close();
		dtmMain->connMain->Open();
		if (dtmMain->connMain->Connected) {
			tReconectScheduler->Enabled = false;
			SetEnableToMDI(true);
			RefreshDatasetOnMDI();
	   }
   }
   catch(const Exception& e)
   {

   }
}
//---------------------------------------------------------------------------


