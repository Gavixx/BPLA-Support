//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProfileForm.h"
#include "DataModule.h"
#include "VolonterForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner, int userID)
	: TForm(Owner), UserID(userID)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ButtonEditNameClick(TObject *Sender)
{
	EditUserName->Enabled = true;
	ButtonSaveName->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ButtonEditEmailClick(TObject *Sender)
{
	EditEmail->Enabled = true;
	ButtonSaveEmail->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ButtonPhoneNumberClick(TObject *Sender)
{
	EditPhone->Enabled = true;
	ButtonSavePhoneNumber->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ButtonEditLoginClick(TObject *Sender)
{
	EditLogin->Enabled = true;
	ButtonSaveLogin->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::ButtonEditPasswordClick(TObject *Sender)
{
	EditPassword->Enabled = true;
	ButtonSavePassword->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormCreate(TObject *Sender)
{
	LoadData();
	LoadHistory();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::LoadData(){
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

		std::unique_ptr<TFDQuery> selectProfileQuery(new TFDQuery(NULL));
		selectProfileQuery->Connection = DataModule1->FDConnection1;
		selectProfileQuery->SQL->Text = "SELECT u.name, u.email, u.phone, uc.login, uc.password FROM Users u "
									  "JOIN UserCredentials uc ON u.user_id = uc.user_id WHERE u.user_id = :user_id";
		selectProfileQuery->ParamByName("user_id")->AsInteger = UserID;
		selectProfileQuery->Open();

		if (!selectProfileQuery->Eof)
		{
			EditUserName->Text = selectProfileQuery->FieldByName("name")->AsString;
			EditEmail->Text = selectProfileQuery->FieldByName("email")->AsString;
			EditPhone->Text = selectProfileQuery->FieldByName("phone")->AsString;
			EditLogin->Text = selectProfileQuery->FieldByName("login")->AsString;
			EditPassword->Text = selectProfileQuery->FieldByName("password")->AsString;
		}
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ������������ ����� �������: " + e.Message);
	}

}
void __fastcall TForm8::ButtonSaveNameClick(TObject *Sender)
{
	if (EditUserName->Text.Trim().IsEmpty())
	{
		ShowMessage("���� �� ���� ���������.");
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

		std::unique_ptr<TFDQuery> updateProfileQuery(new TFDQuery(NULL));
		updateProfileQuery->Connection = DataModule1->FDConnection1;
		updateProfileQuery->SQL->Text = "UPDATE Users SET name = :name WHERE user_id = :user_id";
		updateProfileQuery->ParamByName("name")->AsString = EditUserName->Text;
		updateProfileQuery->ParamByName("user_id")->AsInteger = UserID;
		updateProfileQuery->ExecSQL();

		EditUserName->Enabled = false;
		ButtonSaveName->Enabled = false;

		ShowMessage("���� ������ ���������!");
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ���������� ���: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ButtonSaveEmailClick(TObject *Sender)
{
	if (EditEmail->Text.Trim().IsEmpty())
	{
		ShowMessage("���� �� ���� ���������.");
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

		std::unique_ptr<TFDQuery> updateProfileQuery(new TFDQuery(NULL));
		updateProfileQuery->Connection = DataModule1->FDConnection1;
		updateProfileQuery->SQL->Text = "UPDATE Users SET email = :email WHERE user_id = :user_id";
		updateProfileQuery->ParamByName("email")->AsString = EditEmail->Text;
		updateProfileQuery->ParamByName("user_id")->AsInteger = UserID;
		updateProfileQuery->ExecSQL();

		EditEmail->Enabled = false;
		ButtonSaveEmail->Enabled = false;

		ShowMessage("���� ������ ���������!");
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ���������� ���: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ButtonSavePhoneNumberClick(TObject *Sender)
{
	if (EditPhone->Text.Trim().IsEmpty())
	{
		ShowMessage("���� �� ���� ���������.");
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

		std::unique_ptr<TFDQuery> updateProfileQuery(new TFDQuery(NULL));
		updateProfileQuery->Connection = DataModule1->FDConnection1;
		updateProfileQuery->SQL->Text = "UPDATE Users SET phone = :phone WHERE user_id = :user_id";
		updateProfileQuery->ParamByName("phone")->AsString = EditPhone->Text;
		updateProfileQuery->ParamByName("user_id")->AsInteger = UserID;
		updateProfileQuery->ExecSQL();

		EditPhone->Enabled = false;
		ButtonSavePhoneNumber->Enabled = false;

		ShowMessage("���� ������ ���������!");
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ���������� ���: " + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ButtonSaveLoginClick(TObject *Sender)
{
	if (EditLogin->Text.Trim().IsEmpty())
		{
			ShowMessage("���� �� ���� ���������.");
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

			std::unique_ptr<TFDQuery> updateProfileQuery(new TFDQuery(NULL));
			updateProfileQuery->Connection = DataModule1->FDConnection1;
			updateProfileQuery->SQL->Text = "UPDATE UserCredentials SET login = :login WHERE user_id = :user_id";
			updateProfileQuery->ParamByName("login")->AsString = EditLogin->Text;
			updateProfileQuery->ParamByName("user_id")->AsInteger = UserID;
			updateProfileQuery->ExecSQL();

			EditLogin->Enabled = false;
			ButtonSaveLogin->Enabled = false;

			ShowMessage("���� ������ ���������!");
		}
		catch (Exception &e)
		{
			ShowMessage("������� �� ��� ���������� ���: " + e.Message);
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ButtonSavePasswordClick(TObject *Sender)
{
	if (EditPassword->Text.Trim().IsEmpty())
		{
			ShowMessage("���� �� ���� ���������.");
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

			std::unique_ptr<TFDQuery> updateProfileQuery(new TFDQuery(NULL));
			updateProfileQuery->Connection = DataModule1->FDConnection1;
			updateProfileQuery->SQL->Text = "UPDATE UserCredentials SET password = :password WHERE user_id = :user_id";
			updateProfileQuery->ParamByName("password")->AsString = EditPassword->Text;
			updateProfileQuery->ParamByName("user_id")->AsInteger = UserID;
			updateProfileQuery->ExecSQL();

			EditPassword->Enabled = false;
			ButtonSavePassword->Enabled = false;

			ShowMessage("���� ������ ���������!");
		}
		catch (Exception &e)
		{
			ShowMessage("������� �� ��� ���������� ���: " + e.Message);
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ButtonExitClick(TObject *Sender)
{
    TForm4 *VolonterForm = dynamic_cast<TForm4*>(Owner);
	if (VolonterForm)
	{
		VolonterForm->Show();
	}
	this->Close();
}
//---------------------------------------------------------------------------
 void __fastcall TForm8::LoadHistory(){
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

		std::unique_ptr<TFDQuery> selectHistoryQuery(new TFDQuery(NULL));
		selectHistoryQuery->Connection = DataModule1->FDConnection1;
		selectHistoryQuery->SQL->Text = "SELECT c.request_id, c.quantity, c.contribution_date, d.drone_name "
										"FROM Contributions c "
										"JOIN MilitaryRequests r ON c.request_id = r.request_id "
										"JOIN DroneModel d ON r.drone_id = d.drone_id "
										"WHERE c.user_id = :user_id "
										"ORDER BY c.contribution_date DESC ";

		selectHistoryQuery->ParamByName("user_id")->AsInteger = UserID;
		selectHistoryQuery->Open();

		MemoHistory->Clear();
		MemoHistory->Lines->Add("	������ ������:");
		MemoHistory->Lines->Add("----------------------------------------------------------------------------------");

		while (!selectHistoryQuery->Eof)
			{
				String historyLine;
				historyLine = "     ����� ID: " + selectHistoryQuery->FieldByName("request_id")->AsString + "	\n" +
							  "     ����: " + selectHistoryQuery->FieldByName("drone_name")->AsString + "	\n" +
							  "     ʳ������: " + selectHistoryQuery->FieldByName("quantity")->AsString + "	\n" +
							  "     ����: " + selectHistoryQuery->FieldByName("contribution_date")->AsDateTime.FormatString("dd mmmm");

				MemoHistory->Lines->Add(historyLine);
				MemoHistory->Lines->Add("----------------------------------------------------------------------------------");
				selectHistoryQuery->Next();
			}


		MemoHistory->Visible = true;
	}
	catch (Exception &e)
	{
		ShowMessage("������� �� ��� ������������ ����� ������: " + e.Message);
	}



 }
