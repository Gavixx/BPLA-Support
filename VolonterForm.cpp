//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VolonterForm.h"
#include "DataModule.h"
#include "DonateForm.h"
#include "ProfileForm.h"
#include <DateUtils.hpp>  // ��� DayOf() � MonthOf()
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------

const String monthNames[12] = {"ѳ���", "������", "�������", "�����", "������", "������",
							   "�����", "������", "�������", "������", "���������", "������"};





__fastcall TForm4::TForm4(TComponent* Owner, String userName, int user_id)
	: TForm(Owner), UserName(userName), UserID(user_id)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm4::LoadDB()  {
 // �������������, �� �'������� �� ���� ����� �������
	if (!DataModule1->FDConnection1->Connected) {
        DataModule1->ConnectToDatabase();
	}

    // ��������� ��������� ����� ����� ��������� ������
	DataModule1->FDQuery1->Close();

	// ����������� ����� ����� DataModule1
	DataModule1->FDQuery1->SQL->Text = "SELECT MR.request_id, DM.drone_name, DM.drone_type, MR.quantity, MR.request_date, MR.status, MR.fulfilled_quantity "
									   "FROM MilitaryRequests MR "
									   "JOIN DroneModel DM ON MR.drone_id = DM.drone_id "
										"WHERE MR.status = 'In Progress'";
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
	}               }

void __fastcall TForm4::FormShow(TObject *Sender)
{
	LoadDB();
	// ³���������� � Label ��� ����� ����� ������ ����
	LabelWelcom->Caption = "³����, " + UserName + "!";
	DBGrid1->SelectedRows->Clear();
	ButtonDonate->Enabled = false;
    BalloonHint1->Title = "������";
	BalloonHint1->Description = "��� ����������, ���� �����, �������� ������� ����� � �������.";
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
	int gridWidth = DBGrid1->ClientWidth; // �������� ������ �������
	int totalFixedWidth = 0; // �������� ������ ��� �������

	// �������� ������������ ��������� ������ ��� ��� ������� � ������ �������� ������
	for (int i = 0; i < DBGrid1->Columns->Count; i++) {
		if (i == 0) {
			DBGrid1->Columns->Items[i]->Visible = false; // ������� ID ������
		} else {
			DBGrid1->Columns->Items[i]->Width = gridWidth / DBGrid1->Columns->Count; // ���������� �������� ������
			totalFixedWidth += DBGrid1->Columns->Items[i]->Width;
		}
	}

	// ���������� �������������� ������ � ������ ���� �� ����� �������
	int remainingWidth = gridWidth - totalFixedWidth;
	int extraWidthPerColumn = remainingWidth / (DBGrid1->Columns->Count - 1);

	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width += extraWidthPerColumn; // ������ ��������� ������ �� ����� �������
	}

	// ������ ������������ ��������� � ����������� ��� ����� �������
	DBGrid1->Columns->Items[1]->Title->Caption = "����� �����";
	DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;

	DBGrid1->Columns->Items[2]->Title->Caption = "��� �����";
	DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[2]->Alignment = taCenter;

	DBGrid1->Columns->Items[3]->Title->Caption = "������� �-��";
	DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[3]->Alignment = taCenter;

	DBGrid1->Columns->Items[4]->Title->Caption = "���� ������ ������";
	DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[4]->Alignment = taCenter;

	DBGrid1->Columns->Items[5]->Title->Caption = "������";
	DBGrid1->Columns->Items[5]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[5]->Alignment = taCenter;

	DBGrid1->Columns->Items[6]->Title->Caption = "�������� �����";
	DBGrid1->Columns->Items[6]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[6]->Alignment = taCenter;

	// �������� ��� ����������� ����
	DataModule1->FDQuery1->FieldByName("request_date")->OnGetText = DateFieldGetText;
}




void __fastcall TForm4::DateFieldGetText(TField *Sender, UnicodeString &Text, bool DisplayText)
{
	TDateTime requestDate = Sender->AsDateTime;  // �������� ���� � ����

	int day = DayOf(requestDate);   // �������� ���� � ����
	int month = MonthOf(requestDate);  // �������� ����� � ����

	// ������� ������������� ����
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
	Action = caFree;   // ������� ���'��� ���� ��������
	Application->Terminate();  // ������� ����������
	}
}

//---------------------------------------------------------------------------


