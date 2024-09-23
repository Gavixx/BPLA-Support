//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ArmyForm.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()
#include "AddOrderForm.h"
#include <windows.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------

const String monthNames[12] = {"ѳ���", "������", "�������", "�����", "������", "������",
							   "�����", "������", "�������", "������", "���������", "������"};





__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	FDQuery1->Connection = FDConnection1;  // ��'���� � ����� �����
	GetItemToFillBox();
	LoadDB();

}


//     		     ³���� ��� ���������� �������
//---------------------------------------------------------------------------
void __fastcall TForm3::SetDBGridColumnsStyles()
{
	DBGrid1->Columns->Items[0]->Width = 200;  // ������ ����� �������
	DBGrid1->Columns->Items[0]->Title->Caption = "����� �����";
	DBGrid1->Columns->Items[0]->Title->Alignment = taCenter;

	DBGrid1->Columns->Items[1]->Width = 200;  // ������ ����� �������
	DBGrid1->Columns->Items[1]->Title->Caption = "��� �����";
	DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[1]->Alignment = taCenter;

	DBGrid1->Columns->Items[2]->Width = 150;  // ������ ������ �������
	DBGrid1->Columns->Items[2]->Title->Caption = "������� �-��";
	DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[2]->Alignment = taCenter;

	DBGrid1->Columns->Items[3]->Width = 200;
	DBGrid1->Columns->Items[3]->Title->Caption = "���� ������ ������";
	DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[3]->Alignment = taCenter;

	DBGrid1->Columns->Items[4]->Width = 200;
	DBGrid1->Columns->Items[4]->Title->Caption = "������";
	DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[4]->Alignment = taCenter;

	DBGrid1->Columns->Items[5]->Width = 200;
	DBGrid1->Columns->Items[5]->Title->Caption = "�������� ������";
	DBGrid1->Columns->Items[5]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[5]->Alignment = taCenter;
	FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
}


//       	    ��� ����������� � ������ "1 �������"
void __fastcall TForm3::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

	int day = DayOf(requestDate);   // �������� ���� � ����
	int month = MonthOf(requestDate);  // �������� ����� � ����

	// ������� ������������� ����
	Text = IntToStr(day) + " " + monthNames[month - 1];
}



  // 			��� �� ���� �������
void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{
	// ��'� ����, �� ���� ���������� ����������
	static String lastSortedColumn = "";  // ������� ����������� �������
	static bool sortAscending = true;     // ������ ��� �������� ����������

	String columnName = Column->FieldName;

	// ��������, �� � �������� DataSet, � �� ������� �� SQL
	if (DataSource1->DataSet && dynamic_cast<TFDQuery*>(DataSource1->DataSet))
	{
		TFDQuery *query = dynamic_cast<TFDQuery*>(DataSource1->DataSet);

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

		// ��������� ����� � ��������������� ����
		query->SQL->Text = baseSQL;
		query->Close();
		query->Open();
			// ����'����� ���� ��� ������������ ����
		FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;

		// ������������ DataSet ��� DataSource
		DataSource1->DataSet = FDQuery1;
		SetDBGridColumnsStyles();
	}
}

//---------------------------------------------------------------------------

//              ³������� ����� �� ��������� ������
void __fastcall TForm3::ButtonAddOrderClick(TObject *Sender)
{
	TForm5 *AddOrderForm = new TForm5(this);
	AddOrderForm->Show();
	this->Hide();

}
//---------------------------------------------------------------------------


//              ������ ��� ��������� �������(������ ��)
void __fastcall TForm3::ButtonShowStatClick(TObject *Sender)
{
	FDConnection1->Connected = true;  // �������������, �� �'������� � ����� ����� �������

	// ������������ ������
	FDQuery1->Connection = FDConnection1;
	FDQuery1->SQL->Text = "SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
						   "FROM MilitaryRequests MR "
						   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id";
	FDQuery1->Open();  // ������ ����� �� ������� ����������

    // ����'���� �����
    DataSource1->DataSet = FDQuery1;
	DBGrid1->DataSource = DataSource1;
	SetDBGridColumnsStyles();
}
//---------------------------------------------------------------------------

//       	   ������� ��� �������� ��
void __fastcall TForm3::LoadDB(){

	FDConnection1->Connected = true;  // �������������, �� �'������� � ����� ����� �������

	// ������������ ������
	FDQuery1->Connection = FDConnection1;
	FDQuery1->SQL->Text = "SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
						   "FROM MilitaryRequests MR "
						   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id";
	FDQuery1->Open();  // ������ ����� �� ������� ����������

	// ����'���� �����
	DataSource1->DataSet = FDQuery1;
	DBGrid1->DataSource = DataSource1;
	SetDBGridColumnsStyles();

}

//---------------------------------------------------------------------------

// 				���������� box � ��

void __fastcall TForm3::GetItemToFillBox(){
	//  Drone type
	FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT DISTINCT drone_type FROM DroneModel";
	FDQuery1->Open();
	ComboBoxDroneType->Items->Clear();
	while (!FDQuery1->Eof) {
		ComboBoxDroneType->Items->Add(FDQuery1->FieldByName("drone_type")->AsString);
		FDQuery1->Next();
	}
	//  Drone name
	FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT DISTINCT drone_name FROM DroneModel";
	FDQuery1->Open();
	ComboBoxDroneName->Items->Clear();
	while (!FDQuery1->Eof) {
		ComboBoxDroneName->Items->Add(FDQuery1->FieldByName("drone_name")->AsString);
		FDQuery1->Next();
	}
	// Drone Status
    FDQuery1->Close();
	FDQuery1->SQL->Text = "SELECT DISTINCT status FROM MilitaryRequests";
	FDQuery1->Open();
	ComboBoxStatus->Items->Clear();
	while (!FDQuery1->Eof) {
		ComboBoxStatus->Items->Add(FDQuery1->FieldByName("status")->AsString);
		FDQuery1->Next();
	}
}

//---------------------------------------------------------------------------



void __fastcall TForm3::ButtonFilterClick(TObject *Sender)
{
    // �������� �������� ��� � DateTimePicker
    TDateTime startDate = DateTimePickerStart->Date;
    TDateTime endDate = DateTimePickerEnd->Date;
	if (ComboBoxDroneName->Text == "")
	{
		ShowMessage("���� ���� ����� �����!");
	}
	else
	{
		ShowMessage("�������� ��� �����: " + ComboBoxDroneName->Text);
	}
}
//---------------------------------------------------------------------------

