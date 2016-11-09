//---------------------------------------------------------------------------

#ifndef dmMainH
#define dmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
class TdtmMain : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *connMain;
	void __fastcall DataModuleDestroy(TObject *Sender);
	void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	TIniFile *Ini;
	WideString ConnectionStr;
	WideString DBName;
	WideString ServerName;
	WideString UserName;
	WideString Password;
	void __fastcall LoadParams();
	void __fastcall PrepareConnectionString(WideString ADBName, WideString AServerName
	  , WideString AUserName, WideString APassword);
	__fastcall TdtmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdtmMain *dtmMain;
//---------------------------------------------------------------------------
#endif
