//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
                       // Встановлюємо кількість стовпців та рядків
    StringGrid1->ColCount = 4;  // 4 стовпці
    StringGrid1->RowCount = 4;  // 4 рядки (1 заголовок + 3 рядки даних)

    // Встановлюємо заголовки стовпців
    StringGrid1->Cells[0][0] = "ID";
    StringGrid1->Cells[1][0] = "Username";
    StringGrid1->Cells[2][0] = "Email";
    StringGrid1->Cells[3][0] = "Password";

    // Додаємо дані в таблицю
    StringGrid1->Cells[0][1] = "1";
    StringGrid1->Cells[1][1] = "john_doe";
    StringGrid1->Cells[2][1] = "john@example.com";
    StringGrid1->Cells[3][1] = "password123";

    StringGrid1->Cells[0][2] = "2";
    StringGrid1->Cells[1][2] = "jane_smith";
    StringGrid1->Cells[2][2] = "jane@example.com";
    StringGrid1->Cells[3][2] = "securepass";

    StringGrid1->Cells[0][3] = "3";
    StringGrid1->Cells[1][3] = "alex_brown";
    StringGrid1->Cells[2][3] = "alex@example.com";
    StringGrid1->Cells[3][3] = "qwerty123";
}
//---------------------------------------------------------------------------
