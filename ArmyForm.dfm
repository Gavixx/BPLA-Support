object Form3: TForm3
  Left = 487
  Top = 146
  Caption = 'Army'
  ClientHeight = 690
  ClientWidth = 1079
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  DesignSize = (
    1079
    690)
  TextHeight = 15
  object LabelFilter: TLabel
    Left = 258
    Top = 458
    Width = 464
    Height = 36
    Caption = 'CHOSE FILTER PARAMETERS'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Layout = tlCenter
  end
  object ButtonShowStat: TButton
    Left = 23
    Top = 343
    Width = 241
    Height = 65
    Anchors = []
    Caption = #1054#1073#1085#1086#1074#1080#1090#1080
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonShowStatClick
  end
  object ButtonAddOrder: TButton
    Left = 809
    Top = 343
    Width = 241
    Height = 65
    Anchors = []
    Caption = #1044#1086#1076#1072#1090#1080' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonAddOrderClick
  end
  object ComboBoxDroneName: TComboBox
    Left = 32
    Top = 514
    Width = 145
    Height = 23
    AutoComplete = False
    TabOrder = 2
  end
  object ComboBoxDroneType: TComboBox
    Left = 200
    Top = 514
    Width = 145
    Height = 23
    AutoComplete = False
    TabOrder = 3
  end
  object ComboBoxStatus: TComboBox
    Left = 368
    Top = 514
    Width = 145
    Height = 23
    AutoComplete = False
    TabOrder = 4
  end
  object DateTimePickerStart: TDateTimePicker
    Left = 536
    Top = 514
    Width = 186
    Height = 23
    Date = 45292.000000000000000000
    Format = 'dd MMMM yyyy'
    Time = 0.885561087961832500
    DateFormat = dfLong
    TabOrder = 5
  end
  object DateTimePickerEnd: TDateTimePicker
    Left = 740
    Top = 514
    Width = 186
    Height = 23
    Date = 45560.000000000000000000
    Format = 'dd MMMM yyyy'
    Time = 0.885561087961832500
    DateFormat = dfLong
    TabOrder = 6
  end
  object ButtonFilter: TButton
    Left = 576
    Top = 575
    Width = 241
    Height = 65
    Anchors = []
    Caption = 'Filter'
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonFilterClick
  end
  object ButtonClearFilter: TButton
    Left = 262
    Top = 567
    Width = 241
    Height = 65
    Anchors = []
    Caption = 'Clear Filers'
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = ButtonClearFilterClick
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 1063
    Height = 297
    TabOrder = 9
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
  end
  object MainMenu1: TMainMenu
    Left = 904
    Top = 600
    object ChangeUser1: TMenuItem
      Action = DataModule1.ActionChangeUser
    end
    object MenuHelp: TMenuItem
      Caption = 'Reference'
      ShortCut = 112
      object Help1: TMenuItem
        Action = DataModule1.ActionHelp
      end
      object Help2: TMenuItem
        Action = DataModule1.ActionAboutUs
      end
    end
    object MenuClose: TMenuItem
      Action = DataModule1.ActionClose
    end
  end
end
