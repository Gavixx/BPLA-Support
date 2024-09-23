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
		// Підключаємося до бази даних
		FDConnection1->Connected = true;

		// SQL-запит для пошуку користувача за логіном
		FDQuery1->SQL->Text = "SELECT password FROM Users WHERE username = :username";
		FDQuery1->ParamByName("username")->AsString = enteredUsername;

		// Виконуємо запит
		FDQuery1->Open();

		// Перевіряємо, чи знайдено користувача
		if (!FDQuery1->Eof) {
			// Отримуємо пароль із бази даних
			String storedPassword = FDQuery1->FieldByName("password")->AsString;

			// Перевіряємо, чи збігається введений пароль із тим, що в базі
			if (enteredPassword == storedPassword) {
				if (enteredUsername == "admin") {
					TForm2 *AdminForm = new TForm2(this);
					AdminForm->Show();
					this->Hide();  // Ховаємо форму логіну після відкриття нової форми
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

		// Закриваємо запит і з'єднання
		FDQuery1->Close();
		FDConnection1->Connected = false;
	}
	catch (Exception &e) {
		ShowMessage("Помилка: " + e.Message);
	}





}
//---------------------------------------------------------------------------

