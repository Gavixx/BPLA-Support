//---------------------------------------------------------------------------

#ifndef ProfileFormH
#define ProfileFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelUsername;
	TEdit *EditUserName;
	TButton *ButtonEditName;
	TButton *ButtonSaveName;
	TLabel *Label1;
	TEdit *EditEmail;
	TButton *ButtonEditEmail;
	TButton *ButtonSaveEmail;
	TLabel *Label2;
	TEdit *EditPhone;
	TButton *ButtonPhoneNumber;
	TButton *ButtonSavePhoneNumber;
	TLabel *Label3;
	TEdit *EditLogin;
	TButton *ButtonEditLogin;
	TButton *ButtonSaveLogin;
	TLabel *Label4;
	TEdit *EditPassword;
	TButton *ButtonExit;
	TButton *ButtonSavePassword;
	TButton *ButtonEditPassword;
	TMainMenu *MainMenu1;
	TMenuItem *Close1;
	TMemo *MemoHistory;
	void __fastcall ButtonEditNameClick(TObject *Sender);
	void __fastcall ButtonEditEmailClick(TObject *Sender);
	void __fastcall ButtonPhoneNumberClick(TObject *Sender);
	void __fastcall ButtonEditLoginClick(TObject *Sender);
	void __fastcall ButtonEditPasswordClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonSaveNameClick(TObject *Sender);
	void __fastcall ButtonSaveEmailClick(TObject *Sender);
	void __fastcall ButtonSavePhoneNumberClick(TObject *Sender);
	void __fastcall ButtonSaveLoginClick(TObject *Sender);
	void __fastcall ButtonSavePasswordClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
private:	// User declarations
	int UserID;
	void __fastcall LoadData();
    void __fastcall LoadHistory();
public:		// User declarations
	__fastcall TForm8(TComponent* Owner, int userID);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
