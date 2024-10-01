//---------------------------------------------------------------------------

#ifndef ArmyFormH
#define ArmyFormH
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
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonShowStat;
	TButton *ButtonAddOrder;
	TComboBox *ComboBoxDroneName;
	TComboBox *ComboBoxDroneType;
	TComboBox *ComboBoxStatus;
	TDateTimePicker *DateTimePickerStart;
	TDateTimePicker *DateTimePickerEnd;
	TButton *ButtonFilter;
	TButton *ButtonClearFilter;
	TLabel *LabelFilter;
	TMainMenu *MainMenu1;
	TMenuItem *MenuClose;
	TMenuItem *MenuHelp;
	TMenuItem *ChangeUser1;
	TMenuItem *Help1;
	TMenuItem *Help2;
	TDBGrid *DBGrid1;
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall ButtonAddOrderClick(TObject *Sender);
	void __fastcall ButtonShowStatClick(TObject *Sender);
	void __fastcall ButtonFilterClick(TObject *Sender);
	void __fastcall ButtonClearFilterClick(TObject *Sender);
private:	// User declarations
	void __fastcall SetDBGridColumnsStyles();
	void __fastcall DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall LoadDB();
    void __fastcall GetItemToFillBox();
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
