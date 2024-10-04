#include <vcl.h>
#pragma hdrstop

#include "DonateForm.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner, int requestID, String droneName, int maxQuantity, int userID)
    : TForm(Owner), SelectedRequestID(requestID), SelectedDroneName(droneName), MaxQuantityNeeded(maxQuantity), UserID(userID)
{
    LabelDroneName->Caption = "Дрон: " + SelectedDroneName;
	LabelMaxQuantity->Caption = "Максимальна кількість: " + IntToStr(MaxQuantityNeeded);
    EditQuantity->Text = "1";
}

//---------------------------------------------------------------------------

void __fastcall TForm7::FillBox()
{
    try
    {
        DataModule1->ConnectToDatabase(); // Ensure the database connection is active

        DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
        DataModule1->FDQuery1->Close();

        // Updated SQL query to select distinct drone names with status 'In Progress'
        DataModule1->FDQuery1->SQL->Text =
            "SELECT DISTINCT DM.drone_name "
            "FROM DroneModel DM "
            "JOIN MilitaryRequests MR ON DM.drone_id = MR.drone_id "
            "WHERE MR.status = 'In Progress'";

        DataModule1->FDQuery1->Open();

        ComboBoxDrones->Items->Clear();
        while (!DataModule1->FDQuery1->Eof)
        {
            ComboBoxDrones->Items->Add(DataModule1->FDQuery1->FieldByName("drone_name")->AsString);
            DataModule1->FDQuery1->Next();
        }
    }
    catch (Exception &e)
    {
        ShowMessage("Помилка при заповненні списку дронів: " + e.Message);
    }
}

void __fastcall TForm7::ComboBoxDronesChange(TObject *Sender)
{
	UpdateMaxQuantityNeeded();
}

void __fastcall TForm7::UpdateMaxQuantityNeeded()
{
    String selectedDrone = ComboBoxDrones->Text.Trim();

    if (selectedDrone.IsEmpty())
    {
        // No drone selected, reset MaxQuantityNeeded
        MaxQuantityNeeded = 0;
        LabelMaxQuantity->Caption = "";
        EditQuantity->Text = "";
        EditQuantity->Enabled = false;
        ButtonSend->Enabled = false;
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

        // Retrieve the total remaining quantity needed for the selected drone
        TFDQuery *quantityQuery = new TFDQuery(NULL);
        quantityQuery->Connection = DataModule1->FDConnection1;
        quantityQuery->SQL->Text =
            "SELECT SUM(MR.quantity - MR.fulfilled_quantity) AS remaining_quantity "
            "FROM MilitaryRequests MR "
            "JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
            "WHERE MR.status = 'In Progress' AND DM.drone_name = :drone_name";
        quantityQuery->ParamByName("drone_name")->AsString = selectedDrone;
        quantityQuery->Open();

        if (!quantityQuery->Eof && !quantityQuery->FieldByName("remaining_quantity")->IsNull)
        {
            MaxQuantityNeeded = quantityQuery->FieldByName("remaining_quantity")->AsInteger;
        }
        else
        {
            MaxQuantityNeeded = 0;
        }

        quantityQuery->Close();
        delete quantityQuery;

        // Display the MaxQuantityNeeded to the user
        LabelMaxQuantity->Caption = "Максимальна кількість для пожертви: " + IntToStr(MaxQuantityNeeded);

        if (MaxQuantityNeeded <= 0)
        {
            ShowMessage("Немає потреби в додаткових пожертвах для цього дрону.");
            EditQuantity->Enabled = false;
            ButtonSend->Enabled = false;
            EditQuantity->Text = "";
        }
        else
        {
            EditQuantity->Enabled = true;
            ButtonSend->Enabled = true;
            EditQuantity->Text = "1";
        }

    }
    catch (Exception &e)
    {
        ShowMessage("Помилка при отриманні максимальної кількості: " + e.Message);
        MaxQuantityNeeded = 0;
        EditQuantity->Enabled = false;
        ButtonSend->Enabled = false;
        EditQuantity->Text = "";
        LabelMaxQuantity->Caption = "";
    }
}

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
	String selectedDrone = ComboBoxDrones->Text.Trim();
    if (selectedDrone.IsEmpty())
    {
        ShowMessage("Будь ласка, оберіть дрон для пожертви.");
        return;
    }

    String quantityText = EditQuantity->Text.Trim();
    int quantity = StrToIntDef(quantityText, -1);
    if (quantity <= 0)
    {
        ShowMessage("Будь ласка, введіть коректну кількість для пожертви.");
        return;
    }

    if (quantity > MaxQuantityNeeded)
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

        // Get drone_id from DroneModel table
        int droneID = -1;
        TFDQuery *droneQuery = new TFDQuery(NULL);
        droneQuery->Connection = DataModule1->FDConnection1;
        droneQuery->SQL->Text = "SELECT drone_id FROM DroneModel WHERE drone_name = :drone_name";
        droneQuery->ParamByName("drone_name")->AsString = selectedDrone;
        droneQuery->Open();

        if (!droneQuery->Eof)
        {
            droneID = droneQuery->FieldByName("drone_id")->AsInteger;
        }
        else
        {
            ShowMessage("Обраний дрон не знайдено в базі даних.");
            droneQuery->Close();
            delete droneQuery;
            return;
        }
        droneQuery->Close();
        delete droneQuery;

        // Insert the donation into the Donations table
        // Ensure that the Donations table exists in your database
        TFDQuery *insertDonationQuery = new TFDQuery(NULL);
        insertDonationQuery->Connection = DataModule1->FDConnection1;
        insertDonationQuery->SQL->Text = "INSERT INTO Donations (drone_id, quantity, donation_date) VALUES (:drone_id, :quantity, NOW())";
        insertDonationQuery->ParamByName("drone_id")->AsInteger = droneID;
        insertDonationQuery->ParamByName("quantity")->AsInteger = quantity;

        insertDonationQuery->ExecSQL();
        delete insertDonationQuery;

        // Optionally, update the fulfilled_quantity in MilitaryRequests
        // ... (code to update MilitaryRequests if needed) ...

        // After successful donation
        ShowMessage("Дякуємо за вашу пожертву!");

        // Clear the input fields
        EditQuantity->Clear();

        // Update the MaxQuantityNeeded
        UpdateMaxQuantityNeeded();
    }
    catch (Exception &e)
    {
        ShowMessage("Виникла помилка під час обробки вашої пожертви: " + e.Message);
    }
}
//----------------------------------------------------------------


//---------------------------------------------------------------------------

