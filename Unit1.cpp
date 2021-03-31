

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = 4;
int y = 4;
int liczbaOdbic = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTop_PLTimer(TObject *Sender)
{
    if(PL->Top > 5)  PL->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBottom_PLTimer(TObject *Sender)
{
     if(PL->Top + PL->Height < tlo->Height -8 )PL->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 0x41 ) TimerTop_PL->Enabled = true;
    if(Key == 0x5A ) TimerBottom_PL->Enabled = true;
    if(Key == 0x26 ) TimerTop_PP->Enabled = true;
    if(Key == 0x28 ) TimerBottom_PP->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 0x41 ) TimerTop_PL->Enabled = false;
    if(Key == 0x5A ) TimerBottom_PL->Enabled = false;
    if(Key == 0x26 ) TimerTop_PP->Enabled = false;
    if(Key == 0x28 ) TimerBottom_PP->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerTop_PPTimer(TObject *Sender)
{
    if(PP->Top > 5)  PP->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBottom_PPTimer(TObject *Sender)
{
      if(PP->Top + PP->Height < tlo->Height -8 )PP->Top += 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
      ball->Left -= x;
      ball->Top -= y;
      //odbicie od gornej sciany
      if( ball->Top <= tlo->Top+5 ) y = -y;
      //odbicie od dolnej sciany
      if ( ball->Top + ball->Height >= tlo->Top +tlo->Height  )  y = -y;
      // skucha zawodnika po lewej
      if ( ball->Left < PL->Left+PL->Width-5)
      {
         Timer_ball->Enabled = false;
         ball->Visible = false;
      }
      // odbicie pi³ki od Paletki Lewej
       if ((ball->Left <= PL->Left + PL->Width-2 &&
                ball->Top + ball->Height/2 <= PL->Top + PL->Height &&
                ball->Top + ball->Height/2 >= PL->Top))
       {
           x = -x;
           liczbaOdbic++;
       }

       // skucha zawodnika po prawej
      if (ball->Left + ball->Width > PP->Left+5)
      {
         Timer_ball->Enabled = false;
         ball->Visible = false;
      }
      // odbicie pi³ki od Paletki Prawej
      if ((ball->Left + ball->Width <= PP->Left &&
                ball->Top + ball->Height/2 >= PP->Top  &&
                ball->Top + ball->Height/2 <= PL->Top + PP->Height))
       {
           x = -x;
           liczbaOdbic++;
       }

}

//---------------------------------------------------------------------------


