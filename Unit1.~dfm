object Form1: TForm1
  Left = 409
  Top = 128
  Width = 935
  Height = 553
  Caption = 'Ping Pong'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object tlo: TShape
    Left = 0
    Top = 0
    Width = 919
    Height = 514
    Align = alClient
    Brush.Color = clGreen
    ParentShowHint = False
    Pen.Style = psClear
    ShowHint = False
  end
  object PL: TShape
    Left = 64
    Top = 160
    Width = 30
    Height = 150
    Brush.Color = clBlack
    Pen.Color = clGreen
    Pen.Width = 2
  end
  object PP: TShape
    Left = 664
    Top = 160
    Width = 30
    Height = 150
    Brush.Color = clBlack
    Pen.Width = 2
  end
  object ball: TShape
    Left = 88
    Top = 80
    Width = 30
    Height = 30
    Brush.Color = clAqua
    Shape = stCircle
  end
  object Label2: TLabel
    Left = 343
    Top = 192
    Width = 119
    Height = 33
    Alignment = taCenter
    Caption = 'Ilosc odbic:'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = '@Arial Unicode MS'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object wynik: TLabel
    Left = 383
    Top = 144
    Width = 43
    Height = 41
    Alignment = taCenter
    Caption = '0:0'
    Color = clBtnFace
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clBlack
    Font.Height = -31
    Font.Name = '@Arial Unicode MS'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object points: TLabel
    Left = 184
    Top = 40
    Width = 424
    Height = 43
    Alignment = taCenter
    Caption = '<= Punkt dla gracza lewego'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = '@Arial Unicode MS'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 152
    Top = 96
    Width = 497
    Height = 37
    Alignment = taCenter
    Caption = 'Zapraszam do gry w PingPonga!'
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
  end
  object newGame: TButton
    Left = 256
    Top = 320
    Width = 300
    Height = 60
    Cursor = crHandPoint
    Caption = 'Nowa gra'
    DragCursor = crHandPoint
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = '@Arial Unicode MS'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    TabOrder = 0
    OnClick = newGameClick
  end
  object nextRound: TButton
    Left = 256
    Top = 248
    Width = 300
    Height = 60
    Caption = 'Nast'#281'pna rudna'
    DragCursor = crHandPoint
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clBlack
    Font.Height = -32
    Font.Name = '@Arial Unicode MS'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
    TabOrder = 1
    Visible = False
    OnClick = nextRoundClick
  end
  object TimerTop_PL: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerTop_PLTimer
    Left = 16
    Top = 24
  end
  object TimerBottom_PL: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerBottom_PLTimer
    Left = 16
    Top = 104
  end
  object TimerTop_PP: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerTop_PPTimer
    Left = 744
    Top = 32
  end
  object TimerBottom_PP: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerBottom_PPTimer
    Left = 744
    Top = 96
  end
  object Timer_ball: TTimer
    Enabled = False
    Interval = 20
    OnTimer = Timer_ballTimer
    Left = 400
    Top = 16
  end
end
