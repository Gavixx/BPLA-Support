//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AddOrderForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::ButtonAddClick(TObject *Sender)
{

	String drone_type =  LabeledEditDroneType->Text;
	ShowMessage(drone_type);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
	FDQuery1->Connection = FDConnection1;
}
//---------------------------------------------------------------------------
