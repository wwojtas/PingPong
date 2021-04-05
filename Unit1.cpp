//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = 6;
int y = 6;
int scoreForLeftPlayer = 0;
int scoreForRightPlayer = 0;
int numberOfReflections = 0;
int round = 1;
AnsiString how = "";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTop_PLTimer(TObject *Sender)
{
        if( PL->Top > 5)   PL->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBottom_PLTimer(TObject *Sender)
{
        if( PL->Top + PL->Height < tlo->Height-8) PL->Top += 10;
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
        if( PP->Top > 5)   PP->Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBottom_PPTimer(TObject *Sender)
{
        if( PP->Top + PP->Height < tlo->Height-8) PP->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
   ball->Left += x;
   ball->Top += y;

   //odbicie od górnej sciany
   if (ball->Top <= tlo->Top) y = -y ;

   //odbicie od dolnej sciany
   if (ball->Top + ball->Height >= tlo->Height) y = -y;

   //skucha
    if ((( ball->Left < PL->Left  &&
        (ball->Top + ball->Height/2 < PL->Top ||
        ball->Top + ball->Height/2 > PL->Top + PL->Height)) ||
        (ball->Left + ball->Width > PP->Left + PP->Width &&
        (ball->Top + ball->Height/2 < PP->Top ||
        ball->Top + ball->Height/2 > PP->Top + PP->Height))))
    {
        Timer_ball->Enabled = false;
        ball->Visible = false;
        round++;
        if (how == "leftPlayer" && ball->Left > PP->Left)
        {
                points->Caption = " <= Punkt dla gracza lewego ";
                scoreForLeftPlayer++;
         }
        else if (how == "rightPlayer" && ball->Left < PL->Left)
        {
                points->Caption = " Punkt dla gracza prawego => ";
                scoreForRightPlayer++;
        }

        points->Visible = true;
        wynik->Caption = " " + IntToStr(scoreForLeftPlayer) + " : " + IntToStr(scoreForRightPlayer);
        wynik->Visible = true;
        Label2->Caption = " Iloœæ odbiæ:" + IntToStr(numberOfReflections);
        Label2->Visible = true;
        newGame->Visible = true;
        nextRound->Visible = true;
      }

   else if ((ball->Left < PL->Left + PL->Width &&
           ball->Top + ball->Height/2 <= PL->Top + PL->Height &&
           ball->Top + ball->Height/2 >= PL->Top))
       {
                x = 1.1 * x;
                numberOfReflections++;
                how = "leftPlayer";
                if(x < 0)
                {
                        if ((ball->Left <= PL->Left + PL->Width &&
                        ball->Top + ball->Height/2 < PL->Top + PL->Height/3 &&
                        ball->Top + ball->Height/2 >= PL->Top))
                        {
                                x = -  1.1 * x;
                                y = 1.1 * y;
                        }
                        else if ((ball->Left <= PL->Left + PL->Width &&
                        ball->Top + ball->Height/2 <= PL->Top + 2 * PL->Height/3 &&
                        ball->Top + ball->Height/2 >= PL->Top + PL->Height/3))
                        {
                                x = -1.2* x;
                        }
                        else if ((ball->Left <= PL->Left + PL->Width &&
                        ball->Top + ball->Height/2 <= PL->Top +  PL->Height &&
                        ball->Top + ball->Height/2 > PL->Top + 2/3 * PL->Height))
                        {
                                x = -1.1 * x;
                                y = 1.1 * y;
                        }
                }
       }

else if ((ball->Left + ball->Width >= PP->Left  &&
           ball->Top + ball->Height/2 <= PP->Top + PP->Height &&
           ball->Top + ball->Height/2 >= PP->Top))
            {
                x =  1.1 * x;
                numberOfReflections++;
                how = "rightPlayer";
                if(x > 0)
                {
                        if ((ball->Left + ball->Width >= PP->Left &&
                        ball->Top + ball->Height/2 < PP->Top + PP->Height/3 &&
                        ball->Top + ball->Height/2 >= PP->Top))
                        {
                                x = -  1.1 * x;
                                y = 1.1 * y;
                        }
                        else if ((ball->Left <= PP->Left + PP->Width &&
                        ball->Top + ball->Height/2 <= PP->Top + 2 * PP->Height/3 &&
                        ball->Top + ball->Height/2 >= PP->Top + PP->Height/3))
                        {
                                x = -1.2* x;
                        }
                        else if ((ball->Left <= PP->Left + PP->Width &&
                        ball->Top + ball->Height/2 <= PP->Top +  PP->Height &&
                        ball->Top + ball->Height/2 > PP->Top + 2/3 * PP->Height))
                        {
                                x = -1.1 * x;
                                y = 1.1 * y;
                        }
                }
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
     points->Visible = false;
     wynik->Visible = false;
     Label2->Visible = false;
     Label3->Visible = true;
     newGame->Visible = true;
     nextRound->Visible = false;

     scoreForLeftPlayer = 0,
     scoreForRightPlayer = 0;
     numberOfReflections = 0;
     round = 1;
     how = "leftPlayer";
     Timer_ball->Enabled = true;
     ball->Visible = true;
     newGame->Visible = false;
     Label3->Visible = false;
     ball->Left = 100;
     x = 6; y = 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
     points->Visible = false;
     wynik->Visible = false;
     Label2->Visible = false;
     Label3->Visible = true;
     newGame->Visible = true;
     nextRound->Visible = false;
     Timer_ball->Enabled = true;
     ball->Visible = true;
     newGame->Visible = false;
     Label3->Visible = false;
     numberOfReflections = 0;
     if (round > 1 && round % 2 == 0)
     {
        ball->Left = PP->Left - 10;
        x = -7, y = -7;
     }
     else if (round > 1 && round % 2 == 1)
     {
         ball->Left = 100;
         x = 7, y = 7;
     }
        randomize();
        ball->Top = random(tlo->Height - 100) + 50 ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(Application->MessageBoxA("Czy na pewno zakonczyc program?", "Potwierdz",
        MB_YESNO | MB_ICONQUESTION) == IDNO)
        {
                Action = caNone;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application->MessageBox(
        "Zapraszam do gry w Ping Ponga! \n "
        "Troche historii Ping Ponga \n"
        "Narodzil sie w Anglii w latach 80. XIX w.\n"
        "W Londynie odbyly sie pierwsze oficjalne\n"
        "mistrzostwa swiata w 1926 roku\n"
        "W 1988 r. po raz pierwszy pojawil sie w programie\n"
        "igrzysk olimpijskich w Seulu\n"
        "Sterowanie: "
        "Lewy gracz: klawisze A i Z \n"
        "Prawy gracz: klawisze UP i DOWN \n"
        "\n MILEJ ZABAWY \n"
        ,MB_OK);
}
//---------------------------------------------------------------------------

