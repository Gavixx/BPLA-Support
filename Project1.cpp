//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("ProfileForm.cpp", Form8);
USEFORM("LoginForm.cpp", Form1);
USEFORM("DonateForm.cpp", Form7);
USEFORM("VolonterForm.cpp", Form4);
USEFORM("AddUser.cpp", Form6);
USEFORM("AddOrg.cpp", Form9);
USEFORM("AddOrderForm.cpp", Form5);
USEFORM("DataModule.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("ArmyForm.cpp", Form3);
USEFORM("AdminForm.cpp", Form2);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TDataModule1), &DataModule1);
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
