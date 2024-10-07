//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddOrderForm.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------

__fastcall TForm5::TForm5(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormCreate(TObject *Sender)
{
    DateTimePickerRequestDate->Date = Now(); // Встановлюємо поточну дату
    ButtonAdd->Enabled = false;              // Кнопка вимкнена, поки поля не заповнені
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ButtonAddClick(TObject *Sender)
{
    // Перевіряємо, чи всі необхідні поля заповнені перед додаванням запиту
    if (LabeledEditDroneName->Text.IsEmpty() || ComboBoxDroneType->Text.IsEmpty() || LabeledEditQuantity->Text.IsEmpty())
    {
        ShowMessage("Будь ласка, заповніть всі обов'язкові поля!");
        return;
    }

    try
    {
        // Спочатку перевіряємо, чи існує дрон у базі
        DataModule1->FDQuery1->Close();
        DataModule1->FDQuery1->SQL->Text = "SELECT drone_id FROM DroneModel WHERE drone_name = :drone_name";
        DataModule1->FDQuery1->ParamByName("drone_name")->AsString = LabeledEditDroneName->Text;
        DataModule1->FDQuery1->Open();

        int drone_id = 0;
        if (!DataModule1->FDQuery1->Eof) {
            drone_id = DataModule1->FDQuery1->FieldByName("drone_id")->AsInteger;
        } else {
            // Якщо дрон не знайдено, додаємо його до бази
            DataModule1->FDQuery1->Close();
            DataModule1->FDQuery1->SQL->Text = "INSERT INTO DroneModel (drone_name, drone_type) VALUES (:drone_name, :drone_type)";
            DataModule1->FDQuery1->ParamByName("drone_name")->AsString = LabeledEditDroneName->Text;
            DataModule1->FDQuery1->ParamByName("drone_type")->AsString = ComboBoxDroneType->Text;
            DataModule1->FDQuery1->ExecSQL();

            // Отримуємо ID новоствореного дрона
            DataModule1->FDQuery1->Close();
            DataModule1->FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS drone_id";
            DataModule1->FDQuery1->Open();
            drone_id = DataModule1->FDQuery1->FieldByName("drone_id")->AsInteger;
        }

        // Тепер додаємо новий запит у MilitaryRequests
        DataModule1->FDQuery1->Close();
        DataModule1->FDQuery1->SQL->Text = "INSERT INTO MilitaryRequests (drone_id, quantity, request_date, status, fulfilled_quantity) "
                                           "VALUES (:drone_id, :quantity, :request_date, :status, :fulfilled_quantity)";
        DataModule1->FDQuery1->ParamByName("drone_id")->AsInteger = drone_id;
        DataModule1->FDQuery1->ParamByName("quantity")->AsInteger = StrToInt(LabeledEditQuantity->Text);
        DataModule1->FDQuery1->ParamByName("request_date")->AsDate = DateTimePickerRequestDate->Date;
        DataModule1->FDQuery1->ParamByName("status")->AsString = "In Progress";
        DataModule1->FDQuery1->ParamByName("fulfilled_quantity")->AsInteger = 0;

        DataModule1->FDQuery1->ExecSQL();
        ShowMessage("Запит успішно додано!");

        TForm3 *ArmyForm = new TForm3(this);
        ArmyForm->Show();
        this->Close();
    }
    catch (Exception &e)
    {
        ShowMessage("Помилка при додаванні запиту: " + e.Message);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckFields()
{
    // Перевірка, чи всі обов'язкові поля заповнені
    bool isEnabled = !LabeledEditDroneName->Text.IsEmpty() &&
                     !ComboBoxDroneType->Text.IsEmpty() &&
                     !LabeledEditQuantity->Text.IsEmpty();

    // Увімкнення або вимкнення кнопки "Додати"
    ButtonAdd->Enabled = isEnabled;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::LabeledEditDroneNameChange(TObject *Sender)
{
    CheckFields();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ComboBoxDroneTypeChange(TObject *Sender)
{
    CheckFields();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::LabeledEditQuantityChange(TObject *Sender)
{
    CheckFields();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::LabeledEditQuantityKeyPress(TObject *Sender, System::WideChar &Key)
{
    if (!CharIsDigit(Key) && Key != 8) {  // 8 - це код клавіші Backspace
        Key = 0;  // Ігнорувати клавішу
    }
}
//---------------------------------------------------------------------------

bool __fastcall TForm5::CharIsDigit(char c)
{
    return (c >= '0' && c <= '9');
}
//---------------------------------------------------------------------------

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
    TForm3 *ArmyForm = dynamic_cast<TForm3*>(Owner);
    if (ArmyForm)
    {
        ArmyForm->Show();
    }

}
//---------------------------------------------------------------------------

