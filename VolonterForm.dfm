object Form4: TForm4
  Left = 234
  Top = 146
  BorderStyle = bsSingle
  Caption = 'Volonter '
  ClientHeight = 554
  ClientWidth = 951
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  OnShow = FormShow
  TextHeight = 15
  object LabelWelcom: TLabel
    Left = 0
    Top = 0
    Width = 951
    Height = 55
    Align = alTop
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 12
  end
  object LabelRequests: TLabel
    Left = 0
    Top = 55
    Width = 951
    Height = 55
    Align = alTop
    Alignment = taCenter
    Caption = #1040#1082#1090#1080#1074#1085#1110' '#1079#1072#1087#1080#1090#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 342
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 110
    Width = 951
    Height = 330
    Hint = #1041#1091#1076#1100' '#1083#1072#1089#1082#1072', '#1074#1080#1073#1077#1088#1110#1090#1100' '#1088#1103#1076#1086#1082' '#1091' '#1090#1072#1073#1083#1080#1094#1110', '#1097#1086#1073' '#1087#1088#1086#1076#1086#1074#1078#1080#1090#1080
    Align = alTop
    DataSource = DataModule1.DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentShowHint = False
    ReadOnly = True
    ShowHint = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
  end
  object ButtonShowRequests: TButton
    Left = 0
    Top = 446
    Width = 233
    Height = 51
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1079#1072#1087#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 2
    ImageMargins.Top = 3
    ImageMargins.Right = 5
    Images = DataModule1.ImageList1
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonShowRequestsClick
  end
  object ButtonDonate: TButton
    Left = 360
    Top = 446
    Width = 193
    Height = 51
    Hint = 'First chose a row on table '
    Caption = #1044#1086#1085#1072#1090
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 7
    ImageMargins.Right = 20
    Images = DataModule1.ImageList1
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = ButtonDonateClick
  end
  object Button1: TButton
    Left = 704
    Top = 446
    Width = 241
    Height = 51
    Hint = 'First chose a row on table '
    Caption = #1055#1088#1086#1092#1110#1083#1100
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 10
    ImageMargins.Top = 2
    ImageMargins.Right = 20
    Images = DataModule1.ImageList1
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnClick = Button1Click
  end
  object MainMenu1: TMainMenu
    Left = 728
    Top = 408
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
    object Close2: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      object Help1: TMenuItem
        Caption = #1044#1086#1087#1086#1084#1086#1075#1072
        ShortCut = 112
      end
      object Help2: TMenuItem
        Caption = #1055#1088#1086' '#1085#1072#1089
        ShortCut = 113
      end
    end
    object ChangeUser1: TMenuItem
      Action = DataModule1.ActionChangeUser
    end
  end
  object BalloonHint1: TBalloonHint
    HideAfter = 3000
    Position = hpBelow
    Left = 616
    Top = 472
  end
end
