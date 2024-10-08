//---------------------------------------------------------------------------

#ifndef AddOrderFormH
#define AddOrderFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
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
#include <Vcl.ComCtrls.hpp>
#include "ArmyForm.h"
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonAdd;
	TLabeledEdit *LabeledEditQuantity;
	TLabeledEdit *LabeledEditDroneName;
	TDateTimePicker *DateTimePickerRequestDate;
	TComboBox *ComboBoxDroneType;
	TLabel *LabelDroneType;
	TMainMenu *MainMenu1;
	TMenuItem *Close1;
	TMenuItem *Reference1;
	TMenuItem *Help1;
	TMenuItem *AboutUs1;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LabeledEditDroneNameChange(TObject *Sender);
	void __fastcall ComboBoxDroneTypeChange(TObject *Sender);
	void __fastcall LabeledEditQuantityChange(TObject *Sender);
	void __fastcall LabeledEditQuantityKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	void __fastcall CheckFields();

    bool __fastcall CharIsDigit(char c);
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
