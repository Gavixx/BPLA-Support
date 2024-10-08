//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VolonterForm.h"
#include "DataModule.h"
#include "DonateForm.h"
#include "ProfileForm.h"
#include <DateUtils.hpp>  // Для DayOf() і MonthOf()
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------

const String monthNames[12] = {"Січня", "Лютого", "Березня", "Квітня", "Травня", "Червня",
							   "Липня", "Серпня", "Вересня", "Жовтня", "Листопада", "Грудня"};





__fastcall TForm4::TForm4(TComponent* Owner, String userName, int user_id)
	: TForm(Owner), UserName(userName), UserID(user_id)
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
	LabelWelcom->Caption = "Вітаємо, " + UserName + "!";
	DBGrid1->SelectedRows->Clear();
	ButtonDonate->Enabled = false;
    BalloonHint1->Title = "Порада";
	BalloonHint1->Description = "Щоб задонатити, будь ласка, спочатку виберіть рядок у таблиці.";
	BalloonHint1->ShowHint(ButtonDonate);
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
	int gridWidth = DBGrid1->ClientWidth; // Загальна ширина таблиці
	int totalFixedWidth = 0; // Загальна ширина всіх колонок

	// Спочатку встановлюємо фіксовану ширину для всіх колонок і рахуємо загальну ширину
	for (int i = 0; i < DBGrid1->Columns->Count; i++) {
		if (i == 0) {
			DBGrid1->Columns->Items[i]->Visible = false; // Сховати ID запиту
		} else {
			DBGrid1->Columns->Items[i]->Width = gridWidth / DBGrid1->Columns->Count; // Встановити однакову ширину
			totalFixedWidth += DBGrid1->Columns->Items[i]->Width;
		}
	}

	// Вираховуємо невикористаний простір і додаємо його до кожної колонки
	int remainingWidth = gridWidth - totalFixedWidth;
	int extraWidthPerColumn = remainingWidth / (DBGrid1->Columns->Count - 1);

	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width += extraWidthPerColumn; // Додаємо залишкову ширину до кожної колонки
	}

	// Додаємо налаштування заголовків і вирівнювання для кожної колонки
	DBGrid1->Columns->Items[1]->Title->Caption = "Назва дрону";
	DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;

	DBGrid1->Columns->Items[2]->Title->Caption = "Тип дрону";
	DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[2]->Alignment = taCenter;

	DBGrid1->Columns->Items[3]->Title->Caption = "Потрібна к-ть";
	DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[3]->Alignment = taCenter;

	DBGrid1->Columns->Items[4]->Title->Caption = "Дата подачі запиту";
	DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[4]->Alignment = taCenter;

	DBGrid1->Columns->Items[5]->Title->Caption = "Статус";
	DBGrid1->Columns->Items[5]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[5]->Alignment = taCenter;

	DBGrid1->Columns->Items[6]->Title->Caption = "Отримано дронів";
	DBGrid1->Columns->Items[6]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[6]->Alignment = taCenter;

	// Обробник для відображення дати
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
}




void __fastcall TForm4::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // Отримуємо дату з поля

	int day = DayOf(requestDate);   // Отримуємо день з дати
	int month = MonthOf(requestDate);  // Отримуємо місяць з дати

	// Формуємо відформатовану дату
	Text = IntToStr(day) + " " + monthNames[month - 1];
}


void __fastcall TForm4::DBGrid1CellClick(TColumn *Column)
{

	SelectedRequestID = DataModule1->FDQuery1->FieldByName("request_id")->AsInteger;
	MaxQuantityNeeded = DataModule1->FDQuery1->FieldByName("quantity")->AsInteger - DataModule1->FDQuery1->FieldByName("fulfilled_quantity")->AsInteger ;
	SelectedDroneName = DataModule1->FDQuery1->FieldByName("drone_name")->AsString;

	// Enable the Contribute button
	ButtonDonate->Enabled = true;
}
//---------------------------------------------------------------------------

String __fastcall TForm4::GetUserName(){
	return UserName;
}

int __fastcall TForm4::GetUserID(){
	return UserID;
}
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	TForm8 *ProfileForm = new TForm8(this, UserID);
	ProfileForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	if(DataModule1->GetChangeUserState() == false){
	Action = caFree;   // Звільняє пам'ять після закриття
	Application->Terminate();  // Завершує застосунок
	}
}

//---------------------------------------------------------------------------


