//---------------------------------------------------------------------------


#pragma hdrstop

#include "DataModule.h"
#include "LoginForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
	changeuser = false;
	wchar_t buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	PathRemoveFileSpec(buffer);  // Видаляємо ім'я виконуваного файлу
	PathRemoveFileSpec(buffer);
	PathRemoveFileSpec(buffer);
	String basePath = buffer;
	String libPath = basePath + L"\\lib\\libmysql.dll";

	try{
		FDPhysMySQLDriverLink1->VendorLib = libPath;
	}
	catch (Exception &e) {
		ShowMessage("Помилка: " + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::ConnectToDatabase()
{
    try {
        FDConnection1->Connected = true;  // Підключаємося до бази
    } catch (const Exception &e) {
        ShowMessage("Помилка підключення до бази: " + e.Message);
    }
}

void __fastcall TDataModule1::ActionCloseExecute(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::ActionHelpExecute(TObject *Sender)
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
		"  - Issue: Application crashes on startup. Solution: Check for updates and VPN connection or reinstall the application.\n");
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::ActionAboutUsExecute(TObject *Sender)
{
		ShowMessage( " About Us\n"
		"This application was developed by the HighTech team. Version: 1.0.\n\n"

		"For additional assistance, please contact support at HighTech@info.com.");
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::ActionChangeUserExecute(TObject *Sender)
{
	changeuser = true;
    // Створюємо форму входу
    TForm1 *LoginForm = new TForm1(this);
	Screen->ActiveForm->Close();
	LoginForm->Show();
}

bool __fastcall TDataModule1::GetChangeUserState(){
	return changeuser;
}

