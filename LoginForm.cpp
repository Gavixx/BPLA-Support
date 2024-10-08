//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "AdminForm.h"
#include "LoginForm.h"
#include "ArmyForm.h"
#include "VolonterForm.h"
#include "DataModule.h"
#include "CryptoUtils.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoginButtonClick(TObject *Sender)
{
    String enteredUsername = EditLogin->Text;
    String enteredPassword = EditPassword->Text;

    if (enteredUsername.IsEmpty() || enteredPassword.IsEmpty()) {
        ShowMessage("���� �����, ������ �� ����, ��� � ������");
        return;
    }

    try {
        DataModule1->ConnectToDatabase();  // ϳ���������� �� ���� ����� ����� DataModule

        // SQL-����� ��� ������ ���, ������ �� ���� ����������� �� ������
        DataModule1->FDQuery1->SQL->Text =
            "SELECT U.user_id, U.role, U.name, C.password FROM Users U "
            "INNER JOIN UserCredentials C ON U.user_id = C.user_id "
            "WHERE C.login = :login";
        DataModule1->FDQuery1->ParamByName("login")->AsString = enteredUsername;
        DataModule1->FDQuery1->Open();

        // ����������, �� �������� �����������
        if (!DataModule1->FDQuery1->Eof) {
            // �������� ��� � ����
            String storedPasswordHash = DataModule1->FDQuery1->FieldByName("password")->AsString;
            String userRole = DataModule1->FDQuery1->FieldByName("role")->AsString;
            String userName = DataModule1->FDQuery1->FieldByName("name")->AsString;  // �������� ��'� �����������
            int user_id = DataModule1->FDQuery1->FieldByName("user_id")->AsInteger;

            // ����������� ��������� ������ �� std::string
            std::string password = UTF8String(enteredPassword).c_str();

			// ��������� ��������� ������
            std::string hashedPassword = CryptoUtils::HashPassword(password);

            // ����������, �� ��������� ���� ������
            if (hashedPassword == std::string(UTF8String(storedPasswordHash).c_str())) {
                OpenRoleSpecificForm(userRole, userName, user_id);  // �������� ����, ��'� ����������� �� ID
                this->Hide();  // ������ ����� ����� ���� �������� ���� �����
            } else {
                ShowMessage("������� ���� ��� ������");
            }
        } else {
            ShowMessage("������� ���� ��� ������");
        }

        // ��������� ����� � ��������� �'�������
        DataModule1->FDQuery1->Close();
        DataModule1->FDConnection1->Connected = false;
    }
    catch (Exception &e) {
        ShowMessage("�������: " + e.Message);
        DataModule1->FDConnection1->Connected = false;  // ������������, �� ���������� �������� � ��� �������
    }
}


//---------------------------------------------------------------------------
void TForm1::OpenRoleSpecificForm(String role, String userName, int user_id)
{
	if (role == "admin") {
		TForm2 *AdminForm = new TForm2(this);
		AdminForm->Show();
	}
	else if (role == "military") {
		TForm3 *ArmyForm = new TForm3(this);
		ArmyForm->Show();
	}
	else if (role == "volunteer") {
		TForm4 *VolonterForm = new TForm4(this, userName, user_id);  // �������� ��'� �����������s
		VolonterForm->Show();
	}
	else {
		ShowMessage("Unknown role: " + role);
	}
}

//---------------------------------------------------------------------------


