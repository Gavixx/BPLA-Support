//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ArmyForm.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------

__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	FDQuery1->Connection = FDConnection1;  // ��'���� � ����� �����
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SetDBGridColumnsStyles()
{
    DBGrid1->Columns->Items[0]->Width = 200;  // ������ ����� �������
    DBGrid1->Columns->Items[0]->Title->Caption = "��� �����";
    DBGrid1->Columns->Items[0]->Title->Alignment = taCenter;

    DBGrid1->Columns->Items[1]->Width = 200;  // ������ ����� �������
    DBGrid1->Columns->Items[1]->Title->Caption = "�������";
    DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;
    DBGrid1->Columns->Items[1]->Alignment = taCenter;

    DBGrid1->Columns->Items[2]->Width = 200;  // ������ ������ �������
    DBGrid1->Columns->Items[2]->Title->Caption = "���� ������";
    DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
    DBGrid1->Columns->Items[2]->Alignment = taCenter;

    DBGrid1->Columns->Items[3]->Width = 150;
    DBGrid1->Columns->Items[3]->Title->Caption = "�������";
    DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
    DBGrid1->Columns->Items[3]->Alignment = taCenter;

    DBGrid1->Columns->Items[4]->Width = 200;
    DBGrid1->Columns->Items[4]->Title->Caption = "��������";
    DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
    DBGrid1->Columns->Items[4]->Alignment = taCenter;
}


const String monthNames[12] = {"ѳ���", "������", "�������", "�����", "������", "������",
                               "�����", "������", "�������", "������", "���������", "������"};

void __fastcall TForm3::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
    TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

    int day = DayOf(requestDate);   // �������� ���� � ����
    int month = MonthOf(requestDate);  // �������� ����� � ����

    // ������� ������������� ����
    Text = IntToStr(day) + " " + monthNames[month - 1];
}



void __fastcall TForm3::ButtonShowStatClick(TObject *Sender)
{
    FDQuery1->SQL->Text = "SELECT drone_type, quantity, request_date, status, fulfilled_quantity FROM MilitaryRequests";
    FDQuery1->Open();

	// ����'����� ���� ��� ������������ ����
	FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;

    // ������������ DataSet ��� DataSource
	DataSource1->DataSet = FDQuery1;

    // ������������ ���� ������� ���� ������������ �����
    SetDBGridColumnsStyles();
}

//---------------------------------------------------------------------------

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


