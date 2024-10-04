//---------------------------------------------------------------------------

#ifndef VolonterFormH
#define VolonterFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelWelcom;
	TMainMenu *MainMenu1;
	TMenuItem *Close1;
	TMenuItem *Close2;
	TMenuItem *Help1;
	TMenuItem *Help2;
	TMenuItem *ChangeUser1;
	TDBGrid *DBGrid1;
	TLabel *LabelRequests;
	TButton *ButtonShowRequests;
	TButton *ButtonDonate;
	TBalloonHint *BalloonHint1;
	TButton *Button1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonShowRequestsClick(TObject *Sender);
	void __fastcall ButtonDonateClick(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	String __fastcall GetUserName();
	int __fastcall GetUserID();
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	String UserName;
	int UserID;
	int SelectedRequestID;
	int MaxQuantityNeeded;
	String SelectedDroneName;
	void __fastcall LoadDB();
	void __fastcall SetDBGridColumnsStyles();
public:
	// Конструктор форми з передачею імені користувача
	__fastcall TForm4(TComponent* Owner, String userName, int user_id);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
