object Form1: TForm1
  Left = 543
  Top = 171
  Caption = 'Login'
  ClientHeight = 730
  ClientWidth = 950
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  TextHeight = 15
  object EnterLoginLabel: TLabel
    Left = 172
    Top = 272
    Width = 237
    Height = 41
    Caption = 'Enter your login:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object EnterPasswordLabel: TLabel
    Left = 172
    Top = 368
    Width = 303
    Height = 41
    Caption = 'Enter your password:'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object StaticText1: TStaticText
    Left = 365
    Top = 160
    Width = 212
    Height = 45
    Caption = 'Authorization'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object EditLogin: TEdit
    Left = 500
    Top = 269
    Width = 174
    Height = 49
    Alignment = taCenter
    Color = clHighlightText
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object EditPassword: TEdit
    Left = 500
    Top = 365
    Width = 174
    Height = 49
    Alignment = taCenter
    Color = clHighlightText
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    PasswordChar = '*'
    ShowHint = False
    TabOrder = 2
  end
  object LoginButton: TButton
    Left = 375
    Top = 500
    Width = 200
    Height = 75
    Cursor = crHandPoint
    Caption = 'Sign in'
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 3
    OnClick = LoginButtonClick
  end
  object MainMenu1: TMainMenu
    Left = 856
    Top = 632
    object Reference1: TMenuItem
      Caption = 'Reference'
      object Help1: TMenuItem
        Action = DataModule1.ActionHelp
        ShortCut = 112
      end
      object AboutUs1: TMenuItem
        Action = DataModule1.ActionAboutUs
        ShortCut = 113
      end
    end
    object close1: TMenuItem
      Action = DataModule1.ActionClose
      ShortCut = 32883
    end
  end
end
