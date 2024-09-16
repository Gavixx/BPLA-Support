object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Army'
  ClientHeight = 700
  ClientWidth = 950
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  DesignSize = (
    950
    700)
  TextHeight = 15
  object DBGrid1: TDBGrid
    Left = 16
    Top = 8
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
    Left = 14
    Top = 314
    Width = 241
    Height = 65
    Anchors = []
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1079#1072#1084#1086#1074#1083#1077#1085#1085#1103
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
    Left = 300
    Top = 314
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
  object FDQuery1: TFDQuery
    Left = 760
    Top = 544
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MyPhysDriver'
    VendorLib = 'C:\Users\Roman\Desktop\proj\BPLA-Support\lib\libmysql.dll'
    Left = 672
    Top = 600
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=admin'
      'Password=admin'
      'Server=192.168.11.3'
      'Database=Drone_Management'
      'DriverID=MyPhysDriver')
    Left = 816
    Top = 624
  end
  object DataSource1: TDataSource
    Left = 912
    Top = 624
  end
end
