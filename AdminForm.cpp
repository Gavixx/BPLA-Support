//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdminForm.h"
#include "AddUser.h"
#include "DataModule.h"
#include <DateUtils.hpp>  // Для DayOf() і MonthOf()
 //---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
const String monthNames[12] = {"Січня", "Лютого", "Березня", "Квітня", "Травня", "Червня",
							   "Липня", "Серпня", "Вересня", "Жовтня", "Листопада", "Грудня"};
//---------------------------------------------------------------------------




__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesUsers()
{
	int gridWidth = DBGridUsers->ClientWidth; // Ширина всієї таблички

	// Визначаємо загальну кількість колонок
	int totalColumns = DBGridUsers->Columns->Count;

	// Пропорційні коефіцієнти для колонок (ви можете змінювати ці значення, щоб налаштувати пропорції)
	float coefColumn1 = 0.4; // 40% для першої колонки
	float coefColumn2 = 0.35; // 35% для другої колонки
	float coefColumn3 = 0.25; // 25% для третьої колонки

	// Встановлюємо ширину кожної колонки відносно ширини таблиці
	 DBGridUsers->Columns->Items[0]->Width = gridWidth * coefColumn1;
	 DBGridUsers->Columns->Items[0]->Title->Caption = "ПІБ";
	 DBGridUsers->Columns->Items[0]->Title->Alignment = taCenter;

	 DBGridUsers->Columns->Items[1]->Width = gridWidth * coefColumn2;
	 DBGridUsers->Columns->Items[1]->Title->Caption = "Пошта";
	 DBGridUsers->Columns->Items[1]->Title->Alignment = taCenter;
	 DBGridUsers->Columns->Items[1]->Alignment = taCenter;

	 DBGridUsers->Columns->Items[2]->Width = gridWidth * coefColumn3;
	 DBGridUsers->Columns->Items[2]->Title->Caption = "Телефон";
	 DBGridUsers->Columns->Items[2]->Title->Alignment = taCenter;
	 DBGridUsers->Columns->Items[2]->Alignment = taCenter;

}

void __fastcall TForm2::SetDBGridColumnsStylesRequests(){
	int gridWidth = DBGridRequests->ClientWidth; // Ширина всієї таблички

	// Визначаємо загальну кількість колонок
	int totalColumns = DBGridRequests->Columns->Count;
	// Пропорційні коефіцієнти для колонок (ви можете змінювати ці значення, щоб налаштувати пропорції)
	float coefColumn1 = 0.2;  // 20% для першої колонки
	float coefColumn2 = 0.2;  // 20% для другої колонки
	float coefColumn3 = 0.1;  // 10% для третьої колонки
	float coefColumn4 = 0.2;  // 20% для четвертої колонки
	float coefColumn5 = 0.2;  // 20% для п'ятої колонки
	float coefColumn6 = 0.1;  // 10% для шостої колонки



	// Встановлюємо ширину кожної колонки відносно ширини таблиці
	 DBGridRequests->Columns->Items[0]->Width = 386;
	 DBGridRequests->Columns->Items[0]->Title->Caption = "Назва дрону";
	 DBGridRequests->Columns->Items[0]->Title->Alignment = taCenter;

	 DBGridRequests->Columns->Items[1]->Width = 275;
	 DBGridRequests->Columns->Items[1]->Title->Caption = "Тип дрону";
	 DBGridRequests->Columns->Items[1]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[1]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[2]->Width = 231;
	 DBGridRequests->Columns->Items[2]->Title->Caption = "Потрібна к-ть";
	 DBGridRequests->Columns->Items[2]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[2]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[3]->Width = 231;
	 DBGridRequests->Columns->Items[3]->Title->Caption = "Дата подачі запиту";
	 DBGridRequests->Columns->Items[3]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[3]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[4]->Width = 231;
	 DBGridRequests->Columns->Items[4]->Title->Caption = "Статус";
	 DBGridRequests->Columns->Items[4]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[4]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[5]->Width = 154;
	 DBGridRequests->Columns->Items[5]->Title->Caption = "Отримано дронів";
	 DBGridRequests->Columns->Items[5]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[5]->Alignment = taCenter;

	// Обробник для відображення дати
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;


}

//---------------------------------------------------------------------------

void __fastcall TForm2::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // Отримуємо дату з поля

	int day = DayOf(requestDate);   // Отримуємо день з дати
	int month = MonthOf(requestDate);  // Отримуємо місяць з дати

	// Формуємо відформатовану дату
	Text = IntToStr(day) + " " + monthNames[month - 1];
}


//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonShowUsersClick(TObject *Sender)
{
	LoadUsers();
}



//---------------------------------------------------------------------------
void __fastcall TForm2::LoadUsers(){
	try {
		DataModule1->ConnectToDatabase();	  // Підключення до бази через DataModule1

		// Налаштування запиту через DataModule1
		DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
		DataModule1->FDQuery1->SQL->Text = "SELECT name, email, phone FROM Volunteers";
		DataModule1->FDQuery1->Open();  // Виконує запит та відкриває результати

		// Прив'язка даних
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridUsers->DataSource = DataModule1->DataSource1;
		SetDBGridColumnsStylesUsers();  // Встановлюємо стилі колонок
	} catch (const Exception &e) {
		ShowMessage("Помилка при отриманні даних: " + e.Message);
	}
}
void __fastcall TForm2::ButtonAddUserClick(TObject *Sender)
{
	TForm6 *AddUser = new TForm6(this);
	AddUser->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DBGridUsersTitleClick(TColumn *Column)
{
	// Ім'я поля, за яким відбудеться сортування
	static String lastSortedColumn = "";  // Остання відсортована колонка
	static bool sortAscending = true;     // Прапор для напрямку сортування

	String columnName = Column->FieldName;

	// Перевірка, чи є активний DataSet, і чи підтримує він SQL
	if (DataModule1->DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet);

		// Отримуємо поточний SQL запит
		String baseSQL = query->SQL->Text;

		// Спробуємо знайти вже існуюче "ORDER BY"
		int orderByPos = baseSQL.Pos("ORDER BY");
		// Якщо "ORDER BY" вже існує, видаляємо його
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// Якщо клікаємо по тій самій колонці, змінюємо напрямок сортування
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // Міняємо прапор
		}
		else
		{
			// Якщо інша колонка, завжди починаємо з сортування за зростанням
			sortAscending = true;
		}

		// Зберігаємо поточну колонку як останню відсортовану
		lastSortedColumn = columnName;

		// Формуємо запит із новим сортуванням
		String sortDirection = sortAscending ? "ASC" : "DESC";
		baseSQL += " ORDER BY " + columnName + " " + sortDirection;

		// Оновлюємо запит і перезавантажуємо дані
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();

		// Прив'язка оновленого запиту до DataSource
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		SetDBGridColumnsStylesUsers();  // Оновлюємо стилі колонок
	}
}


void __fastcall TForm2::ButtonShowRequestsClick(TObject *Sender)
{
	LoadRequests();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadRequests()
{
	DBGridUsers->Visible = false;
	DBGridRequests->Visible = true;
	DataModule1->ConnectToDatabase();	  // Переконайтесь, що з'єднання з базою даних активно

	// Налаштування запиту
	DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
	DataModule1->FDQuery1->SQL->Text = "SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
						   "FROM MilitaryRequests MR "
						   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id";
	DataModule1->FDQuery1->Open();  // Виконує запит та відкриває результати

	// Прив'язка даних
	DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
	DBGridRequests->DataSource = DataModule1->DataSource1;
	SetDBGridColumnsStylesRequests();
}


