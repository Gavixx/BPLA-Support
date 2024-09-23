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
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TButton *ButtonShowStat;
	TFDQuery *FDQuery1;
	TFDPhysMySQLDriverLink *FDPhysMySQLDriverLink1;
	TFDConnection *FDConnection1;
	TDataSource *DataSource1;
	TButton *ButtonAddOrder;
	TButton *Button1;
	TComboBox *ComboBoxDroneName;
	TComboBox *ComboBoxDroneType;
	TComboBox *ComboBoxStatus;
	TDateTimePicker *DateTimePickerStart;
	TDateTimePicker *DateTimePickerEnd;
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall ButtonAddOrderClick(TObject *Sender);
	void __fastcall ButtonShowStatClick(TObject *Sender);

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
