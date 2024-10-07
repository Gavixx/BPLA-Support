//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddUser.h"
#include "AdminForm.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
	DataModule1->ConnectToDatabase();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ButtonAddUserClick(TObject *Sender)
{

		DataModule1->FDQuery1->SQL->Text = "INSERT INTO Volunteers (name, email, phone) "
							  "VALUES (:name, :email, :phone)";
		DataModule1->FDQuery1->ParamByName("name")->AsString = EditName->Text;
		DataModule1->FDQuery1->ParamByName("email")->AsString = EditMail->Text;
		DataModule1->FDQuery1->ParamByName("phone")->AsString = EditNumber->Text;
		try {
			DataModule1->FDQuery1->ExecSQL();  // Виконати запит
			ShowMessage("Запит успішно додано!");
			TForm2 *AdminForm = new TForm2(this);
			AdminForm->Show();
			this->Close();
		}
		catch (Exception &e) {
			ShowMessage("Помилка при додаванні запиту: " + e.Message);
		}

}
//---------------------------------------------------------------------------
