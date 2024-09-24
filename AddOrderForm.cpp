	//---------------------------------------------------------------------------

	#include <vcl.h>
	#pragma hdrstop

	#include "AddOrderForm.h"
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
		FDQuery1->Connection = FDConnection1;
		DateTimePickerRequestDate->Date = Now();
		ButtonAdd->Enabled = false;
	}
	//---------------------------------------------------------------------------


	void __fastcall TForm5::ButtonAddClick(TObject *Sender)
	{
		  // Check if the required fields are filled

		// Enable or disable the button based on the result

		FDQuery1->Close();  // ������� �����, ���� �� ��������
		FDQuery1->SQL->Text = "SELECT drone_id FROM DroneModel WHERE drone_name = :drone_name";
		FDQuery1->ParamByName("drone_name")->AsString = LabeledEditDroneName->Text;  // �������� �������� drone_name

		FDQuery1->Open();  // �������� �����
		int drone_id = 0;

		// ����������, �� � ����� � ���������
		if (!FDQuery1->Eof) {
			drone_id = FDQuery1->FieldByName("drone_id")->AsInteger;
		} else {
			// ���� ������ ����, ������ ����� ����
			FDQuery1->Close();  // ������� �����
			FDQuery1->SQL->Text = "INSERT INTO DroneModel (drone_name, drone_type) VALUES (:drone_name, :drone_type)";
			FDQuery1->ParamByName("drone_name")->AsString = LabeledEditDroneName->Text;
			FDQuery1->ParamByName("drone_type")->AsString = ComboBoxDroneType->Text;  // ��� ����-���� ����� ���
			FDQuery1->ExecSQL();  // �������� �������

			// ϳ��� ������� �������� ID �������������� �����
			FDQuery1->Close();  // ������� �����
			FDQuery1->SQL->Text = "SELECT LAST_INSERT_ID() AS drone_id";  // �������� �������� ���������� ID
			FDQuery1->Open();  // �������� �����
			drone_id = FDQuery1->FieldByName("drone_id")->AsInteger;
		}

		FDQuery1->Close();  // ������� ����� ���� ��������� drone_id

		// ���������� ����� ����� � MilitaryRequests
		FDQuery1->SQL->Text = "INSERT INTO MilitaryRequests (drone_id, quantity, request_date, status, fulfilled_quantity) "
							  "VALUES (:drone_id, :quantity, :request_date, :status, :fulfilled_quantity)";
		FDQuery1->ParamByName("drone_id")->AsInteger = drone_id;
		FDQuery1->ParamByName("quantity")->AsInteger = StrToInt(LabeledEditQuantity->Text);
		FDQuery1->ParamByName("request_date")->AsDate = DateTimePickerRequestDate->Date;
		FDQuery1->ParamByName("status")->AsString = "In Process";
		FDQuery1->ParamByName("fulfilled_quantity")->AsInteger = 0;

		try {
			FDQuery1->ExecSQL();  // �������� �����
			ShowMessage("����� ������ ������!");
			TForm3 *ArmyForm = new TForm3(this);
			ArmyForm->Show();
			this->Close();
		}
		catch (Exception &e) {
			ShowMessage("������� ��� ��������� ������: " + e.Message);
		}

	}
	//---------------------------------------------------------------------------



    void __fastcall TForm5::CheckFields()
{
    // Check if the required fields are filled
    bool isEnabled = !LabeledEditDroneName->Text.IsEmpty() &&
                     !ComboBoxDroneType->Text.IsEmpty() &&
                     !LabeledEditQuantity->Text.IsEmpty();

    // Enable or disable the Add Order button based on the result
    ButtonAdd->Enabled = isEnabled;
}
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
  if (!CharIsDigit(Key) && Key != 8) { // 8 is the ASCII code for Backspace
        Key = 0; // Ignore the key press
	}
}
//---------------------------------------------------------------------------


bool __fastcall TForm5::CharIsDigit(char c)
{
    return (c >= '0' && c <= '9');
}

//------------------------------------------------------------------------
void __fastcall TForm5::Close1Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

