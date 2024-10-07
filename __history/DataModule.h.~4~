//---------------------------------------------------------------------------

#ifndef DataModuleH
#define DataModuleH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.Menus.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TFDConnection *FDConnection1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDQuery *FDQuery1;
	TActionManager *ActionManager1;
	TDataSource *DataSource1;
	TAction *ActionChangeUser;
	TAction *ActionHelp;
	TAction *ActionAboutUs;
	TAction *ActionClose;
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionHelpExecute(TObject *Sender);
	void __fastcall ActionAboutUsExecute(TObject *Sender);
	void __fastcall ActionChangeUserExecute(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
	void __fastcall ConnectToDatabase();
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
