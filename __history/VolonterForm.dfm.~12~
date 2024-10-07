object Form4: TForm4
  Left = 234
  Top = 146
  Caption = 'Volonter '
  ClientHeight = 784
  ClientWidth = 1403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnShow = FormShow
  TextHeight = 15
  object LabelWelcom: TLabel
    Left = 0
    Top = 0
    Width = 1403
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
    Width = 1403
    Height = 55
    Align = alTop
    Alignment = taCenter
    Caption = 'Active Tasks'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 258
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 110
    Width = 1403
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
    Width = 225
    Height = 51
    Caption = 'Show Active Requests'
    TabOrder = 1
    OnClick = ButtonShowRequestsClick
  end
  object ButtonDonate: TButton
    Left = 328
    Top = 446
    Width = 241
    Height = 51
    Hint = 'First chose a row on table '
    Caption = 'DONATE'
    Enabled = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = ButtonDonateClick
  end
  object Button1: TButton
    Left = 680
    Top = 446
    Width = 241
    Height = 51
    Hint = 'First chose a row on table '
    Caption = 'Profile'
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
      Caption = 'Reference'
      object Help1: TMenuItem
        Caption = 'Help'
      end
      object Help2: TMenuItem
        Caption = 'About us'
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
