//---------------------------------------------------------------------------


#pragma hdrstop

#include "dmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
#include "System.hpp"
TdtmMain *dtmMain;
//---------------------------------------------------------------------------
__fastcall TdtmMain::TdtmMain(TComponent* Owner)
	: TDataModule(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TdtmMain::PrepareConnectionString(WideString ADBName
  , WideString AServerName, WideString AUserName, WideString APassword)
{
	WideString lResult = ConnectionStr;

	lResult = StringReplace(lResult, "PPPPPPPP", Password
	  , TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);

	lResult = StringReplace(lResult, "UUUUUUUU", UserName
	  , TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);

	lResult = StringReplace(lResult, "BBBBBBBB", DBName
	  , TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);

	lResult = StringReplace(lResult, "SSSSSSSS", ServerName
	  , TReplaceFlags()<< rfReplaceAll << rfIgnoreCase);
	connMain->ConnectionString = lResult;
}
//---------------------------------------------------------------------------
void __fastcall TdtmMain::LoadParams()
{
  ServerName = Ini->ReadString("CONNECTION","ServerName", "");
  DBName = Ini->ReadString("CONNECTION","DBName", "");
  UserName = Ini->ReadString("CONNECTION","UserName", "");
  Password = Ini->ReadString("CONNECTION","Password", "");
  PrepareConnectionString(DBName, ServerName, UserName, Password);
  connMain->Open();
}
//---------------------------------------------------------------------------

void __fastcall TdtmMain::DataModuleDestroy(TObject *Sender)
{
    Ini->Free();
}
//---------------------------------------------------------------------------

void __fastcall TdtmMain::DataModuleCreate(TObject *Sender)
{
	ConnectionStr = "Provider=SQLOLEDB.1;Password=PPPPPPPP;"
	  +String("Persist Security Info=True;User ID=UUUUUUUU;Initial Catalog=BBBBBBBB;")
	  +String("Data Source=SSSSSSSS;Use Procedure for Prepare=1;Auto Translate=True;")
	  +String("Packet Size=4096;Workstation ID=myPC;Use Encryption for Data=False;");
	String lPathToIniFile =	ParamStr(0);
	Ini = new TIniFile(ChangeFileExt(lPathToIniFile, ".ini"));
}
//---------------------------------------------------------------------------


