//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("DonateForm.cpp", Form7);
USEFORM("LoginForm.cpp", Form1);
USEFORM("VolonterForm.cpp", Form4);
USEFORM("AddOrderForm.cpp", Form5);
USEFORM("AddUser.cpp", Form6);
USEFORM("AdminForm.cpp", Form2);
USEFORM("ArmyForm.cpp", Form3);
USEFORM("DataModule.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("ProfileForm.cpp", Form8);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
//		Application->CreateForm(__classid(TForm7), &Form7);
//		Application->CreateForm(__classid(TForm8), &Form8);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
