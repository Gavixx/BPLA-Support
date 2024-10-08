//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "AdminForm.h"
#include "LoginForm.h"
#include "ArmyForm.h"
#include "VolonterForm.h"
#include "DataModule.h"

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
		ShowMessage("Please enter both username and password");
		return;
	}

	try {
		DataModule1->ConnectToDatabase();  // Підключаємося до бази даних через DataModule

		// SQL-запит для пошуку ролі, пароля та імені користувача за логіном
		DataModule1->FDQuery1->SQL->Text = "SELECT U.user_id, U.role, U.name, C.password FROM Users U "
										   "INNER JOIN UserCredentials C ON U.user_id = C.user_id "
										   "WHERE C.login = :login";
		DataModule1->FDQuery1->ParamByName("login")->AsString = enteredUsername;
		DataModule1->FDQuery1->Open();

		// Перевіряємо, чи знайдено користувача
		if (!DataModule1->FDQuery1->Eof) {
			// Отримуємо дані з бази
			String storedPassword = DataModule1->FDQuery1->FieldByName("password")->AsString;
			String userRole = DataModule1->FDQuery1->FieldByName("role")->AsString;
			String userName = DataModule1->FDQuery1->FieldByName("name")->AsString;  // Отримуємо ім'я користувача
			int user_id = DataModule1->FDQuery1->FieldByName("user_id")->AsInteger;
			// Перевіряємо, чи збігається введений пароль із тим, що в базі
			if (enteredPassword == storedPassword) {
				OpenRoleSpecificForm(userRole, userName, user_id);  // Передаємо роль і ім'я користувача
				this->Hide();  // Ховаємо форму логіну після відкриття нової форми
			} else {
				ShowMessage("Invalid login or password");
			}
		} else {
			ShowMessage("Invalid login or password");
		}

		// Закриваємо запит і відключаємо з'єднання
		DataModule1->FDQuery1->Close();
		DataModule1->FDConnection1->Connected = false;
	}
	catch (Exception &e) {
		ShowMessage("Помилка: " + e.Message);
		DataModule1->FDConnection1->Connected = false;  // Переконуємося, що підключення вимкнене у разі помилки
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
		TForm4 *VolonterForm = new TForm4(this, userName, user_id);  // Передаємо ім'я користувачаs
		VolonterForm->Show();
	}
	else {
		ShowMessage("Unknown role: " + role);
	}
}

//---------------------------------------------------------------------------


