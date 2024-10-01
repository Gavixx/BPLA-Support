//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ArmyForm.h"
#include "AddOrderForm.h"
#include "LoginForm.h"
#include "DataModule.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------

const String monthNames[12] = {"ѳ���", "������", "�������", "�����", "������", "������",
							   "�����", "������", "�������", "������", "���������", "������"};

//---------------------------------------------------------------------------

__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
	GetItemToFillBox();
	LoadDB();
	SetDBGridColumnsStyles();
	DateTimePickerEnd->Date = Now();
}

// ³���� ��� ���������� �������
//---------------------------------------------------------------------------

void __fastcall TForm3::SetDBGridColumnsStyles()
{
	int gridWidth = DBGrid1->ClientWidth; // ������ �񳺿 ��������

	// ����������, �� � ��������� �������
	if (DBGrid1->Columns->Count >= 6) {
		DBGrid1->Columns->Items[0]->Width = 386;
		DBGrid1->Columns->Items[0]->Title->Caption = "����� �����";
		DBGrid1->Columns->Items[0]->Title->Alignment = taCenter;

		DBGrid1->Columns->Items[1]->Width = 275;
		DBGrid1->Columns->Items[1]->Title->Caption = "��� �����";
		DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[1]->Alignment = taCenter;

		DBGrid1->Columns->Items[2]->Width = 231;
		DBGrid1->Columns->Items[2]->Title->Caption = "������� �-��";
		DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[2]->Alignment = taCenter;

		DBGrid1->Columns->Items[3]->Width = 231;
		DBGrid1->Columns->Items[3]->Title->Caption = "���� ������ ������";
		DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[3]->Alignment = taCenter;

		DBGrid1->Columns->Items[4]->Width = 231;
		DBGrid1->Columns->Items[4]->Title->Caption = "������";
		DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[4]->Alignment = taCenter;

		DBGrid1->Columns->Items[5]->Width = 154;
		DBGrid1->Columns->Items[5]->Title->Caption = "�������� ������";
		DBGrid1->Columns->Items[5]->Title->Alignment = taCenter;
		DBGrid1->Columns->Items[5]->Alignment = taCenter;

		// �������� ��� ����������� ����
		DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
	} else {
		ShowMessage("����������� ������� ��� ������������ ������.");
	}
}

// ��� ����������� � ������ "1 �������"
//---------------------------------------------------------------------------

void __fastcall TForm3::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

	int day = DayOf(requestDate);   // �������� ���� � ����
	int month = MonthOf(requestDate);  // �������� ����� � ����

	// ������� ������������� ����
	Text = IntToStr(day) + " " + monthNames[month - 1];
}

// ��� �� ���� �������
//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
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
		if (orderByPos > 0)
		{
			baseSQL = baseSQL.SubString(1, orderByPos - 1);
		}

		// ������� �������� ����������
		if (columnName == lastSortedColumn)
		{
			sortAscending = !sortAscending;  // ̳����� ������
		}
		else
		{
			sortAscending = true;
		}

		lastSortedColumn = columnName;
		String sortDirection = sortAscending ? "ASC" : "DESC";
		baseSQL += " ORDER BY " + columnName + " " + sortDirection;

		// ��������� ����� � ��������������� ����
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();

		DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;

		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		SetDBGridColumnsStyles();
	}
}

// ³������� ����� �� ��������� ������
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonAddOrderClick(TObject *Sender)
{
	TForm5 *AddOrderForm = new TForm5(this);
	AddOrderForm->Show();
	this->Hide();
}

// ������ ��� ��������� �������
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonShowStatClick(TObject *Sender)
{
	LoadDB();
}

// ������� ��� �������� ��
//---------------------------------------------------------------------------

void __fastcall TForm3::LoadDB()
{
    // �������������, �� �'������� �� ���� ����� �������
    if (!DataModule1->FDConnection1->Connected) {
        DataModule1->ConnectToDatabase();
    }

    // ��������� ���������� ����� ����� ��������� ������
    DataModule1->FDQuery1->Close();

    // ����������� ����� ����� DataModule1
    DataModule1->FDQuery1->SQL->Text = "SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
                                       "FROM MilitaryRequests MR "
                                       "JOIN DroneModel DM ON MR.drone_id = DM.drone_id";
    DataModule1->FDQuery1->Open();  // ������ ����� �� ������� ����������

    if (DataModule1->FDQuery1->RecordCount > 0) {
        // ����'���� ����� �� DataSource ����� DataModule1
        DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;

        // ����'���� DataSource �� DBGrid ����� DataModule1
        DBGrid1->DataSource = DataModule1->DataSource1;

        // ������������ ����� ������� DBGrid
        SetDBGridColumnsStyles();
    } else {
        ShowMessage("���� ����� ��� �����������.");
    }
}

// ���������� ComboBox � ��
//---------------------------------------------------------------------------

void __fastcall TForm3::GetItemToFillBox()
{
	DataModule1->FDQuery1->Close();

	// ���������� ComboBox ��� ���� �����
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_type FROM DroneModel";
	DataModule1->FDQuery1->Open();
	ComboBoxDroneType->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxDroneType->Items->Add(DataModule1->FDQuery1->FieldByName("drone_type")->AsString);
		DataModule1->FDQuery1->Next();
	}

	// ���������� ComboBox ��� ����� �����
	DataModule1->FDQuery1->Close();
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT drone_name FROM DroneModel";
	DataModule1->FDQuery1->Open();
	ComboBoxDroneName->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxDroneName->Items->Add(DataModule1->FDQuery1->FieldByName("drone_name")->AsString);
		DataModule1->FDQuery1->Next();
	}

	// ���������� ComboBox ��� ������� ������
	DataModule1->FDQuery1->Close();
	DataModule1->FDQuery1->SQL->Text = "SELECT DISTINCT status FROM MilitaryRequests";
	DataModule1->FDQuery1->Open();
	ComboBoxStatus->Items->Clear();
	while (!DataModule1->FDQuery1->Eof) {
		ComboBoxStatus->Items->Add(DataModule1->FDQuery1->FieldByName("status")->AsString);
		DataModule1->FDQuery1->Next();
	}
}

// Գ�������� �� �����������
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonFilterClick(TObject *Sender)
{
	TDateTime startDate = DateTimePickerStart->Date;
	TDateTime endDate = DateTimePickerEnd->Date;

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
			DBGrid1->DataSource = DataModule1->DataSource1;
			SetDBGridColumnsStyles();
			ShowMessage("Filtered successfully");
		}
	} catch (Exception &e) {
		ShowMessage("������� ��� ����������: " + e.Message);
	}
}

// �������� �������
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonClearFilterClick(TObject *Sender)
{
   ComboBoxDroneType->ItemIndex = -1;
   ComboBoxDroneName->ItemIndex = -1;
   ComboBoxStatus->ItemIndex = -1;

   DateTimePickerStart->Date = EncodeDate(2024, 1, 1);  // ������� �� 1 ���� 2024 ����
   DateTimePickerEnd->Date = Now();                     // ������������ ������ ���� �� ��������

   LoadDB();
}

