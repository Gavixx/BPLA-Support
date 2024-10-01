//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdminForm.h"
#include "AddUser.h"
#include "DataModule.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()
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
//---------------------------------------------------------------------------
void __fastcall TForm2::SetDBGridColumnsStylesUsers()
{
	int gridWidth = DBGridUsers->ClientWidth; // ������ �񳺿 ��������

	// ��������� �������� ������� �������
	int totalColumns = DBGridUsers->Columns->Count;

	// ���������� ����������� ��� ������� (�� ������ �������� �� ��������, ��� ����������� ���������)
	float coefColumn1 = 0.4; // 40% ��� ����� �������
	float coefColumn2 = 0.35; // 35% ��� ����� �������
	float coefColumn3 = 0.25; // 25% ��� ������ �������

	// ������������ ������ ����� ������� ������� ������ �������
	 DBGridUsers->Columns->Items[0]->Width = gridWidth * coefColumn1;
	 DBGridUsers->Columns->Items[0]->Title->Caption = "ϲ�";
	 DBGridUsers->Columns->Items[0]->Title->Alignment = taCenter;

	 DBGridUsers->Columns->Items[1]->Width = gridWidth * coefColumn2;
	 DBGridUsers->Columns->Items[1]->Title->Caption = "�����";
	 DBGridUsers->Columns->Items[1]->Title->Alignment = taCenter;
	 DBGridUsers->Columns->Items[1]->Alignment = taCenter;

	 DBGridUsers->Columns->Items[2]->Width = gridWidth * coefColumn3;
	 DBGridUsers->Columns->Items[2]->Title->Caption = "�������";
	 DBGridUsers->Columns->Items[2]->Title->Alignment = taCenter;
	 DBGridUsers->Columns->Items[2]->Alignment = taCenter;

}

void __fastcall TForm2::SetDBGridColumnsStylesRequests(){
	int gridWidth = DBGridRequests->ClientWidth; // ������ �񳺿 ��������

	// ��������� �������� ������� �������
	int totalColumns = DBGridRequests->Columns->Count;
	// ���������� ����������� ��� ������� (�� ������ �������� �� ��������, ��� ����������� ���������)
	float coefColumn1 = 0.2;  // 20% ��� ����� �������
	float coefColumn2 = 0.2;  // 20% ��� ����� �������
	float coefColumn3 = 0.1;  // 10% ��� ������ �������
	float coefColumn4 = 0.2;  // 20% ��� �������� �������
	float coefColumn5 = 0.2;  // 20% ��� �'��� �������
	float coefColumn6 = 0.1;  // 10% ��� ����� �������



	// ������������ ������ ����� ������� ������� ������ �������
	 DBGridRequests->Columns->Items[0]->Width = 386;
	 DBGridRequests->Columns->Items[0]->Title->Caption = "����� �����";
	 DBGridRequests->Columns->Items[0]->Title->Alignment = taCenter;

	 DBGridRequests->Columns->Items[1]->Width = 275;
	 DBGridRequests->Columns->Items[1]->Title->Caption = "��� �����";
	 DBGridRequests->Columns->Items[1]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[1]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[2]->Width = 231;
	 DBGridRequests->Columns->Items[2]->Title->Caption = "������� �-��";
	 DBGridRequests->Columns->Items[2]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[2]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[3]->Width = 231;
	 DBGridRequests->Columns->Items[3]->Title->Caption = "���� ������ ������";
	 DBGridRequests->Columns->Items[3]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[3]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[4]->Width = 231;
	 DBGridRequests->Columns->Items[4]->Title->Caption = "������";
	 DBGridRequests->Columns->Items[4]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[4]->Alignment = taCenter;

	 DBGridRequests->Columns->Items[5]->Width = 154;
	 DBGridRequests->Columns->Items[5]->Title->Caption = "�������� �����";
	 DBGridRequests->Columns->Items[5]->Title->Alignment = taCenter;
	 DBGridRequests->Columns->Items[5]->Alignment = taCenter;

	// �������� ��� ����������� ����
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;


}

//---------------------------------------------------------------------------

void __fastcall TForm2::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

	int day = DayOf(requestDate);   // �������� ���� � ����
	int month = MonthOf(requestDate);  // �������� ����� � ����

	// ������� ������������� ����
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
		DataModule1->ConnectToDatabase();	  // ϳ��������� �� ���� ����� DataModule1

		// ������������ ������ ����� DataModule1
		DataModule1->FDQuery1->Connection = DataModule1->FDConnection1;
		DataModule1->FDQuery1->SQL->Text = "SELECT name, email, phone FROM Volunteers";
		DataModule1->FDQuery1->Open();  // ������ ����� �� ������� ����������

		// ����'���� �����
		DataModule1->DataSource1->DataSet = DataModule1->FDQuery1;
		DBGridUsers->DataSource = DataModule1->DataSource1;
		SetDBGridColumnsStylesUsers();  // ������������ ���� �������
	} catch (const Exception &e) {
		ShowMessage("������� ��� �������� �����: " + e.Message);
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
		SetDBGridColumnsStylesUsers();  // ��������� ���� �������
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


