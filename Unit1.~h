//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TButton *newGame;
        TTimer *TimerTop_PL;
        TTimer *TimerBottom_PL;
        TTimer *TimerTop_PP;
        TTimer *TimerBottom_PP;
        TTimer *Timer_ball;
        TShape *PL;
        TShape *PP;
        TShape *ball;
        TButton *nextRound;
        TLabel *Label2;
        TLabel *wynik;
        TLabel *points;
        TLabel *Label3;
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall TimerTop_PLTimer(TObject *Sender);
        void __fastcall TimerBottom_PLTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerTop_PPTimer(TObject *Sender);
        void __fastcall TimerBottom_PPTimer(TObject *Sender);
        void __fastcall Timer_ballTimer(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
