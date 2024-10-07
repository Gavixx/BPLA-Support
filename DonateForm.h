//---------------------------------------------------------------------------

#ifndef DonateFormH
#define DonateFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *CLose1;
	TMenuItem *CLose2;
	TMenuItem *Help1;
	TMenuItem *Help2;
	TEdit *EditQuantity;
	TButton *ButtonSend;
	TLabel *LabelMaxQuantity;
	TLabel *LabelDroneName;
	TLabel *Label1;
	TButton *ButtonCancel;
	void __fastcall ButtonSendClick(TObject *Sender);
	void __fastcall EditQuantityKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ButtonCancelClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
//	void __fastcall ComboBoxDronesChange(TObject *Sender);
private:	// User declarations
//	void __fastcall UpdateMaxQuantityNeeded();
	int SelectedRequestID;
    String SelectedDroneName;
	int MaxQuantityNeeded;
    int UserID;

public:		// User declarations
	__fastcall TForm7(TComponent* Owner, int requestID, String droneName, int maxQuantity, int userID);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
