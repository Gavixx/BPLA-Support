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
const String monthNames[12] = {"ѳ���", "������", "�������", "�����", "������", "������",
							   "�����", "������", "�������", "������", "���������", "������"};
//---------------------------------------------------------------------------

__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}

					// ����� ��� ������� �����
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesUsers()
{
	int gridWidth = DBGridUsers->ClientWidth; // �������� ������ �������
	int totalFixedWidth = 0; // �������� ������ ��� �������

	// �������� ������������ ��������� ������ ��� ��� ������� � ������ �������� ������
	for (int i = 0; i < DBGridUsers->Columns->Count; i++) {
		if (i == 0) {
			DBGridUsers->Columns->Items[i]->Visible = false; // ������� user_id
		} else {
			DBGridUsers->Columns->Items[i]->Width = gridWidth / (DBGridUsers->Columns->Count - 1); // ���������� �������� ������
			totalFixedWidth += DBGridUsers->Columns->Items[i]->Width;
		}
	}

	// ���������� �������������� ������ � ������ ���� �� ����� �������
	int remainingWidth = gridWidth - totalFixedWidth;
	int extraWidthPerColumn = remainingWidth / (DBGridUsers->Columns->Count - 1);

	for (int i = 1; i < DBGridUsers->Columns->Count; i++) {
		DBGridUsers->Columns->Items[i]->Width += extraWidthPerColumn; // ������ ��������� ������ �� ����� �������
	}

	// ������ ������������ ��������� � ����������� ��� ����� �������
	DBGridUsers->Columns->Items[1]->Title->Caption = "ϲ�";
	DBGridUsers->Columns->Items[1]->Title->Alignment = taCenter;

	DBGridUsers->Columns->Items[2]->Title->Caption = "�����";
	DBGridUsers->Columns->Items[2]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[2]->Alignment = taCenter;

	DBGridUsers->Columns->Items[3]->Title->Caption = "�������";
	DBGridUsers->Columns->Items[3]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[3]->Alignment = taCenter;

	DBGridUsers->Columns->Items[4]->Title->Caption = "����";
	DBGridUsers->Columns->Items[4]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[4]->Alignment = taCenter;

	DBGridUsers->Columns->Items[5]->Title->Caption = "����������";
	DBGridUsers->Columns->Items[5]->Title->Alignment = taCenter;
	DBGridUsers->Columns->Items[5]->Alignment = taCenter;

	// � ��� ���� ���� � �����, ���� �������� ��� ����������� ���� �� �������

}

					// ����� ��� ������� ������
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesRequests(){
	int gridWidth = DBGridRequests->ClientWidth; // ������ �������

	// ��������� ��� �������
	float coefColumn1 = 0.2;  // ����� �����
	float coefColumn2 = 0.15; // ��� �����
	float coefColumn3 = 0.1;  // ������� �������
	float coefColumn4 = 0.2;  // ���� ������ ������
	float coefColumn5 = 0.2;  // ������
	float coefColumn6 = 0.15; // �������� �����

	// ������������ ������ ����� ������� ������� ������ �������
	DBGridRequests->Columns->Items[0]->Width = gridWidth * coefColumn1;
	DBGridRequests->Columns->Items[0]->Title->Caption = "����� �����";
	DBGridRequests->Columns->Items[0]->Title->Alignment = taCenter;

	DBGridRequests->Columns->Items[1]->Width = gridWidth * coefColumn2;
	DBGridRequests->Columns->Items[1]->Title->Caption = "��� �����";
	DBGridRequests->Columns->Items[1]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[1]->Alignment = taCenter;

	DBGridRequests->Columns->Items[2]->Width = gridWidth * coefColumn3;
	DBGridRequests->Columns->Items[2]->Title->Caption = "������� �-��";
	DBGridRequests->Columns->Items[2]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[2]->Alignment = taCenter;

	DBGridRequests->Columns->Items[3]->Width = gridWidth * coefColumn4;
	DBGridRequests->Columns->Items[3]->Title->Caption = "���� ������ ������";
	DBGridRequests->Columns->Items[3]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[3]->Alignment = taCenter;

	DBGridRequests->Columns->Items[4]->Width = gridWidth * coefColumn5;
	DBGridRequests->Columns->Items[4]->Title->Caption = "������";
	DBGridRequests->Columns->Items[4]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[4]->Alignment = taCenter;

	DBGridRequests->Columns->Items[5]->Width = gridWidth * coefColumn6;
	DBGridRequests->Columns->Items[5]->Title->Caption = "�������� �����";
	DBGridRequests->Columns->Items[5]->Title->Alignment = taCenter;
	DBGridRequests->Columns->Items[5]->Alignment = taCenter;

	// �������� ��� ����������� ����
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
}

					// �-� ��� ����������� �������� ���
//---------------------------------------------------------------------------
void __fastcall TForm2::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

	int day = DayOf(requestDate);   // �������� ���� � ����
	int month = MonthOf(requestDate);  // �������� ����� � ����

	// ������� ������������� ����
	Text = IntToStr(day) + " " + monthNames[month - 1];
}

					// ������ �������� ������������
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowUsersClick(TObject *Sender)
{
	LoadUsers();
}

					// �������� ����� � �� � �������
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadUsers(){
	DBGridContributions->Visible = false;
	DBGridUsers->Visible = true;
	DBGridRequests->Visible = false;

	try {
		DataModule1->ConnectToDatabase();  // ϳ��������� �� ���� ����� DataModule1

		// ������������ ������ ����� DataModule1
		DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;

		// SQL-����� ��� ��������� ����� ������������ � ������� Users � ���������� �� ����������
		DataModule1->FDQuery1->SQL->Text =
			"SELECT U.user_id, U.name, U.email, U.phone, U.role, O.name AS organization_name "
			"FROM Users U "
			"LEFT JOIN Organizations O ON U.organization_id = O.organization_id";  // ��������� ����������

		DataModule1->FDQuery1->Open();  // ������ ����� �� ������� ����������

		// ����'���� �����
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridUsers->DataSource = DataModule1->DataSource1;
		SetDBGridColumnsStylesUsers();  // ������������ ���� ������� ��� ������������
	} catch (const Exception &e) {
		ShowMessage("������� ��� �������� �����: " + e.Message);
	}
}

					// ��� ���������� ��� �������� �� ������� � ������� ����������
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridUsersTitleClick(TColumn *Column)
{
	// ��'� ����, �� ���� ���������� ����������
	static String lastSortedColumn = "";  // ������� ����������� �������
	static bool sortAscending = true;     // ������ ��� �������� ����������

	String columnName = Column->FieldName;

	// ��������, �� � �������� DataSet, � �� ������� �� SQL
	if (DataModule1->DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet);

		// ������� SQL-����� ��� ������������ � ������������
		String baseSQL =
						"SELECT U.user_id, U.name, U.email, U.phone, U.role, O.name AS organization_name "
						"FROM Users U "
						"LEFT JOIN Organizations O ON U.organization_id = O.organization_id";

		// ��������� ����-��� �������� ����������
		int orderByPos = baseSQL.Pos("ORDER BY");
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// ���� ������� �� �� ���� �������, ������� �������� ����������
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // ���� �������� ����������
		}
		else
		{
			// ���� ������� ����, ������ ������� �� ����������
			sortAscending = true;
		}

		// �����'������� ������� �������
		lastSortedColumn = columnName;

		// ������� ����� � ����� �����������
		String sortDirection = sortAscending ? "ASC" : "DESC";
		baseSQL += " ORDER BY " + columnName + " " + sortDirection;

		// ��������� ����� � ��������������� ���
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();

		// ����'���� ���������� ������ �� DataSource
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		SetDBGridColumnsStylesUsers();  // ��������� ���� �������
	}
}


					// �-�� �������� �������
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowRequestsClick(TObject *Sender)
{
	LoadRequests();
}

					// �������� ������
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadRequests()
{
	DBGridUsers->Visible = false;
	DBGridContributions->Visible = false;
	DBGridRequests->Visible = true;
	DataModule1->ConnectToDatabase();	  // �������������, �� �'������� � ����� ����� �������

	// ������������ ������
	DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
	DataModule1->FDQuery1->SQL->Text = "SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
						   "FROM MilitaryRequests MR "
						   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id";
	DataModule1->FDQuery1->Open();  // ������ ����� �� ������� ����������

	// ����'���� �����
	DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
	DBGridRequests->DataSource = DataModule1->DataSource1;
	SetDBGridColumnsStylesRequests();
}

					// ��� ������ �����
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(DataModule1->GetChangeUserState() == false){
	Action = caFree;   // ������� ���'��� ���� ��������
	Application->Terminate();  // ������� ����������
	}

}

					// ���� �������
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckListBoxChouseClickCheck(TObject *Sender)
{
	int selectedIndex = CheckListBoxChouse->ItemIndex;

	// ��������� �� ��� ��������� CheckListBox
	for (int i = 0; i < CheckListBoxChouse->Count; i++) {
		// ���� �� �� �������� �������, ������� ����
		if (i != selectedIndex) {
			CheckListBoxChouse->Checked[i] = false;
		}
	}

	// ���� ������� "Volonters", ������ GroupBoxContributions ��������
	if (CheckListBoxChouse->Items->Strings[selectedIndex] == "������") {
		GroupBoxContributions->Enabled = true;  // ��������
	} else {
		GroupBoxContributions->Enabled = false;  // ��������
	}

    if (CheckListBoxChouse->Items->Strings[selectedIndex] == "������") {
		GroupBoxRequests->Enabled = true;  // ��������
	} else {
		GroupBoxRequests->Enabled = false;  // ��������
	}


	// ���� ����� �� �������, �� ���������� ����� ��������� �� ������ ����
	if (CheckListBoxChouse->Checked[selectedIndex] == false) {
		CheckListBoxChouse->Checked[selectedIndex] = true;
	}
}

					// �������� �����
//---------------------------------------------------------------------------
void __fastcall TForm2::LoadContributions() {
	DBGridContributions->Visible = true;
	DBGridUsers->Visible = false;
	DBGridRequests->Visible = false;
	// �������������, �� �'������� �� ���� ����� �������
	if (!DataModule1->FDConnection1->Connected) {
		DataModule1->ConnectToDatabase();
	}

	try {
		// ��������� ��������� ����� ����� ��������� ������
		DataModule1->FDQuery1->Close();

		// ����� ��� ��������� ����� � ������� Contributions ����� �� ��'������ �� Users �� MilitaryRequests
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


		// �������� �����
		DataModule1->FDQuery1->Open();

		// ����'����� ���������� �� DataSource � DBGrid
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridContributions->DataSource = DataModule1->DataSource1;

		// ������������ ����� ������� ��� DBGrid
		SetDBGridColumnsStylesContributions();
	}
	catch (const Exception &e) {
		// � ��� ������� �������� �����������
		ShowMessage("������� ��� �������� ����� ��� ������: " + e.Message);
	}
}

					// ����� ��� �������
 //---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesContributions() {
	int gridWidth = DBGridContributions->ClientWidth; // ������ �������

	// ��������� ��� �������
	float coefColumn1 = 0.1;  // ������������� ������
	float coefColumn2 = 0.2;  // ��'� ���������
	float coefColumn3 = 0.15;  // ����� �����
	float coefColumn4 = 0.15;  // ��� �����
	float coefColumn5 = 0.1;   // �������� �������
	float coefColumn6 = 0.1;   // ������� �������
	float coefColumn7 = 0.1;   // ���� ������
	float coefColumn8 = 0.1;   // ���� ������

	// ������������ ������ �������
	DBGridContributions->Columns->Items[0]->Width = gridWidth * coefColumn1;
	DBGridContributions->Columns->Items[0]->Title->Caption = "ID ������";

	DBGridContributions->Columns->Items[1]->Width = gridWidth * coefColumn2;
	DBGridContributions->Columns->Items[1]->Title->Caption = "��������";
	DBGridContributions->Columns->Items[1]->Alignment = taCenter;

	DBGridContributions->Columns->Items[2]->Width = gridWidth * coefColumn3;
	DBGridContributions->Columns->Items[2]->Title->Caption = "����� �����";

	DBGridContributions->Columns->Items[3]->Width = gridWidth * coefColumn4;
	DBGridContributions->Columns->Items[3]->Title->Caption = "��� �����";

	DBGridContributions->Columns->Items[4]->Width = gridWidth * coefColumn5;
	DBGridContributions->Columns->Items[4]->Title->Caption = "�������� �-��";

	DBGridContributions->Columns->Items[5]->Width = gridWidth * coefColumn6;
	DBGridContributions->Columns->Items[5]->Title->Caption = "������� �-��";

	DBGridContributions->Columns->Items[6]->Width = gridWidth * coefColumn7;
	DBGridContributions->Columns->Items[6]->Title->Caption = "���� ������";

	DBGridContributions->Columns->Items[7]->Width = gridWidth * coefColumn8;
	DBGridContributions->Columns->Items[7]->Title->Caption = "���� ������";

	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
	DataModule1->FDQuery1->FieldByName("contribution_date")->OnGetText = DateFieldGetText;
}

					// ������ ������
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonShowContributionsClick(TObject *Sender)
{
	LoadContributions();
}

					// ������ �� ������� ����������
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridContributionsTitleClick(TColumn *Column)
{
	// ��'� ����, �� ���� ���������� ����������
	static String lastSortedColumn = "";  // ������� ����������� �������
	static bool sortAscending = true;     // ������ ��� �������� ����������

	String columnName = Column->FieldName;

	// ��������, �� � �������� DataSet, � �� ������� �� SQL
	if (DataModule1->DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet);

		// �������� �������� SQL �����
		String baseSQL = query->SQL->Text;

		// �������� ������ ��� ������� "ORDER BY"
		int orderByPos = baseSQL.Pos("ORDER BY");
		// ���� "ORDER BY" ��� ����, ��������� ����
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// ���� ������ �� �� ���� �������, ������� �������� ����������
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // ̳����� ������
		}
		else
		{
			// ���� ���� �������, ������ �������� � ���������� �� ����������
			sortAscending = true;
		}

		// �������� ������� ������� �� ������� �����������
		lastSortedColumn = columnName;

		// ������� ����� �� ����� �����������
		String sortDirection = sortAscending ? "ASC" : "DESC";
		baseSQL += " ORDER BY " + columnName + " " + sortDirection;

		// ��������� ����� � ��������������� ���
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();

		// ����'���� ���������� ������ �� DataSource
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		SetDBGridColumnsStylesContributions();  // ��������� ���� �������
	}
}

					// ���������� �����
//---------------------------------------------------------------------------
void __fastcall TForm2::FillRequestsBox(){
   DataModule1->FDQuery1->Close();

   // ���������� ComboBox ��� ���� �����
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_type FROM DroneModel";
   DataModule1->FDQuery1->Open();
   ComboBoxDroneType->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxDroneType->Items->Add(DataModule1->FDQuery1->FieldByName("drone_type")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // �������� � �������� ������ ���� ���������� ComboBox
   DataModule1->FDQuery1->Close();

   // ���������� ComboBox ��� ����� �����
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_name FROM DroneModel";
   DataModule1->FDQuery1->Open();
   ComboBoxDroneName->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxDroneName->Items->Add(DataModule1->FDQuery1->FieldByName("drone_name")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // �������� � �������� ������ ���� ���������� ComboBox
   DataModule1->FDQuery1->Close();

   // ���������� ComboBox ��� ������� ������
   DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT status FROM MilitaryRequests";
   DataModule1->FDQuery1->Open();
   ComboBoxStatus->Items->Clear();
   while (!DataModule1->FDQuery1->Eof) {
	  ComboBoxStatus->Items->Add(DataModule1->FDQuery1->FieldByName("status")->AsString);
	  DataModule1->FDQuery1->Next();
   }

   // �������� ������ ���� ���������� ����������
   DataModule1->FDQuery1->Close();
}

					// ���������� �����
//---------------------------------------------------------------------------
void __fastcall TForm2::FillContributionsBox(){
	DataModule1->FDQuery1->Close();
	// ���������� ComboBox ��� ���� �����
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT name FROM Users";
	DataModule1->FDQuery1->Open();
	ComboBoxUserName->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxUserName->Items->Add(DataModule1->FDQuery1->FieldByName("name")->AsString);
		DataModule1->FDQuery1->Next();
	}

		// ���������� ComboBox ��� ����� �����
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

					// Գ�������� �� �����������
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
				ShowMessage("Գ���� �� ��� ����������.");
			} else {
				DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
				DBGridRequests->DataSource = DataModule1->DataSource1;
				SetDBGridColumnsStylesRequests();
				ShowMessage("Filtered successfully");
			}
		} catch (Exception &e) {
			ShowMessage("������� ��� ����������: " + e.Message);
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
				ShowMessage("Գ���� �� ��� ����������.");
			} else {
				DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
				DBGridContributions->DataSource = DataModule1->DataSource1;
				SetDBGridColumnsStylesContributions();
				ShowMessage("Filtered successfully");
			}
		} catch (Exception &e) {
			ShowMessage("������� ��� ����������: " + e.Message);
		}
	}
}

					// �������� �������
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonClearFilterClick(TObject *Sender)
{
	int selectedIndex = CheckListBoxChouse->ItemIndex;
	if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Contributions") {
		LoadContributions(); // ��������
	} else if (CheckListBoxChouse->Items->Strings[selectedIndex] == "Requests") {
		LoadRequests();
	}
}

					// ������ �����������
//---------------------------------------------------------------------------
void __fastcall TForm2::AddUserClick(TObject *Sender)
{
	TForm6 *AddUser = new TForm6(this);
	AddUser->Show();
	this->Hide();
}

					// ������ ����������
//---------------------------------------------------------------------------
void __fastcall TForm2::AddOrgClick(TObject *Sender)
{
	TForm9 *AddOrg = new TForm9(this);
	AddOrg->Show();
	this->Hide();
}

					// �������� �����������
//---------------------------------------------------------------------------
void __fastcall TForm2::DeleteUserClick(TObject *Sender)
{
	// ����������, �� � �������� ����� � �������
	if (DBGridUsers->DataSource->DataSet->RecordCount == 0) {
		ShowMessage("���� ��������� ����������� ��� ���������.");
		return;
	}

	// �������� �������� user_id ��������� �����������
	int userID = DataModule1->FDQuery1->FieldByName("user_id")->AsInteger;
	String userName = DataModule1->FDQuery1->FieldByName("name")->AsString;

	// ������ �����������, �� ����� �� ���� �������� �����������
	String confirmationMessage = "�� ����� ������ �������� �����������: " + userName + "?";
	if (MessageDlg(confirmationMessage, mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		try
		{
			// �������� ���������� �� ���� �����
			if (!DataModule1->FDConnection1->Connected)
			{
				DataModule1->ConnectToDatabase();
				if (!DataModule1->FDConnection1->Connected)
				{
					throw Exception("�� ������� ����������� �� ���� �����.");
				}
			}

			// ������������� ���������� ��� ���������� ���������
			DataModule1->FDConnection1->StartTransaction();

			// ��������� ����������� � ������� UserCredentials
			std::unique_ptr<TFDQuery> deleteUserCredentialsQuery(new TFDQuery(NULL));
			deleteUserCredentialsQuery->Connection = DataModule1->FDConnection1;
			deleteUserCredentialsQuery->SQL->Text = "DELETE FROM UserCredentials WHERE user_id = :user_id";
			deleteUserCredentialsQuery->ParamByName("user_id")->AsInteger = userID;
			deleteUserCredentialsQuery->ExecSQL();

			// ��������� ����������� � ������� Users
			std::unique_ptr<TFDQuery> deleteUserQuery(new TFDQuery(NULL));
			deleteUserQuery->Connection = DataModule1->FDConnection1;
			deleteUserQuery->SQL->Text = "DELETE FROM Users WHERE user_id = :user_id";
			deleteUserQuery->ParamByName("user_id")->AsInteger = userID;
			deleteUserQuery->ExecSQL();

			// ϳ���������� ����
			DataModule1->FDConnection1->Commit();

			ShowMessage("����������� ������ ��������.");

			// ��������� ������� ������������
			DataModule1->FDQuery1->Close();
			DataModule1->FDQuery1->Open();
			SetDBGridColumnsStylesUsers();
		}
		catch (Exception &e)
		{
			DataModule1->FDConnection1->Rollback();
			ShowMessage("������� ��� �������� �����������: " + e.Message);
		}
	}
}

					// ������ ��� �����������
//---------------------------------------------------------------------------
void __fastcall TForm2::ChangeUserDataClick(TObject *Sender)
{
	if (DBGridUsers->DataSource->DataSet->RecordCount == 0) {
		ShowMessage("���� ��������� ����������� ��� ���������.");
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
			ShowMessage("������� ��� ������� ������� �����������: " + e.Message);
		}
}

					// ��� ����� �����
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
	FillRequestsBox();
	FillContributionsBox();
	// ������������ ������� �� ������������� ��� DateTimePickers
	DateTimePickerRequestsStart->Date = EncodeDate(2024, 1, 1);  // ������� ���� 2024
	DateTimePickerRequestsEnd->Date = Now();  // �������� ����

}
//---------------------------------------------------------------------------
void __fastcall TForm2::DBGridRequestsTitleClick(TColumn *Column)
{
	// ��'� ����, �� ���� ���������� ����������
	static String lastSortedColumn = "";  // ������� ����������� �������
	static bool sortAscending = true;     // ������ ��� �������� ����������

	String columnName = Column->FieldName;

	// ��������, �� � �������� DataSet, � �� ������� �� SQL
	if (DataModule1->DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataModule1->DataSource1->DataSet);

		// ������� SQL-�����
		String baseSQL =
			"SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
			"FROM MilitaryRequests MR "
			"JOIN DroneModel DM ON MR.drone_id = DM.drone_id";

		// ��������� ����-��� �������� ����������
		int orderByPos = baseSQL.Pos("ORDER BY");
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// ���� ������ �� �� ���� �������, ������� �������� ����������
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // ̳����� �������� ����������
		}
		else
		{
			// ���� ������� ����, �������� ���������� �� ����������
			sortAscending = true;
		}

		// �������� ������� ������� �� ������� �����������
		lastSortedColumn = columnName;

		// ������� ����� �� ����� �����������
		String sortDirection = sortAscending ? "ASC" : "DESC";
		baseSQL += " ORDER BY " + columnName + " " + sortDirection;

		// ��������� ����� � ��������������� ���
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();

		// ����'���� ���������� ������ �� DataSource
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		SetDBGridColumnsStylesRequests();  // ��������� ���� ������� ��� ������
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


