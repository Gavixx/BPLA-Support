object Form1: TForm1
  Left = 469
  Top = 201
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1110#1103
  ClientHeight = 456
  ClientWidth = 763
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  TextHeight = 15
  object EnterLoginLabel: TLabel
    Left = 108
    Top = 130
    Width = 213
    Height = 41
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1083#1086#1075#1110#1085':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object EnterPasswordLabel: TLabel
    Left = 108
    Top = 223
    Width = 239
    Height = 41
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1087#1072#1088#1086#1083#1100':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object StaticText1: TStaticText
    Left = 263
    Top = 48
    Width = 207
    Height = 45
    Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1110#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object EditLogin: TEdit
    Left = 401
    Top = 127
    Width = 217
    Height = 49
    Alignment = taCenter
    Color = clHighlightText
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    MaxLength = 100
    ParentFont = False
    TabOrder = 1
  end
  object EditPassword: TEdit
    Left = 401
    Top = 220
    Width = 217
    Height = 49
    Alignment = taCenter
    Color = clHighlightText
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -36
    Font.Name = 'Times New Roman'
    Font.Style = []
    MaxLength = 255
    ParentFont = False
    ParentShowHint = False
    PasswordChar = '*'
    ShowHint = False
    TabOrder = 2
  end
  object LoginButton: TButton
    Left = 263
    Top = 318
    Width = 200
    Height = 75
    Cursor = crHandPoint
    Caption = #1059#1074#1110#1081#1090#1080
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
    Left = 65528
    Top = 296
    object Reference1: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      object Help1: TMenuItem
        Action = DataModule1.ActionHelp
        Caption = #1044#1086#1087#1086#1084#1086#1075#1072
        ShortCut = 112
      end
      object AboutUs1: TMenuItem
        Action = DataModule1.ActionAboutUs
        Caption = #1055#1088#1086' '#1085#1072#1089
        ShortCut = 113
      end
    end
    object close1: TMenuItem
      Action = DataModule1.ActionClose
      Caption = #1047#1072#1082#1088#1080#1090#1080
      ShortCut = 32883
    end
  end
end
