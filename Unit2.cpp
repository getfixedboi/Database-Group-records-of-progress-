//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TDBGrid* GlobalDBGrid1;
extern void closeAll();
extern bool isDarkTheme,passwordVisible;
extern int min,sec,hou;
bool passwordVisible = false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
min=0;
sec=0;
hou=0;
Form2->ClientWidth=800;
Form2->ClientHeight=500;
Form2->Color=clCream;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
if(Edit1->Text=="admin" && Edit2->Text=="admin"){
ShowMessage("Текущая роль: Администратор");
Form2->Hide();
Form5->Show();
Form5->GlobalDBGrid1->ReadOnly=false;
Form5->Timer1->Enabled=true;

Form5->Edit1->Enabled=true;
Form5->Edit2->Enabled=true;
Form5->Edit3->Enabled=true;

Form5->Label1->Enabled=true;
Form5->Label2->Enabled=true;
Form5->Label3->Enabled=true;
}
else if(Edit1->Text=="user" && Edit2->Text=="123"){
ShowMessage("Текущая роль: Студент");
Form2->Hide();
Form5->Show();
Form5->GlobalDBGrid1->ReadOnly=true;
Form5->Timer1->Enabled=true;

//Form5->MainMenu1->Enabled=false;    //оаоаоао нет параметра Enabled, а без разницы, поля то для изменений недоступны АХХАХАХХАХА

Form5->Edit1->Enabled=false;
Form5->Edit2->Enabled=false;
Form5->Edit3->Enabled=false;

Form5->Label1->Enabled=false;
Form5->Label2->Enabled=false;
Form5->Label3->Enabled=false;

}
else if (!(Edit1->Text=="Rick" && Edit2->Text=="Astley"))ShowMessage("Неверный логин или пароль");

if (Edit1->Text=="Rick" && Edit2->Text=="Astley"){
#include <Windows.h>
ShellExecuteA(NULL, "open", "https://www.youtube.com/watch?v=dQw4w9WgXcQ", NULL, NULL, SW_SHOWNORMAL);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
Form2->Hide();
Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1Click(TObject *Sender)
{
passwordVisible = !passwordVisible;

    // Изменение свойства PasswordChar компонента TEdit
    if (passwordVisible) {
		Edit2->PasswordChar = 0;  // Отображение пароля
	} else {
		Edit2->PasswordChar = '*';  // Скрытие пароля
    }

    // Изменение изображения глаза в зависимости от состояния пароля
	if (passwordVisible) {

	if(isDarkTheme)
	{
	Image1->Picture->LoadFromFile("p2dark.png");  // Путь к изображению глаза открытого
	}
	else
	{
	Image1->Picture->LoadFromFile("p2.png");
	}
	}
	else
	{
	if(isDarkTheme)
	{
	Image1->Picture->LoadFromFile("p1dark.png");  // Путь к изображению глаза открытого
	}
	else
	{
	Image1->Picture->LoadFromFile("p1.png");
	}
	}
}
//---------------------------------------------------------------------------

