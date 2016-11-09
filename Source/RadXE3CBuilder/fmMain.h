//---------------------------------------------------------------------------

#ifndef fmMainH
#define fmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mmMain;
	TMenuItem *miFile;
	TMenuItem *miExit;
	TMenuItem *miWindow;
	TMenuItem *miOpenNewWindow;
	TActionList *alMain;
	TAction *aExit;
	TAction *aNewWindow;
	TTimer *tReconectScheduler;
	TApplicationEvents *aeHandleDisconnect;
	void __fastcall aExitExecute(TObject *Sender);
	void __fastcall aNewWindowExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall aeHandleDisconnectException(TObject *Sender, Exception *E);
	void __fastcall tReconectSchedulerTimer(TObject *Sender);


private:	// User declarations
	HINSTANCE DLL;
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	void __fastcall SetEnableToMDI(Boolean AEnable);
	void __fastcall RefreshDatasetOnMDI();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
