//---------------------------------------------------------------------------

#ifndef AddOrgH
#define AddOrgH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditOrgName;
	TLabel *Label2;
	TMemo *MemoDescription;
	TButton *ButtonAdd;
	TMainMenu *MainMenu1;
	TMenuItem *Close1;
	TButton *ButtonCancel;
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
