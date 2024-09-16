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
void __fastcall TForm5::ButtonAddClick(TObject *Sender)
{

   //	String dronetype =  LabeledEditDroneType->Text;
	//int quantity = StrToInt(LabeledEditQuantity->Text);
	//TDateTime selectedDate = DateTimePickerRequestDate->Date;
	//String status = "В процесі";
	//String formattedDate = FormatDateTime("yyyy-mm-dd", selectedDate);
	//ShowMessage(formattedDate);
	//int fulfilledquantity = 0;


	FDQuery1->SQL->Text = "INSERT INTO MilitaryRequests (drone_type, quantity, request_date, status, fulfilled_quantity) "
						  "VALUES (:drone_type, :quantity, :request_date, :status, :fulfilled_quantity)";

	FDQuery1->ParamByName("drone_type")->AsString = LabeledEditDroneType->Text;
	FDQuery1->ParamByName("quantity")->AsInteger = StrToInt(LabeledEditQuantity->Text);
	FDQuery1->ParamByName("request_date")->AsDate = DateTimePickerRequestDate->Date;
	FDQuery1->ParamByName("status")->AsString = "In Process";
	FDQuery1->ParamByName("fulfilled_quantity")->AsInteger =0;
	  try
	{
		FDQuery1->ExecSQL();  // Виконати запит
		ShowMessage("Запит успішно додано!");
		TForm3 *ArmyForm = new TForm3(this);
		ArmyForm->Show();
		this -> Close();
	}
	catch (Exception &e)
	{
		ShowMessage("Помилка при додаванні запиту: " + e.Message);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
	FDQuery1->Connection = FDConnection1;
	DateTimePickerRequestDate->Date = Now();
}
//---------------------------------------------------------------------------
