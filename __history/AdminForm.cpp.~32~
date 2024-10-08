//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdminForm.h"
#include "AddUser.h"
#include "DataModule.h"
#include <DateUtils.hpp>
#include "AddOrg.h"
#include "ProfileForm.h"
#include "AddOrderForm.h"

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

					// Стиль для таблиці Юзерів
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesUsers()
{
	int gridWidth = DBGridUsers->ClientWidth; // Загальна ширина таблиці
	int totalFixedWidth = 0; // Загальна ширина всіх колонок

	// Спочатку встановлюємо фіксовану ширину для всіх колонок і рахуємо загальну ширину
	for (int i = 0; i < DBGridUsers->Columns->Count; i++) {
		if (i == 0) {
			DBGridUsers->Columns->Items[i]->Visible = false; // Сховати user_id
		} else {
			DBGridUsers->Columns->Items[i]->Width = gridWidth / (DBGridUsers->Columns->Count - 1); // Встановити однакову ширину
			totalFixedWidth += DBGridUsers->Columns->Items[i]->Width;
		}
	}

	// Вираховуємо невикористаний простір і додаємо його до кожної колонки
	int remainingWidth = gridWidth - totalFixedWidth;
	int extraWidthPerColumn = remainingWidth / (DBGridUsers->Columns->Count - 1);

	for (int i = 1; i < DBGridUsers->Columns->Count; i++) {
		DBGridUsers->Columns->Items[i]->Width += extraWidthPerColumn; // Додаємо залишкову ширину до кожної колонки
	}

	// Додаємо налаштування заголовків і вирівнювання для кожної колонки
	DBGridUsers->Columns->Items[1]->Title->Caption = "ПІБ";
	DBGridUsers->Columns->Items[1]->Title->Alignment = taCenter;

	DBGridUsers->Columns->Items[2]->Title->Caption = "Пошта";
	DBGridUsers->Columns->Items[2]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[2]->Alignment = taCenter;

	DBGridUsers->Columns->Items[3]->Title->Caption = "Телефон";
	DBGridUsers->Columns->Items[3]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[3]->Alignment = taCenter;

	DBGridUsers->Columns->Items[4]->Title->Caption = "Роль";
	DBGridUsers->Columns->Items[4]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[4]->Alignment = taCenter;

	DBGridUsers->Columns->Items[5]->Title->Caption = "Організація";
	DBGridUsers->Columns->Items[5]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[5]->Alignment = taCenter;

	// У вас немає поля з датою, тому обробник для відображення дати не потрібен

}

					// Стиль для таблиці Запитів
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesRequests(){
	int gridWidth = DBGridRequests->ClientWidth; // Ширина таблиці

	// Пропорції для колонок
	float coefColumn1 = 0.2;  // Назва дрону
	float coefColumn2 = 0.15; // Тип дрону
	float coefColumn3 = 0.1;  // Потрібна кількість
	float coefColumn4 = 0.2;  // Дата подачі запиту
	float coefColumn5 = 0.2;  // Статус
	float coefColumn6 = 0.15; // Отримано дронів

	// Встановлення ширини кожної колонки відносно ширини таблиці
	DBGridRequests->Columns->Items[0]->Width = gridWidth * coefColumn1;
	DBGridRequests->Columns->Items[0]->Title->Caption = "Назва дрону";
	DBGridRequests->Columns->Items[0]->Title->Alignment = taCenter;

	DBGridRequests->Columns->Items[1]->Width = gridWidth * coefColumn2;
	DBGridRequests->Columns->Items[1]->Title->Caption = "Тип дрону";
	DBGridRequests->Columns->Items[1]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[1]->Alignment = taCenter;

	DBGridRequests->Columns->Items[2]->Width = gridWidth * coefColumn3;
	DBGridRequests->Columns->Items[2]->Title->Caption = "Потрібна к-ть";
	DBGridRequests->Columns->Items[2]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[2]->Alignment = taCenter;

	DBGridRequests->Columns->Items[3]->Width = gridWidth * coefColumn4;
	DBGridRequests->Columns->Items[3]->Title->Caption = "Дата подачі запиту";
	DBGridRequests->Columns->Items[3]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[3]->Alignment = taCenter;

	DBGridRequests->Columns->Items[4]->Width = gridWidth * coefColumn5;
	DBGridRequests->Columns->Items[4]->Title->Caption = "Статус";
	DBGridRequests->Columns->Items[4]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[4]->Alignment = taCenter;

	DBGridRequests->Columns->Items[5]->Width = gridWidth * coefColumn6;
	DBGridRequests->Columns->Items[5]->Title->Caption = "Отримано дронів";
	DBGridRequests->Columns->Items[5]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[5]->Alignment = taCenter;

	// Обробник для відображення дати
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
}

					// Ф-я для відобреження коректно дат
//---------------------------------------------------------------------------
void __fastcall TForm2::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // Отримуємо дату з поля

	int day = DayOf(requestDate);   // Отримуємо день з дати
	int month = MonthOf(requestDate);  // Отримуємо місяць з дати

	// Формуємо відформатовану дату
	Text = IntToStr(day) + " " + monthNames[month - 1];
}

					// Кнопка показати користувачів
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowUsersClick(TObject *Sender)
{
	LoadUsers();
}

					// Загрузка даних з бд в таблицю
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadUsers(){
	DBGridContributions->Visible = false;
	DBGridUsers->Visible = true;
	DBGridRequests->Visible = false;

	try {
		DataModule1->ConnectToDatabase();  // Підключення до бази через DataModule1

		// Налаштування запиту через DataModule1
		DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;

		// SQL-запит для отримання даних користувачів з таблиці Users з посиланням на організації
		DataModule1->FDQuery1->SQL->Text =
			"SELECT U.user_id, U.name, U.email, U.phone, U.role, O.name AS organization_name "
			"FROM Users U "
			"LEFT JOIN Organizations O ON U.organization_id = O.organization_id";  // Приєднання організацій

		DataModule1->FDQuery1->Open();  // Виконує запит та відкриває результати

		// Прив'язка даних
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridUsers->DataSource = DataModule1->DataSource1;
		SetDBGridColumnsStylesUsers();  // Встановлюємо стилі колонок для користувачів
	} catch (const Exception &e) {
		ShowMessage("Помилка при отриманні даних: " + e.Message);
	}
}

					// Для сортування при нажиманні на колонку в таблиці Користувач
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

		// Базовий SQL-запит для користувачів з організаціями
		String baseSQL =
						"SELECT U.user_id, U.name, U.email, U.phone, U.role, O.name AS organization_name "
						"FROM Users U "
						"LEFT JOIN Organizations O ON U.organization_id = O.organization_id";

		// Видаляємо будь-яке попереднє сортування
		int orderByPos = baseSQL.Pos("ORDER BY");
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// Якщо клікнули по тій самій колонці, змінюємо напрямок сортування
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // Зміна напрямку сортування
		}
		else
		{
			// Якщо колонка нова, завжди сортуємо за зростанням
			sortAscending = true;
		}

		// Запам'ятовуємо поточну колонку
		lastSortedColumn = columnName;

		// Формуємо запит з новим сортуванням
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


					// К-ка показати ззапити
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowRequestsClick(TObject *Sender)
{
	LoadRequests();
}

					// Загрузка Запитів
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadRequests()
{
	DBGridUsers->Visible = false;
	DBGridContributions->Visible = false;
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

					// При закриті форми
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(DataModule1->GetChangeUserState() == false){
	Action = caFree;   // Звільняє пам'ять після закриття
	Application->Terminate();  // Завершує застосунок
	}

}

					// Вибір фільтра
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckListBoxChouseClickCheck(TObject *Sender)
{
	int selectedIndex = CheckListBoxChouse->ItemIndex;

	// Проходимо по всіх елементах CheckListBox
	for (int i = 0; i < CheckListBoxChouse->Count; i++) {
		// Якщо це не вибраний елемент, скидаємо вибір
		if (i != selectedIndex) {
			CheckListBoxChouse->Checked[i] = false;
		}
	}

	// Якщо вибрано "Volonters", робимо GroupBoxContributions активним
	if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Внески") {
		GroupBoxContributions->Enabled = true;  // Активуємо
	} else {
		GroupBoxContributions->Enabled = false;  // Вимикаємо
	}

    if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Запити") {
		GroupBoxRequests->Enabled = true;  // Активуємо
	} else {
		GroupBoxRequests->Enabled = false;  // Вимикаємо
	}


	// Якщо нічого не вибрано, не дозволяємо зняти прапорець із самого себе
	if (CheckListBoxChouse->Checked[selectedIndex] == false) {
		CheckListBoxChouse->Checked[selectedIndex] = true;
	}
}

					// Загрузка історії
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadContributions() {
	DBGridContributions->Visible = true;
	DBGridUsers->Visible = false;
	DBGridRequests->Visible = false;
	// Переконайтеся, що з'єднання до бази даних активне
	if (!DataModule1->FDConnection1->Connected) {
		DataModule1->ConnectToDatabase();
	}

	try {
		// Закриваємо попередній запит перед відкриттям нового
		DataModule1->FDQuery1->Close();

		// Запит для отримання даних з таблиці Contributions разом із зв'язками на Users та MilitaryRequests
		DataModule1->FDQuery1->SQL->Text =
											"SELECT C.contribution_id, U.name AS volunteer_name, "
											"DM.drone_name, DM.drone_type, "
											"MR.quantity AS requested_quantity, C.quantity AS contributed_quantity, "
											"MR.request_date, C.contribution_date "
											"FROM Contributions C "
											"JOIN Users U ON C.user_id = U.user_id "
											"JOIN MilitaryRequests MR ON C.request_id = MR.request_id "
											"JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
											"ORDER BY C.contribution_date DESC";


		// Виконуємо запит
		DataModule1->FDQuery1->Open();

		// Прив'язуємо результати до DataSource і DBGrid
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridContributions->DataSource = DataModule1->DataSource1;

		// Налаштування стилів колонок для DBGrid
		SetDBGridColumnsStylesContributions();
	}
	catch (const Exception &e) {
		// У разі помилки показуємо повідомлення
		ShowMessage("Помилка при отриманні даних про внески: " + e.Message);
	}
}

					// Стиль для таблиці
 //---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesContributions() {
	int gridWidth = DBGridContributions->ClientWidth; // Ширина таблиці

	// Пропорції для колонок
	float coefColumn1 = 0.1;  // Ідентифікатор внеску
	float coefColumn2 = 0.2;  // Ім'я волонтера
	float coefColumn3 = 0.15;  // Назва дрону
	float coefColumn4 = 0.15;  // Тип дрону
	float coefColumn5 = 0.1;   // Запитана кількість
	float coefColumn6 = 0.1;   // Внесена кількість
	float coefColumn7 = 0.1;   // Дата запиту
	float coefColumn8 = 0.1;   // Дата внеску

	// Встановлення ширини колонок
	DBGridContributions->Columns->Items[0]->Width = gridWidth * coefColumn1;
	DBGridContributions->Columns->Items[0]->Title->Caption = "ID Внеску";

	DBGridContributions->Columns->Items[1]->Width = gridWidth * coefColumn2;
	DBGridContributions->Columns->Items[1]->Title->Caption = "Волонтер";
	DBGridContributions->Columns->Items[1]->Alignment = taCenter;

	DBGridContributions->Columns->Items[2]->Width = gridWidth * coefColumn3;
	DBGridContributions->Columns->Items[2]->Title->Caption = "Назва дрону";

	DBGridContributions->Columns->Items[3]->Width = gridWidth * coefColumn4;
	DBGridContributions->Columns->Items[3]->Title->Caption = "Тип дрону";

	DBGridContributions->Columns->Items[4]->Width = gridWidth * coefColumn5;
	DBGridContributions->Columns->Items[4]->Title->Caption = "Запитана к-ть";

	DBGridContributions->Columns->Items[5]->Width = gridWidth * coefColumn6;
	DBGridContributions->Columns->Items[5]->Title->Caption = "Внесена к-ть";

	DBGridContributions->Columns->Items[6]->Width = gridWidth * coefColumn7;
	DBGridContributions->Columns->Items[6]->Title->Caption = "Дата запиту";

	DBGridContributions->Columns->Items[7]->Width = gridWidth * coefColumn8;
	DBGridContributions->Columns->Items[7]->Title->Caption = "Дата внеску";

	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
	DataModule1->FDQuery1->FieldByName("contribution_date")->OnGetText = DateFieldGetText;
}

					// Кнопка показу
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowContributionsClick(TObject *Sender)
{
	LoadContributions();
}

					// Тикать на таблицю сортування
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridContributionsTitleClick(TColumn *Column)
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
		SetDBGridColumnsStylesContributions();  // Оновлюємо стилі колонок
	}
}

					// Заповлення боксів
//---------------------------------------------------------------------------
void __fastcall TForm2::FillRequestsBox(){
   DataModule1->FDQuery1->Close();

   // Заповнення ComboBox для типу дрону
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_type FROM DroneModel";
   DataModule1->FDQuery1->Open();
   ComboBoxDroneType->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxDroneType->Items->Add(DataModule1->FDQuery1->FieldByName("drone_type")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // Очищення і закриття запиту після заповнення ComboBox
   DataModule1->FDQuery1->Close();

   // Заповнення ComboBox для назви дрону
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_name FROM DroneModel";
   DataModule1->FDQuery1->Open();
   ComboBoxDroneName->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxDroneName->Items->Add(DataModule1->FDQuery1->FieldByName("drone_name")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // Очищення і закриття запиту після заповнення ComboBox
   DataModule1->FDQuery1->Close();

   // Заповнення ComboBox для статусу запиту
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT status FROM MilitaryRequests";
   DataModule1->FDQuery1->Open();
   ComboBoxStatus->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxStatus->Items->Add(DataModule1->FDQuery1->FieldByName("status")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // Закриття запиту після останнього заповнення
   DataModule1->FDQuery1->Close();
}

					// заповнення боксів
//---------------------------------------------------------------------------
void __fastcall TForm2::FillContributionsBox(){
	DataModule1->FDQuery1->Close();
	// Заповнення ComboBox для типу дрону
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT name FROM Users";
	DataModule1->FDQuery1->Open();
	ComboBoxUserName->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxUserName->Items->Add(DataModule1->FDQuery1->FieldByName("name")->AsString);
		DataModule1->FDQuery1->Next();
	}

		// Заповнення ComboBox для назви дрону
	DataModule1->FDQuery1->Close();
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT name FROM Organizations";
	DataModule1->FDQuery1->Open();
	ComboBoxOrg->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxOrg->Items->Add(DataModule1->FDQuery1->FieldByName("name")->AsString);
		DataModule1->FDQuery1->Next();
	}

	DataModule1->FDQuery1->Close();
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_name FROM DroneModel";
	DataModule1->FDQuery1->Open();
	ComboBoxDroName->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxDroName->Items->Add(DataModule1->FDQuery1->FieldByName("drone_name")->AsString);
		DataModule1->FDQuery1->Next();
	}

	DataModule1->FDQuery1->Close();
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_type FROM DroneModel";
	DataModule1->FDQuery1->Open();
	ComboBoxDroType->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxDroType->Items->Add(DataModule1->FDQuery1->FieldByName("drone_type")->AsString);
		DataModule1->FDQuery1->Next();
	}
}

					// Фільтрація за параметрами
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonFilterClick(TObject *Sender)
{
	int selectedIndex = CheckListBoxChouse->ItemIndex;
	TDateTime startDate = DateTimePickerRequestsStart->Date;
	TDateTime endDate = DateTimePickerRequestsEnd->Date;
	if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Requests") {
		LoadContributions();
		String baseSQL =
			"SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
			"FROM MilitaryRequests MR "
			"JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
			"WHERE MR.request_date BETWEEN :startDate AND :endDate";

		if (ComboBoxDroneName->Text != "")
		{
			baseSQL += " AND DM.drone_name LIKE :dronename";
		}

		if (ComboBoxDroneType->Text != "")
		{
			baseSQL += " AND DM.drone_type LIKE :dronetype";
		}

		if (ComboBoxStatus->Text != "")
		{
			baseSQL += " AND MR.status LIKE :status";
		}

		DataModule1->FDQuery1->Close();
		DataModule1->FDQuery1->SQL->Text = baseSQL;
		DataModule1->FDQuery1->ParamByName("startDate")->AsDate = startDate;
		DataModule1->FDQuery1->ParamByName("endDate")->AsDate = endDate;

		if (ComboBoxDroneName->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("dronename")->AsString = ComboBoxDroneName->Text + "%";
		}

		if (ComboBoxDroneType->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("dronetype")->AsString = ComboBoxDroneType->Text + "%";
		}

		if (ComboBoxStatus->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("status")->AsString = ComboBoxStatus->Text + "%";
		}

		try {
			DataModule1->FDQuery1->Open();

			if (DataModule1->FDQuery1->RecordCount == 0) {
				ShowMessage("Фільтр не дав результатів.");
			} else {
				DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
				DBGridRequests->DataSource = DataModule1->DataSource1;
				SetDBGridColumnsStylesRequests();
				ShowMessage("Filtered successfully");
			}
		} catch (Exception &e) {
			ShowMessage("Помилка при фільтрації: " + e.Message);
		}
	} else if(CheckListBoxChouse->Items->Strings[selectedIndex] == "Contributions") {
		LoadRequests();

		String baseSQL = 	 "SELECT C.contribution_id, U.name AS volunteer_name, "
							 "DM.drone_name, DM.drone_type, "
							 "MR.quantity AS requested_quantity, C.quantity AS contributed_quantity, "
							 "MR.request_date, C.contribution_date "
							 "FROM Contributions C "
							 "JOIN Users U ON C.user_id = U.user_id "
							 "JOIN MilitaryRequests MR ON C.request_id = MR.request_id "
							 "JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
							 "WHERE MR.request_date BETWEEN :startDate AND :endDate";


		if (ComboBoxUserName->Text != "")
		{
			 baseSQL += " AND U.name LIKE :username";
		}

		if (ComboBoxOrg->Text != "")
		{
			 baseSQL += " AND O.name LIKE :organization";
		}

		if (ComboBoxDroName->Text != "")
		{
			 baseSQL += " AND DM.drone_name LIKE :drone_name";
		}

		if(ComboBoxDroType->Text != "")
		{
			 baseSQL += " AND DM.drone_type LIKE :drone_type";
		}
		DataModule1->FDQuery1->Close();
		DataModule1->FDQuery1->SQL->Text = baseSQL;
		DataModule1->FDQuery1->ParamByName("startDate")->AsDate = startDate;
		DataModule1->FDQuery1->ParamByName("endDate")->AsDate = endDate;

		if (ComboBoxUserName->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("username")->AsString = ComboBoxUserName->Text + "%";
		}

		if (ComboBoxOrg->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("organization")->AsString = ComboBoxOrg->Text + "%";
		}

		if (ComboBoxDroName->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("drone_name")->AsString = ComboBoxDroName->Text + "%";
		}

			if (ComboBoxDroType->Text != "")
		{
			DataModule1->FDQuery1->ParamByName("drone_type")->AsString = ComboBoxDroType->Text + "%";
		}

		try {
			DataModule1->FDQuery1->Open();

			if (DataModule1->FDQuery1->RecordCount == 0) {
				ShowMessage("Фільтр не дав результатів.");
			} else {
				DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
				DBGridContributions->DataSource = DataModule1->DataSource1;
				SetDBGridColumnsStylesContributions();
				ShowMessage("Filtered successfully");
			}
		} catch (Exception &e) {
			ShowMessage("Помилка при фільтрації: " + e.Message);
		}
	}
}

					// Скидання фільтрів
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClearFilterClick(TObject *Sender)
{
	int selectedIndex = CheckListBoxChouse->ItemIndex;
	if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Contributions") {
		LoadContributions(); // Активуємо
	} else if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Requests") {
		LoadRequests();
	}
}

					// Додати користувача
//---------------------------------------------------------------------------
void __fastcall TForm2::AddUserClick(TObject *Sender)
{
	TForm6 *AddUser = new TForm6(this);
	AddUser->Show();
	this->Hide();
}

					// Додати організацію
//---------------------------------------------------------------------------
void __fastcall TForm2::AddOrgClick(TObject *Sender)
{
	TForm9 *AddOrg = new TForm9(this);
	AddOrg->Show();
	this->Hide();
}

					// Видалити користувача
//---------------------------------------------------------------------------
void __fastcall TForm2::DeleteUserClick(TObject *Sender)
{
	// Перевіряємо, чи є вибраний рядок у таблиці
	if (DBGridUsers->DataSource->DataSet->RecordCount == 0) {
		ShowMessage("Немає вибраного користувача для видалення.");
		return;
	}

	// Отримуємо значення user_id вибраного користувача
	int userID = DataModule1->FDQuery1->FieldByName("user_id")->AsInteger;
	String userName = DataModule1->FDQuery1->FieldByName("name")->AsString;

	// Питаємо користувача, чи дійсно він хоче видалити користувача
	String confirmationMessage = "Ви дійсно хочете видалити користувача: " + userName + "?";
	if (MessageDlg(confirmationMessage, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		try
		{
			// Перевірка підключення до бази даних
			if (!DataModule1->FDConnection1->Connected)
			{
				DataModule1->ConnectToDatabase();
				if (!DataModule1->FDConnection1->Connected)
				{
					throw Exception("Не вдалося підключитися до бази даних.");
				}
			}

			// Використовуємо транзакцію для безпечного видалення
			DataModule1->FDConnection1->StartTransaction();

			// Видаляємо користувача з таблиці UserCredentials
			std::unique_ptr<TFDQuery> deleteUserCredentialsQuery(new TFDQuery(NULL));
			deleteUserCredentialsQuery->Connection = DataModule1->FDConnection1;
			deleteUserCredentialsQuery->SQL->Text = "DELETE FROM UserCredentials WHERE user_id = :user_id";
			deleteUserCredentialsQuery->ParamByName("user_id")->AsInteger = userID;
			deleteUserCredentialsQuery->ExecSQL();

			// Видаляємо користувача з таблиці Users
			std::unique_ptr<TFDQuery> deleteUserQuery(new TFDQuery(NULL));
			deleteUserQuery->Connection = DataModule1->FDConnection1;
			deleteUserQuery->SQL->Text = "DELETE FROM Users WHERE user_id = :user_id";
			deleteUserQuery->ParamByName("user_id")->AsInteger = userID;
			deleteUserQuery->ExecSQL();

			// Підтверджуємо зміни
			DataModule1->FDConnection1->Commit();

			ShowMessage("Користувача успішно видалено.");

			// Оновлюємо таблицю користувачів
			DataModule1->FDQuery1->Close();
			DataModule1->FDQuery1->Open();
			SetDBGridColumnsStylesUsers();
		}
		catch (Exception &e)
		{
			DataModule1->FDConnection1->Rollback();
			ShowMessage("Помилка при видаленні користувача: " + e.Message);
		}
	}
}

					// Змінити дані користувача
//---------------------------------------------------------------------------
void __fastcall TForm2::ChangeUserDataClick(TObject *Sender)
{
	if (DBGridUsers->DataSource->DataSet->RecordCount == 0) {
		ShowMessage("Немає вибраного користувача для видалення.");
		return;
	}
	int userID = DataModule1->FDQuery1->FieldByName("user_id")->AsInteger;
    try
		{
		   TForm8 *ProfileForm = new TForm8(this, userID);
			ProfileForm->Show();
			this->Hide();
		}
		catch (Exception &e)
		{
			ShowMessage("Помилка при відкритті профіля користувача: " + e.Message);
		}
}

					// При показі форми
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	FillRequestsBox();
	FillContributionsBox();
	// Налаштування значень за замовчуванням для DateTimePickers
	DateTimePickerRequestsStart->Date = EncodeDate(2024, 1, 1);  // Початок року 2024
	DateTimePickerRequestsEnd->Date = Now();  // Теперішня дата

}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridRequestsTitleClick(TColumn *Column)
{
	// Ім'я поля, за яким відбудеться сортування
	static String lastSortedColumn = "";  // Остання відсортована колонка
	static bool sortAscending = true;     // Прапор для напрямку сортування

	String columnName = Column->FieldName;

	// Перевірка, чи є активний DataSet, і чи підтримує він SQL
	if (DataModule1->DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet);

		// Базовий SQL-запит
		String baseSQL =
			"SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
			"FROM MilitaryRequests MR "
			"JOIN DroneModel DM ON MR.drone_id = DM.drone_id";

		// Видаляємо будь-яке попереднє сортування
		int orderByPos = baseSQL.Pos("ORDER BY");
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// Якщо клікаємо по тій самій колонці, змінюємо напрямок сортування
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // Міняємо напрямок сортування
		}
		else
		{
			// Якщо колонка нова, починаємо сортування за зростанням
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
		SetDBGridColumnsStylesRequests();  // Оновлюємо стилі колонок для запитів
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AddRequestsClick(TObject *Sender)
{
	TForm5 *AddOrderForm = new TForm5(this);
	AddOrderForm->Show();
	this->Hide();
}
//---------------------------------------------------------------------------


