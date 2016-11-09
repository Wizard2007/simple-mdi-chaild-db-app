//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you

#pragma hdrstop
#pragma argsused

#include <Vcl.Dialogs.hpp>
#include <Vcl.Forms.hpp>
#include "fmMDIChild.h"
#include "dmMain.h"

TApplication* DllApplication = NULL;

extern "C" void __declspec(dllexport) __stdcall ShowMDIForm(TApplication *ParentApp
  , TdtmMain *AMain);

void __stdcall ShowMDIForm(TApplication *ParentApp, TdtmMain *AMain)
{
	TfrmMDIChild* lChild;
	if (!DllApplication) {
	  DllApplication = Application;
	  Application= ParentApp;
	}
	lChild = new TfrmMDIChild(Application);
	if (AMain->connMain->Connected) {
	  lChild->dsDetail->Connection = AMain->connMain;
	  lChild->dsMaster->Connection = AMain->connMain;
	  lChild->Ini = AMain->Ini;
	  lChild->RefreshAllDataSet();
	  lChild->Show();
	}
}

int WINAPI DllEntryPoint(HINSTANCE hinst
, unsigned long reason, void* lpReserved)
{
	if ((reason == DLL_PROCESS_DETACH)&&(DllApplication)) {
		Application = DllApplication;
	}
	return 1;
}
