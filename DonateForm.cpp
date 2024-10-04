#include <vcl.h>
#pragma hdrstop

#include "DonateForm.h"
#include "DataModule.h"
#include "VolonterForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner, int requestID, String droneName, int maxQuantity, int userID)
	: TForm(Owner), SelectedRequestID(requestID), SelectedDroneName(droneName), MaxQuantityNeeded(maxQuantity), UserID(userID)
{
	LabelDroneName->Caption = "Ви обрали дрон: " + SelectedDroneName;
	LabelMaxQuantity->Caption = "МАКСИМАЛЬНА КІЛЬКІСТЬ: " + IntToStr(MaxQuantityNeeded);
	EditQuantity->Text = "1";
}

//---------------------------------------------------------------------------

void __fastcall TForm7::EditQuantityKeyPress(TObject *Sender, System::WideChar &Key)
{
	// Allow only digits and control characters
	if (!((Key >= '0' && Key <= '9') || Key == VK_BACK || Key == '\b'))
	{
		Key = 0; // Discard the key
	}
}

void __fastcall TForm7::ButtonSendClick(TObject *Sender)
{
	String quantityText = EditQuantity->Text.Trim();
	int quantityg = StrToIntDef(quantityText, -1);
//	ShowMessage(quantityg);
//	ShowMessage(MaxQuantityNeeded);
	if (quantityg == -1)
	{
		ShowMessage("Введено некоректне значення. Будь ласка, введіть дійсне число.");
		return;
	}
	if (quantityg > MaxQuantityNeeded)
	{
		ShowMessage("Кількість пожертви перевищує максимально необхідну кількість (" + IntToStr(MaxQuantityNeeded) + ").");
		return;
	}

	try
	{
		// Ensure the database connection is active
		if (!DataModule1->FDConnection1->Connected)
		{
			DataModule1->ConnectToDatabase();
			if (!DataModule1->FDConnection1->Connected)
			{
				throw Exception("Не вдалося підключитися до бази даних.");
			}
		}
		  // Start a transaction
		DataModule1->FDConnection1->StartTransaction();

		// Insert into Contributions
		std::unique_ptr<TFDQuery> insertDonationQuery(new TFDQuery(NULL));
        insertDonationQuery->Connection = DataModule1->FDConnection1;
        insertDonationQuery->SQL->Text = "INSERT INTO Contributions (user_id, request_id, quantity, contribution_date) VALUES (:user_id, :request_id, :quantity, NOW())";
		insertDonationQuery->ParamByName("user_id")->AsInteger = UserID;
        insertDonationQuery->ParamByName("request_id")->AsInteger = SelectedRequestID;
        insertDonationQuery->ParamByName("quantity")->AsInteger = quantityg;
		insertDonationQuery->ExecSQL();


		// Update fulfilled_quantity in MilitaryRequests
		std::unique_ptr<TFDQuery> updateRequestQuery(new TFDQuery(NULL));
		updateRequestQuery->Connection = DataModule1->FDConnection1;
		if (quantityg>=MaxQuantityNeeded) {
		   updateRequestQuery->SQL->Text = "UPDATE MilitaryRequests "
										"SET fulfilled_quantity = fulfilled_quantity + :quantity, status = 'Complete' "
										"WHERE request_id = :request_id";
		}
		else{
            updateRequestQuery->SQL->Text = "UPDATE MilitaryRequests "
										"SET fulfilled_quantity = fulfilled_quantity + :quantity "
										"WHERE request_id = :request_id";
        }

		updateRequestQuery->ParamByName("quantity")->AsInteger = quantityg;
		updateRequestQuery->ParamByName("request_id")->AsInteger = SelectedRequestID;
		updateRequestQuery->ExecSQL();
		// After successful donation
		ShowMessage("Дякуємо за вашу пожертву!");

		TForm4 *VolonterForm = dynamic_cast<TForm4*>(Owner);
		if (VolonterForm)
		{
			VolonterForm->Show();
		}
		this->Close();
	}
	catch (Exception &e)
	{
		ShowMessage("Виникла помилка під час обробки вашої пожертви: " + e.Message);
	}
}
//----------------------------------------------------------------
void __fastcall TForm7::ButtonCancelClick(TObject *Sender)
{
	TForm4 *VolonterForm = dynamic_cast<TForm4*>(Owner);
	if (VolonterForm)
	{
		VolonterForm->Show();
	}
	this->Close();
}
//---------------------------------------------------------------------------

