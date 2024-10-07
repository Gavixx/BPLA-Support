//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddOrg.h"
#include "DataModule.h"
#include "AdminForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::ButtonAddClick(TObject *Sender)
{
	// Перевірка, чи заповнені всі необхідні поля
	if (EditOrgName->Text.Trim().IsEmpty() || MemoDescription->Lines->Text.Trim().IsEmpty())
    {
        ShowMessage("Будь ласка, заповніть всі поля.");
		return;
    }

    try
    {
        if (!DataModule1->FDConnection1->Connected)
        {
            DataModule1->ConnectToDatabase();
			if (!DataModule1->FDConnection1->Connected)
			{
				throw Exception("Не вдалося підключитися до бази даних.");
			}
		}

		// Додавання організації до бази даних
		std::unique_ptr<TFDQuery> insertOrganizationQuery(new TFDQuery(NULL));
		insertOrganizationQuery->Connection = DataModule1->FDConnection1;
		insertOrganizationQuery->SQL->Text = "INSERT INTO Organizations (name, description) VALUES (:name, :description)";
		insertOrganizationQuery->ParamByName("name")->AsString = EditOrgName->Text;  // Назва організації
		insertOrganizationQuery->ParamByName("description")->AsString = MemoDescription->Lines->Text;  // Опис організації
		insertOrganizationQuery->ExecSQL();

		ShowMessage("Організацію успішно додано!");

		// Очищення полів після додавання
		EditOrgName->Clear();
		MemoDescription->Clear();
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка під час додавання організації: " + e.Message);
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm9::ButtonCancelClick(TObject *Sender)
{
	TForm2 *AdminForm = dynamic_cast<TForm2*>(Owner);
	AdminForm->Show();
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::FormClose(TObject *Sender, TCloseAction &Action)
{
	TForm2 *AdminForm = dynamic_cast<TForm2*>(Owner);
	if (AdminForm)
	{
		AdminForm->Show();
	}
}
//---------------------------------------------------------------------------
