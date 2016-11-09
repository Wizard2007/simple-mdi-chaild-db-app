//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fmMDIChild.h"
#include <Data.Win.ADODB.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMDIChild *frmMDIChild;

//---------------------------------------------------------------------------
__fastcall TfrmMDIChild::TfrmMDIChild(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmMDIChild::SaveGridColumnsWidthInToFile(TDBGrid *AGrid)
{//
	String lSectionName =  AGrid->Name;
	int i;
	for (i = 0; i < AGrid->Columns->Count ; i++) {
		Ini->WriteInteger(lSectionName,AGrid->Columns->Items[i]->FieldName
			, AGrid->Columns->Items[i]->Width);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMDIChild::LoadGridColumnsWidthInToFile(TDBGrid *AGrid)
{//
	String lSectionName =  AGrid->Name;
	int i;
	for (i = 0; i < AGrid->Columns->Count ; i++) {
		AGrid->Columns->Items[i]->Width = Ini->ReadInteger(lSectionName,AGrid->Columns->Items[i]->FieldName
			, AGrid->Columns->Items[i]->Width);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMDIChild::RefreshAllDataSet()
{
	aRefreshMaster->Execute();
	aRefreshDetail->Execute();
	LoadGridColumnsWidthInToFile(grdMaster);
	LoadGridColumnsWidthInToFile(grdDetail);
}
//---------------------------------------------------------------------------
void __fastcall TfrmMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
	SaveGridColumnsWidthInToFile(grdMaster);
	SaveGridColumnsWidthInToFile(grdDetail);
	Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aAddDetailExecute(TObject *Sender)
{
  dsDetail->Edit();
  dsDetail->Append();
  aAddDetail->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aDeleteDetailExecute(TObject *Sender)
{
  if( MessageBox(NULL, ("Do you want to delete detail '"+
	dsDetailDetailName->AsAnsiString+"'?").c_str()
, "Confirm",  MB_OKCANCEL ) == idOK){
		dsDetail->Delete();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aSaveMasterExecute(TObject *Sender)
{
  dsMaster->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aAddMasterExecute(TObject *Sender)
{
  dsMaster->Insert();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aDeleteMasterExecute(TObject *Sender)
{
  if( MessageBox(NULL, ("Do you want to delete master' "
	+dsMasterMasterName->AsAnsiString+"'?").c_str(), "Confirm",  MB_OKCANCEL ) == idOK){
	dsMaster->Delete();
	;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aRefreshMasterExecute(TObject *Sender)
{
  int idMaster = -1;

  if (dsMaster->Active) {
	  idMaster = dsMasterIdMaster->AsInteger;
  }
  int idDetail = -1;
  if (dsDetail->Active) {
	idDetail = dsDetailIdDetail->AsInteger;
  }
  dsMaster->Close();
  dsMaster->Open();
  TLocateOptions SearchOptions;
  if (!dsMaster->Locate("IdMaster",idMaster, SearchOptions)){
	  dsMaster->First();
  }
  if (dsDetail->Active) {
	  if (!dsDetail->Locate("IdDetail",idDetail , SearchOptions)){
		  dsDetail->First();
	  }
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aSaveDetailExecute(TObject *Sender)
{
  dsDetail->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aRefreshDetailExecute(TObject *Sender)
{
  int idDetail = -1;
  if (dsDetail->Active) {
	idDetail = dsDetailIdDetail->AsInteger;
  }
  dsDetail->Close();
  dsDetail->Open();
  TLocateOptions SearchOptions;
  if (!dsDetail->Locate("IdDetail",idDetail , SearchOptions)){
	  dsDetail->First();
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::FormShow(TObject *Sender)
{
//  dsMaster->Properties->[OleVariant("Update Resync")]->Value = adResyncAutoIncrement + adResyncInserts;
//  dsDetail->Properties[String("Update Resync").c_str()]->Value = adResyncAutoIncrement + adResyncInserts;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMDIChild::dsMasterAfterInsert(TDataSet *DataSet)
{
	lblMasterId->Caption = dsMasterIdMaster->AsString;
/*
  dsMaster->Edit();
  dsMaster->FieldByName("MasterName")->Value = "";
  dsMaster->FieldByName("CreateDate")->Value = Now();
  */
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::dsDetailAfterInsert(TDataSet *DataSet)
{

/*
  dsDetail->Edit();
  dsDetail->FieldByName("IdMaster")->Value = dsMaster->FieldByName("IdMaster")->AsInteger;
  dsDetail->FieldByName("DetailName")->Value = "";
  dsDetail->FieldByName("CreateDate")->Value = Now();
  */
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aSaveMasterUpdate(TObject *Sender)
{
  Boolean lResult = (dsMaster->State == dsEdit) || (dsMaster->State == dsInsert)
  &((edtMasterName->Text != "") & (edtMasterCreateDate->Text != ""));
  if (aSaveMaster->Enabled != lResult){
	aSaveMaster->Enabled = lResult;
  }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMDIChild::aSaveDetailUpdate(TObject *Sender)
{
  Boolean lResult = (dsDetail->State == dsEdit) || (dsDetail->State == dsInsert)
  &((dsDetailDetailName->AsString != "") & (dsDetailCreateDate->AsString != ""));
  if (aSaveDetail->Enabled != lResult) {
	aSaveDetail->Enabled = lResult;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aDeleteDetailUpdate(TObject *Sender)
{
  Boolean lResult = (dsDetail->RecordCount > 0);
  if (aDeleteDetail->Enabled != lResult) {
	aDeleteDetail->Enabled = lResult;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aDeleteMasterUpdate(TObject *Sender)
{
  Boolean lResult = (dsDetail->RecordCount == 0) & (dsMaster->RecordCount > 0);
  if (aDeleteMaster->Enabled != lResult) {
	aDeleteMaster->Enabled = lResult;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::aAddDetailUpdate(TObject *Sender)
{
  Boolean lResult = (dsMaster->RecordCount > 0);
  if (aAddDetail->Enabled != lResult) {
	aAddDetail->Enabled = lResult;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::dsMasterAfterPost(TDataSet *DataSet)
{
	if (dsMasterIdMaster->Tag == 1){
		// лучше использовать инструкцию IDENT_CURRENT
		lblMasterId->Caption = dsMasterIdMaster->AsString;
		dsMasterIdMaster->Tag = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::dsMasterNewRecord(TDataSet *DataSet)
{
	dsMasterIdMaster->Tag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::dsDetailAfterPost(TDataSet *DataSet)
{
	if (dsDetailIdDetail->Tag == 1){
		// лучше использовать инструкцию IDENT_CURRENT
		lblDetailId->Caption = dsDetailIdDetail->AsString;
		dsDetailIdDetail->Tag = 0;
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmMDIChild::dsDetailNewRecord(TDataSet *DataSet)
{
    dsDetailIdDetail->Tag = 1;
}
//---------------------------------------------------------------------------





