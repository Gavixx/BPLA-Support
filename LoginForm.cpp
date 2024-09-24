//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "AdminForm.h"
#include "LoginForm.h"
#include "ArmyForm.h"
#include "VolonterForm.h"


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

	bool status = false;
	String enteredUsername = EditLogin->Text;
	String enteredPassword = EditPassword->Text;
try {
		// ϳ���������� �� ���� �����
		FDConnection1->Connected = true;

		// SQL-����� ��� ������ ����������� �� ������
		FDQuery1->SQL->Text = "SELECT password FROM Users WHERE username = :username";
		FDQuery1->ParamByName("username")->AsString = enteredUsername;

		// �������� �����
		FDQuery1->Open();

		// ����������, �� �������� �����������
		if (!FDQuery1->Eof) {
			// �������� ������ �� ���� �����
			String storedPassword = FDQuery1->FieldByName("password")->AsString;

			// ����������, �� �������� �������� ������ �� ���, �� � ���
			if (enteredPassword == storedPassword) {
				if (enteredUsername == "admin") {
					TForm2 *AdminForm = new TForm2(this);
					AdminForm->Show();
					this->Hide();  // ������ ����� ����� ���� �������� ���� �����
				}
				else if(enteredUsername == "army"){
					TForm3 *ArmyForm = new TForm3(this);
					ArmyForm->Show();
					this->Hide();}
				else{
					TForm4 *VolonterForm = new TForm4(this);
					VolonterForm->Show();
					this->Hide();
				}



			} else {
				ShowMessage("Ivalid login or password");
			}
		} else {
			ShowMessage("Ivalid login or password");
		}

		// ��������� ����� � �'�������
		FDQuery1->Close();
		FDConnection1->Connected = false;
	}
	catch (Exception &e) {
		ShowMessage("�������: " + e.Message);
	}





}
//---------------------------------------------------------------------------

void __fastcall TForm1::Help2Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Help3Click(TObject *Sender)
{
             ShowMessage("Help\n"
		"Welcome to the Military Drone Management Application. This software is designed to help military personnel manage drone requests and volunteer contributions efficiently.\n\n"

		"Getting Started:\n"
		"To get started with the application:\n"
		"  - Installation: Download the installer from our website and follow the on-screen instructions to install.\n"
		"  - Launching the Application: Once installed, double-click the application icon to launch.\n\n"

		"Using the Application:\n"
		"  - Military Requests: To create a new military request, navigate to the \"Military Requests\" tab, fill in the required fields, and click \"Add Request\".\n"
		"  - Volunteers: Manage volunteer contributions under the \"Volunteers\" section.\n"
		"  - Drone Models: You can manage drone models under the \"Drone Models\" section. Click \"Add Model\" to enter new drone information.\n\n"

		"Filtering and Searching:\n"
		"To filter military requests:\n"
		"  - Use the date pickers to select a date range.\n"
		"  - If you want to filter by drone name, select the desired name from the dropdown.\n"
		"  - Click the \"Filter\" button to apply the selected criteria.\n\n"

		"Common Issues and Troubleshooting:\n"
		"  - Issue: Unable to add a new military request. Solution: Ensure all required fields are filled in correctly.\n"
		"  - Issue: Application crashes on startup. Solution: Check for updates and VPN connection or reinstall the application.\n")     ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Help4Click(TObject *Sender)
{
    ShowMessage( " About Us\n"
		"This application was developed by the HighTech team. Version: 1.0.\n\n"

		"For additional assistance, please contact support at HighTech@info.com.");
}
//---------------------------------------------------------------------------

