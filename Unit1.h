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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *PL;
        TImage *PP;
        TTimer *TimerTop_PL;
        TTimer *TimerBottom_PL;
        TTimer *TimerTop_PP;
        TTimer *TimerBottom_PP;
        TImage *ball;
        TTimer *Timer_ball;
        void __fastcall TimerTop_PLTimer(TObject *Sender);
        void __fastcall TimerBottom_PLTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall TimerTop_PPTimer(TObject *Sender);
        void __fastcall TimerBottom_PPTimer(TObject *Sender);
        void __fastcall Timer_ballTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
