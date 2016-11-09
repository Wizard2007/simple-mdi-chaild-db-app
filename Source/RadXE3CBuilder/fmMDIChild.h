//---------------------------------------------------------------------------

#ifndef fmMDIChildH
#define fmMDIChildH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ToolWin.hpp>
#include "IniFiles.hpp"
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfrmMDIChild : public TForm
{
__published:	// IDE-managed Components
	TDataSource *dsrMaster;
	TDataSource *dsrDetail;
	TActionList *alMain;
	TImageList *ilMain;
	TToolBar *ToolBar1;
	TToolBar *ToolBar2;
	TDBGrid *grdMaster;
	TDBGrid *grdDetail;
	TToolButton *btnAddMaster;
	TToolButton *btnAddDetail;
	TAction *aAddMaster;
	TAction *aDeleteMaster;
	TAction *aSaveMaster;
	TAction *aRefreshMaster;
	TAction *aAddDetail;
	TAction *aDeleteDetail;
	TAction *aSaveDetail;
	TAction *aRefreshDetail;
	TToolButton *btnDeleteMaster;
	TToolButton *btnSaveMaster;
	TToolButton *btnRefreshMaster;
	TToolButton *btnDeleteDetail;
	TToolButton *btnSaveDetail;
	TToolButton *btnRefreshDetail;
	TADODataSet *dsMaster;
	TADODataSet *dsDetail;
	TAutoIncField *dsMasterIdMaster;
	TStringField *dsMasterMasterName;
	TDateTimeField *dsMasterCreateDate;
	TStringField *dsDetailDetailName;
	TDateTimeField *dsDetailCreateDate;
	TAutoIncField *dsDetailIdDetail;
	TIntegerField *dsDetailIdMaster;
	TLabel *lblDetailId;
	TLabel *lblMasterId;
	TPanel *pnlDetail;
	TPanel *pnlMaster;
	TDBEdit *edtMasterName;
	TDBEdit *edtMasterCreateDate;
	TLabel *lblMasterCreateDate;
	TLabel *lblMasterName;
	TLabel *lblDetailName;
	TDBEdit *edtDetailName;
	TLabel *lblDetailCreateDate;
	TDBEdit *edtDetailCreateDate;
	TMainMenu *MainMenu1;
	TMenuItem *r1;
	TMenuItem *r2;
	TMenuItem *r3;
	TMenuItem *r4;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall aAddDetailExecute(TObject *Sender);
	void __fastcall aDeleteDetailExecute(TObject *Sender);
	void __fastcall aSaveMasterExecute(TObject *Sender);
	void __fastcall aAddMasterExecute(TObject *Sender);
	void __fastcall aDeleteMasterExecute(TObject *Sender);
	void __fastcall aRefreshMasterExecute(TObject *Sender);
	void __fastcall aSaveDetailExecute(TObject *Sender);
	void __fastcall aRefreshDetailExecute(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall dsMasterAfterInsert(TDataSet *DataSet);
	void __fastcall dsDetailAfterInsert(TDataSet *DataSet);
	void __fastcall RefreshAllDataSet();
	void __fastcall aSaveMasterUpdate(TObject *Sender);
	void __fastcall aSaveDetailUpdate(TObject *Sender);
	void __fastcall aDeleteDetailUpdate(TObject *Sender);
	void __fastcall aDeleteMasterUpdate(TObject *Sender);
	void __fastcall aAddDetailUpdate(TObject *Sender);
	void __fastcall SaveGridColumnsWidthInToFile(TDBGrid *AGrid);
	void __fastcall LoadGridColumnsWidthInToFile(TDBGrid *AGrid);
	void __fastcall dsMasterAfterPost(TDataSet *DataSet);
	void __fastcall dsMasterNewRecord(TDataSet *DataSet);
	void __fastcall dsDetailAfterPost(TDataSet *DataSet);
	void __fastcall dsDetailNewRecord(TDataSet *DataSet);

private:	// User declarations

public:		// User declarations
	__fastcall TfrmMDIChild(TComponent* Owner);
	TIniFile *Ini;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMDIChild *frmMDIChild;
//---------------------------------------------------------------------------
#endif
