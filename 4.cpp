//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#pragma hdrstop

#include "Lab4Form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormLab *FormLab;
typedef double (*TFun)(double);



void Out_Rez(TFun,double,double,double,TListBox*);
void Out_Rez(TFun f,double a,double b,double h,TMemo *tMemo);

int n=10;

int prefix(int k )
{
 return ((k % 2 == 0) ? 1 : -1);
}
double nomenator(int k,float x)
{
 double nomen = 1;
 k = 2 * k;
 for (int i = 0; i <k; i++)
  nomen = nomen * 2 * x;
 return nomen;
}
double factorial(int i) {
 if ( i == 0) return 1;
 else return i * factorial(i - 1);
}
double  denominator(int k){
 return (factorial(2*k));
}
double Y(double x) {
 return 2 * (cos(x) * cos(x) - 1);
}
double S(double x) {
 double s = 0;
 for (int k = 1; k <= n; k++){
  s+=  prefix(k) * nomenator(k, x) / denominator(k);
 }
 return s;
}
double Diff(double x) {
	return  abs(S(x) - Y(x));
 }


//---------------------------------------------------------------------------
__fastcall TFormLab::TFormLab(TComponent* Owner)
	: TForm(Owner){
}
//---------------------------------------------------------------------------
void __fastcall TFormLab::tbCalcClick(TObject *Sender)
{
	double a,b,h;
        int i_func=0;
        a=StrToFloat(teA->Text);
        b=StrToFloat(teB->Text);
        h=StrToFloat(teH->Text);
        n=StrToFloat(teN->Text);
        n=n>50?50:n;
        switch(rgFunc->ItemIndex){
	        case 0: Out_Rez(S,a,b,h,lb1);
                        break;
         	case 1: Out_Rez(Y,a,b,h,lb2);
                        break;
                case 2: Out_Rez(Diff,a,b,h,lb3);
                        Out_Rez(Diff,a,b,h,Memo1);
                        break;
        }
 }

void Out_Rez(TFun f,double a,double b,double h,TListBox *lbR){
                        lbR->Items->Clear();
                        for(double x=a; x<=b; x+=h)
                           lbR->Items->Add("x="+FloatToStrF(x,ffFixed,8,2)+" f(x)="+FloatToStrF(f(x),ffFixed,8,5));
}
void Out_Rez(TFun f,double a,double b,double h,TMemo *tMemo){
                        tMemo->Clear();
                        for(double x=a; x<=b; x+=h)
                           //lbR->Items->Add("x="+FloatToStrF(x,ffFixed,8,2)+" f(x)="+FloatToStrF(f(x),ffFixed,8,5));
                           tMemo->Lines->Add("x="+FloatToStrF(x,ffFixed,8,2)+" f(x)="+FloatToStrF(f(x),ffFixed,8,5));
}

