//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VolonterForm.h"
#include "DataModule.h"
#include "DonateForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner, String userName)
    : TForm(Owner), UserName(userName)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm4::LoadDB()  {
 // Переконайтесь, що з'єднання до бази даних активно
	if (!DataModule1->FDConnection1->Connected) {
        DataModule1->ConnectToDatabase();
	}

    // Закриваємо попередній запит перед відкриттям нового
	DataModule1->FDQuery1->Close();

	// Налаштовуємо запит через DataModule1
	DataModule1->FDQuery1->SQL->Text = "SELECT MR.request_id, DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
									   "FROM MilitaryRequests MR "
									   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
										"WHERE MR.status = 'In Progress'";
	DataModule1->FDQuery1->Open();  // Виконує запит та відкриває результати

	if (DataModule1->FDQuery1->RecordCount > 0) {
		// Прив'язка даних до DataSource через DataModule1
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;

		// Прив'язка DataSource до DBGrid через DataModule1
		DBGrid1->DataSource = DataModule1->DataSource1;

		// Налаштування стилю колонок DBGrid
		SetDBGridColumnsStyles();
	} else {
        ShowMessage("Немає даних для відображення.");
	}               }

void __fastcall TForm4::FormShow(TObject *Sender)
{
	   LoadDB();
	// Відображення в Label або інший спосіб показу імені
	LabelWelcom->Caption = "Welcome, " + UserName + "!";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ButtonShowRequestsClick(TObject *Sender)
{
	LoadDB();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::ButtonDonateClick(TObject *Sender)
{
	 TForm7 *DonateForm = new TForm7(this, SelectedRequestID, SelectedDroneName, MaxQuantityNeeded, UserID);
    DonateForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::SetDBGridColumnsStyles()
{
		int gridWidth = DBGrid1->ClientWidth; // Ширина всієї таблички

	// Перевіряємо, чи є достатньо колонок
	if (DBGrid1->Columns->Count >= 7) {
		DBGrid1->Columns->Items[0]->Visible = false;


		DBGrid1->Columns->Items[1]->Width = 386;
		DBGrid1->Columns->Items[1]->Title->Caption = "Назва дрону";
		DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;

		DBGrid1->Columns->Items[2]->Width = 275;
		DBGrid1->Columns->Items[2]->Title->Caption = "Тип дрону";
		DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[2]->Alignment = taCenter;

		DBGrid1->Columns->Items[3]->Width = 231;
		DBGrid1->Columns->Items[3]->Title->Caption = "Потрібна к-ть";
		DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[3]->Alignment = taCenter;

		DBGrid1->Columns->Items[4]->Width = 231;
		DBGrid1->Columns->Items[4]->Title->Caption = "Дата подачі запиту";
		DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[4]->Alignment = taCenter;

		DBGrid1->Columns->Items[5]->Width = 231;
		DBGrid1->Columns->Items[5]->Title->Caption = "Статус";
		DBGrid1->Columns->Items[5]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[5]->Alignment = taCenter;

		DBGrid1->Columns->Items[6]->Width = 154;
		DBGrid1->Columns->Items[6]->Title->Caption = "Отримано дронів";
		DBGrid1->Columns->Items[6]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[6]->Alignment = taCenter;

		// Обробник для відображення дати
//		DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
	} else {
		ShowMessage("Недостатньо колонок для налаштування ширини.");
	}
}



void __fastcall TForm4::DBGrid1CellClick(TColumn *Column)
{


	SelectedRequestID = DataModule1->FDQuery1->FieldByName("request_id")->AsInteger;
	MaxQuantityNeeded = DataModule1->FDQuery1->FieldByName("quantity")->AsInteger;
	SelectedDroneName = DataModule1->FDQuery1->FieldByName("drone_name")->AsString;

    // Enable the Contribute button
	ButtonDonate->Enabled = true;
}
//---------------------------------------------------------------------------

