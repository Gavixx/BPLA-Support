//---------------------------------------------------------------------------

#ifndef AdminFormH
#define AdminFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
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
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.CheckLst.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGridUsers;
	TButton *ButtonShowUsers;
	TButton *ButtonAddUser;
	TButton *ButtonShowRequests;
	TDBGrid *DBGridRequests;
	TLabel *LabelFilter;
	TButton *ButtonFilter;
	TButton *ButtonClearFilter;
	TCheckListBox *CheckListBox1;
	TGroupBox *GroupBox1;
	TComboBox *ComboBox1;
	TLabel *Label1;
	TComboBox *ComboBox2;
	TLabel *Label2;
	TDateTimePicker *DateTimePickerFrom;
	TLabel *LabelFrom;
	TComboBox *ComboBox3;
	TLabel *Label3;
	TDateTimePicker *DateTimePickerTo;
	TLabel *LabelTo;
	TGroupBox *GroupBox2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TDateTimePicker *DateTimePicker1;
	TComboBox *ComboBox6;
	TDateTimePicker *DateTimePicker2;
	void __fastcall ButtonShowUsersClick(TObject *Sender);
	void __fastcall ButtonAddUserClick(TObject *Sender);
	void __fastcall DBGridUsersTitleClick(TColumn *Column);
	void __fastcall ButtonShowRequestsClick(TObject *Sender);

private:	// User declarations
	void __fastcall LoadRequests();
	void __fastcall LoadUsers();
	void __fastcall SetDBGridColumnsStylesUsers();
	void __fastcall SetDBGridColumnsStylesRequests();
	void __fastcall DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
