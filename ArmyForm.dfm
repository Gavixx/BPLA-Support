object Form3: TForm3
  Left = 487
  Top = 146
  Caption = 'Army'
  ClientHeight = 700
  ClientWidth = 959
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  DesignSize = (
    959
    700)
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
  object DBGrid1: TDBGrid
    Left = 16
    Top = 42
    Width = 926
    Height = 300
    Constraints.MaxHeight = 300
    Constraints.MaxWidth = 930
    DataSource = DataSource1
    DrawingStyle = gdsClassic
    FixedColor = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = RUSSIAN_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -24
    TitleFont.Name = 'Times New Roman'
    TitleFont.Style = []
    OnTitleClick = DBGrid1TitleClick
  end
  object ButtonShowStat: TButton
    Left = 16
    Top = 348
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
    TabOrder = 1
    OnClick = ButtonShowStatClick
  end
  object ButtonAddOrder: TButton
    Left = 701
    Top = 348
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
    TabOrder = 2
    OnClick = ButtonAddOrderClick
  end
  object ComboBoxDroneName: TComboBox
    Left = 32
    Top = 514
    Width = 145
    Height = 23
    TabOrder = 3
  end
  object ComboBoxDroneType: TComboBox
    Left = 200
    Top = 514
    Width = 145
    Height = 23
    TabOrder = 4
  end
  object ComboBoxStatus: TComboBox
    Left = 368
    Top = 514
    Width = 145
    Height = 23
    TabOrder = 5
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
    TabOrder = 6
  end
  object DateTimePickerEnd: TDateTimePicker
    Left = 740
    Top = 514
    Width = 186
    Height = 23
    Format = 'dd MMMM yyyy'
    Time = 0.885561087961832500
    DateFormat = dfLong
    TabOrder = 7
  end
  object ButtonFilter: TButton
    Left = 536
    Top = 584
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
    TabOrder = 8
    OnClick = ButtonFilterClick
  end
  object ButtonClearFilter: TButton
    Left = 200
    Top = 584
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
    TabOrder = 9
    OnClick = ButtonClearFilterClick
  end
  object FDQuery1: TFDQuery
    Left = 40
    Top = 656
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MyPhysDriver'
    VendorLib = 'C:\Users\Roman\Desktop\proj\BPLA-Support\lib\libmysql.dll'
    Left = 72
    Top = 656
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=admin'
      'Password=admin'
      'Server=192.168.11.3'
      'Database=Drone_Management'
      'DriverID=MyPhysDriver')
    Left = 104
    Top = 656
  end
  object DataSource1: TDataSource
    Left = 136
    Top = 656
  end
  object MainMenu1: TMainMenu
    Left = 856
    Top = 616
    object ChangeUser1: TMenuItem
      Caption = 'Change User'
      ShortCut = 113
      OnClick = ChangeUser1Click
    end
    object MenuHelp: TMenuItem
      Caption = 'Reference'
      ShortCut = 112
      object Help1: TMenuItem
        Caption = 'Help'
        OnClick = Help1Click
      end
      object Help2: TMenuItem
        Caption = 'About us'
        OnClick = Help2Click
      end
    end
    object MenuClose: TMenuItem
      Caption = 'Close'
      ShortCut = 32883
      OnClick = MenuCloseClick
    end
  end
end
