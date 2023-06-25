//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cmath>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
extern void closeAll();
int sum1sem=0,kol1sem=0,sum2sem=0,kol2sem=0,kolzach=0;
bool zach;
extern int min=0,sec=0,hou=0;

//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
ADOQuery1->Edit();
Timer1->Enabled=true;

Form5->ClientWidth=1100;
Form5->ClientHeight=500;
Form5->Color=clCream;

GlobalDBGrid1->Columns->Items[0]->Width=100;

for(int i=1;i<GlobalDBGrid1->Columns->Count;i++)//��������� ������ �������
{

GlobalDBGrid1->Columns->Items[i]->Width=80;
}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
Timer1->Enabled=false;
Form5->Hide();
Form2->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm5::N2Click(TObject *Sender)
{
ADOQuery1->Active=0;
ADOQuery1->SQL->Text=
"select * from tab1 ORDER BY ���_��������";
ADOQuery1->Active=1;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------

void __fastcall TForm5::N4Click(TObject *Sender)
{
if(Edit1->Text!="")
{
AnsiString a=Edit1->Text;
ADOQuery1->Active=0;
ADOQuery1->SQL->Text=
"SELECT * FROM tab1 WHERE ���_�������� = :name";
ADOQuery1->Parameters->ParamByName("name")->Value = a;
ADOQuery1->Active=1;
Edit1->Text="";
}
else ShowMessage("��������� ���� ��� ������");
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N3Click(TObject *Sender)
{
ADOQuery1->Active=0;
ADOQuery1->SQL->Text=
"select * from tab1";
ADOQuery1->Active=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N6Click(TObject *Sender)
{
ADOQuery1->Append();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N7Click(TObject *Sender)
{
if(Edit2->Text!=""){
TLocateOptions Options;
if (ADOQuery1->Locate("���_��������",Edit2->Text,Options)) {
ADOQuery1->Delete();
}
else ShowMessage("��� �������� ��� ��������");
}
else ShowMessage("��������� ���� ��� ��������") ;
}
//---------------------------------------------------------------------------


void __fastcall TForm5::N9Click(TObject *Sender)
{
if(FontDialog1->Execute())
{
Form5->Font->Assign(FontDialog1->Font);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::GlobalDBGrid1KeyPress(TObject *Sender, System::WideChar &Key)
{
{
	if (DataSource1->DataSet->RecordCount >= 30 && Key != VK_BACK && Key != VK_DELETE) {
		Key = NULL;
	}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N11Click(TObject *Sender)
{
if(Edit3->Text!="")
{
ADOQuery1->Active=false;
ADOQuery1->SQL->Text="SELECT * FROM tab1 WHERE ([����������1�������] > " + Edit3->Text + ")";
ADOQuery1->Active=true;
}
else ShowMessage("��� �������� ��� �������");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm5::ADOQuery1CalcFields(TDataSet *DataSet)
{

ADOQuery1->FieldByName ("����1�������")->Value =
(ADOQuery1->FieldByName("����������1�������")->AsInteger +ADOQuery1->FieldByName("����1�������") ->AsInteger +  ADOQuery1->FieldByName("����1�������") ->AsInteger +  ADOQuery1->FieldByName("����1�������") ->AsInteger)/4;

ADOQuery1->FieldByName ("����2�������")->Value =
(ADOQuery1->FieldByName("����������2�������")->AsInteger +ADOQuery1->FieldByName("����2�������") ->AsInteger +  ADOQuery1->FieldByName("����2�������") ->AsInteger +  ADOQuery1->FieldByName("����2�������") ->AsInteger)/4;

ADOQuery1->FieldByName ("�������")->Value =
(ADOQuery1->FieldByName("����1�������")->AsInteger +ADOQuery1->FieldByName("����2�������") ->AsInteger )/2;



}
//---------------------------------------------------------------------------

void __fastcall TForm5::N12Click(TObject *Sender)
{
ADOQuery1->Active=0;
ADOQuery1->SQL->Text=
"select * from tab1";
ADOQuery1->Active=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::N21Click(TObject *Sender)
{
if(Edit3->Text!="")
{
ADOQuery1->Active=false;
ADOQuery1->SQL->Text="SELECT * FROM tab1 WHERE ([����������2�������] > " + Edit3->Text + ")";
ADOQuery1->Active=true;
}
else ShowMessage("��� �������� ��� �������");
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Timer1Timer(TObject *Sender)
{
if(min>=60){hou++;
min-=60;
}
if(sec>=60){min++;
sec-=60;
}
sec++;
Label4->Caption="�� ������� �� ������� � �� ����� "+ IntToStr(hou) + " �����," + IntToStr(min) + " ����� � " + IntToStr(sec) + " ������";
}
//---------------------------------------------------------------------------


void __fastcall TForm5::N13Click(TObject *Sender)
{
ADOQuery1->Active=0;
ADOQuery1->SQL->Text=
"SELECT * FROM tab1 ORDER BY ���_�������� ASC";
ADOQuery1->Active=1;
}
//---------------------------------------------------------------------------



