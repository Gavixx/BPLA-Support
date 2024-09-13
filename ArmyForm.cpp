//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ArmyForm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------

__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	FDQuery1->Connection = FDConnection1;  // Зв'язок з базою даних
}
//---------------------------------------------------------------------------

void __fastcall TForm3::ButtonShowStatClick(TObject *Sender)
{
	FDQuery1->SQL->Text = "SELECT drone_type, quantity, request_date, status, fulfilled_quantity FROM MilitaryRequests";
	FDQuery1->Open();
	DataSource1->DataSet = FDQuery1;
	DBGrid1->Columns->Items[0]->Width = 200;  // Ширина першої колонки
	DBGrid1->Columns->Items[0]->Title->Caption = "Тип дрону";
	DBGrid1->Columns->Items[0]->Title->Alignment = taCenter;

	DBGrid1->Columns->Items[1]->Width = 200;  // Ширина другої колонки
	DBGrid1->Columns->Items[1]->Title->Caption = "Потрібно";
	DBGrid1->Columns->Items[1]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[1]->Alignment = taCenter;

	DBGrid1->Columns->Items[2]->Width = 200;  // Ширина третьої колонки
	DBGrid1->Columns->Items[2]->Title->Caption = "Дата запиту";
	DBGrid1->Columns->Items[2]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[2]->Alignment = taCenter;

	DBGrid1->Columns->Items[3]->Width = 150;
	DBGrid1->Columns->Items[3]->Title->Caption = "Прогрес";
	DBGrid1->Columns->Items[3]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[3]->Alignment = taCenter;

	DBGrid1->Columns->Items[4]->Width = 200;
	DBGrid1->Columns->Items[4]->Title->Caption = "Отримано";
	DBGrid1->Columns->Items[4]->Title->Alignment = taCenter;
	DBGrid1->Columns->Items[4]->Alignment = taCenter;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::DBGrid1TitleClick(TColumn *Column)
{

	 String columnName = Column->Field->FieldName;
    String sql = FDQuery1->SQL->Text;

    // Перевірка наявності ORDER BY у SQL запиті
    int orderByPos = sql.Pos("ORDER BY");
    if (orderByPos > 0)
    {
        // Видалити поточний ORDER BY
        sql = sql.SubString(1, orderByPos - 1).Trim();

        // Перевірка поточного порядку сортування
        if (sql.Pos(columnName) > 0)
        {
            // Перевірка поточного порядку сортування
            if (sql.Pos("DESC") > 0)
            {
                // Якщо поточне сортування DESC, змініть на ASC
                sql = sql.SubString(1, sql.Pos(columnName) - 1) + " ORDER BY " + columnName + " ASC";
            }
            else
            {
                // Якщо поточне сортування ASC, змініть на DESC
                sql = sql.SubString(1, sql.Pos(columnName) - 1) + " ORDER BY " + columnName + " DESC";
            }
        }
        else
        {
            // Додати новий ORDER BY
            sql += " ORDER BY " + columnName + " ASC";
        }
    }
    else
    {
        // Додати новий ORDER BY
        sql += " ORDER BY " + columnName + " ASC";
    }

    // Оновлення SQL запиту
    FDQuery1->SQL->Text = sql;

    // Перезапуск запиту
    FDQuery1->Active = false;
	FDQuery1->Active = true;

}
//---------------------------------------------------------------------------


