//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ArmyForm.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()
#include "AddOrderForm.h"
#include "LoginForm.h"
//#include <windows.h>

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
	DateTimePickerEnd->Date = Now();

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
	TDateTime startDate = DateTimePickerStart->Date;
	TDateTime endDate = DateTimePickerEnd->Date;

	String baseSQL =
		"SELECT DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
		"FROM MilitaryRequests MR "
		"JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
		"WHERE MR.request_date BETWEEN :startDate AND :endDate";

	// ������ ���������� �� ����� �����, ���� ������� �������
	if (ComboBoxDroneName->Text != "")
	{
		String dronename = ComboBoxDroneName->Text;
		baseSQL += " AND DM.drone_name = :dronename";  // Գ�������� �� ����� �����

	}
		if (ComboBoxDroneType->Text != "")
	{
		String dronetype = ComboBoxDroneType->Text;
		baseSQL += " AND DM.drone_type = :dronetype";  // Գ�������� �� ����� �����
	}
		if (ComboBoxStatus->Text != "")
	{
		String status = ComboBoxStatus->Text;
		baseSQL += " AND MR.status = :status";  // Գ�������� �� ����� �����
	}



	// ���������� ���������� ����� �� FDQuery1
	FDQuery1->SQL->Text = baseSQL;

	// ����'����� ��������� �� ��������� �������
	FDQuery1->ParamByName("startDate")->AsDate = startDate;
	FDQuery1->ParamByName("endDate")->AsDate = endDate;

	// ���� ������� ��'� �����, �������� ���� �� ��������
    if (ComboBoxDroneName->Text != "")
	{
		FDQuery1->ParamByName("dronename")->AsString = ComboBoxDroneName->Text;
	}

		if (ComboBoxDroneType->Text != "")
	{
		FDQuery1->ParamByName("dronetype")->AsString = ComboBoxDroneType->Text;
	}

		if (ComboBoxStatus->Text != "")
	{
		FDQuery1->ParamByName("status")->AsString = ComboBoxStatus->Text;
	}




	try {
		FDQuery1->Open();  // �������� �����
		DataSource1->DataSet = FDQuery1;
		DBGrid1->DataSource = DataSource1;
		SetDBGridColumnsStyles();  // ������������ ����� �������
        ShowMessage("Filtered successfully");
	} catch (Exception &e) {
		ShowMessage("������� ��� ����������: " + e.Message);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonClearFilterClick(TObject *Sender)
{
   ComboBoxDroneType->ItemIndex = -1;
   ComboBoxDroneName->ItemIndex = -1;
   ComboBoxStatus->ItemIndex = -1;
   DateTimePickerStart->Date = StrToDate("01/01/2024");  // ������� DateTimePicker �� ������� ����
   DateTimePickerEnd->Date = Now();    // �� ���� ��� ������ ����
   LoadDB();
}


void __fastcall TForm3::MenuCloseClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ChangeUser1Click(TObject *Sender)
{
	TForm1 *LoginForm = new TForm1(this);
	LoginForm->Show();
	this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Help1Click(TObject *Sender)
{
       ShowMessage("Help\n"
		"Welcome to the Military Drone Management Application. This software is designed to help military personnel manage drone requests and volunteer contributions efficiently.\n\n"

		"Getting Started:\n"
		"To get started with the application:\n"
		"  - Installation: Download the installer from our website and follow the on-screen instructions to install.\n"
		"  - Launching the Application: Once installed, double-click the application icon to launch.\n\n"

		"Using the Application:\n"
		"  - Military Requests: To create a new military request, navigate to the \"Military Requests\" tab, fill in the required fields, and click \"Add Request\".\n"
		"  - Volunteers: Manage volunteer contributions under the \"Volunteers\" section.\n"
		"  - Drone Models: You can manage drone models under the \"Drone Models\" section. Click \"Add Model\" to enter new drone information.\n\n"

		"Filtering and Searching:\n"
		"To filter military requests:\n"
		"  - Use the date pickers to select a date range.\n"
		"  - If you want to filter by drone name, select the desired name from the dropdown.\n"
		"  - Click the \"Filter\" button to apply the selected criteria.\n\n"

		"Common Issues and Troubleshooting:\n"
		"  - Issue: Unable to add a new military request. Solution: Ensure all required fields are filled in correctly.\n"
		"  - Issue: Application crashes on startup. Solution: Check for updates and VPN connection or reinstall the application.\n");
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Help2Click(TObject *Sender)
{
		ShowMessage( " About Us\n"
		"This application was developed by the HighTech team. Version: 1.0.\n\n"

		"For additional assistance, please contact support at HighTech@info.com.");
}
//---------------------------------------------------------------------------

