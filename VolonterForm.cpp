//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VolonterForm.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner, String userName)
    : TForm(Owner), UserName(userName)
{
    // Відображення в Label або інший спосіб показу імені
    LabelWelcom->Caption = "Welcome, " + UserName;
}
//---------------------------------------------------------------------------


