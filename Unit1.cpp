//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

extern bool isDarkTheme = false;
extern bool passwordVisible;
extern void closeAll(){ //функция очистки памяти от остальных форм
if(Form2){delete Form2;}
if(Form5){delete Form5;}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Form1->ClientWidth=800;
Form1->ClientHeight=500;
Form1->Color=clCream;
Label1->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form1->Hide();
Form2->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
closeAll();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
isDarkTheme = !isDarkTheme; // Инвертировать значение переменной темы
    if (isDarkTheme)
    {
        Form1->Color = clBlack;
        Form1->Label1->Font->Color = clWhite;

		Form2->Color = clBlack;
		Form2->Edit1->Font->Color = clBlack;
		Form2->Edit2->Font->Color = clBlack;

		Form5->Color = clBlack;

		Form5->Label1->Font->Color=clWhite;
		Form5->Label2->Font->Color=clWhite;
		Form5->Label3->Font->Color=clWhite;
			Form5->Label4->Font->Color=clWhite;



	   for(int i=0;i<Form5->GlobalDBGrid1->Columns->Count;i++)
		{
			Form5->GlobalDBGrid1->Columns->Items[i]->Color=clBlack;
			Form5->GlobalDBGrid1->Columns->Items[i]->Font->Color=clWhite;

		}
    }
    else
    {
		Form1->Color = clWhite;
        Form1->Label1->Font->Color = clBlack;

		Form2->Color = clWhite;
		Form2->Edit1->Font->Color = clBlack;
		Form2->Edit2->Font->Color = clBlack;

           for(int i=0;i<Form5->GlobalDBGrid1->Columns->Count;i++)
		{
			Form5->GlobalDBGrid1->Columns->Items[i]->Color=clWhite;
			Form5->GlobalDBGrid1->Columns->Items[i]->Font->Color=clBlack;


			Form5->Color = clWhite;

		Form5->Label1->Font->Color=clBlack;
		Form5->Label2->Font->Color=clBlack;
		Form5->Label3->Font->Color=clBlack;
		Form5->Label4->Font->Color=clBlack;
		}


	}
}
//---------------------------------------------------------------------------

