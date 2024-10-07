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
	// ��������, �� �������� �� �������� ����
	if (EditOrgName->Text.Trim().IsEmpty() || MemoDescription->Lines->Text.Trim().IsEmpty())
    {
        ShowMessage("���� �����, �������� �� ����.");
		return;
    }

    try
    {
        if (!DataModule1->FDConnection1->Connected)
        {
            DataModule1->ConnectToDatabase();
			if (!DataModule1->FDConnection1->Connected)
			{
				throw Exception("�� ������� ����������� �� ���� �����.");
			}
		}

		// ��������� ���������� �� ���� �����
		std::unique_ptr<TFDQuery> insertOrganizationQuery(new TFDQuery(NULL));
		insertOrganizationQuery->Connection = DataModule1->FDConnection1;
		insertOrganizationQuery->SQL->Text = "INSERT INTO Organizations (name, description) VALUES (:name, :description)";
		insertOrganizationQuery->ParamByName("name")->AsString = EditOrgName->Text;  // ����� ����������
		insertOrganizationQuery->ParamByName("description")->AsString = MemoDescription->Lines->Text;  // ���� ����������
		insertOrganizationQuery->ExecSQL();

		ShowMessage("���������� ������ ������!");

		// �������� ���� ���� ���������
		EditOrgName->Clear();
		MemoDescription->Clear();
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ��������� ����������: " + e.Message);
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
