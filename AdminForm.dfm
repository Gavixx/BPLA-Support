object Form2: TForm2
  Left = 361
  Top = 36
  BorderStyle = bsSingle
  Caption = 'Admin panel'
  ClientHeight = 700
  ClientWidth = 1135
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    1135
    700)
  TextHeight = 15
  object LabelFilter: TLabel
    Left = 376
    Top = 487
    Width = 156
    Height = 36
    Caption = #1060#1110#1083#1100#1090#1088' '#1087#1086':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    Layout = tlCenter
  end
  object DBGridUsers: TDBGrid
    Left = 8
    Top = 0
    Width = 1117
    Height = 385
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnTitleClick = DBGridUsersTitleClick
  end
  object ButtonShowUsers: TButton
    Left = 8
    Top = 400
    Width = 189
    Height = 41
    Caption = #1042#1110#1076#1086#1073#1088#1072#1079#1080#1090#1080' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1110#1074
    Default = True
    DisabledImageIndex = 0
    ImageAlignment = iaRight
    ImageIndex = 2
    ImageMargins.Top = 2
    ImageMargins.Right = 10
    Images = DataModule1.ImageList1
    TabOrder = 1
    OnClick = ButtonShowUsersClick
  end
  object ButtonShowRequests: TButton
    Left = 461
    Top = 400
    Width = 183
    Height = 41
    Caption = #1042#1110#1076#1086#1073#1088#1072#1079#1080#1090#1080' '#1079#1072#1087#1080#1090#1080
    Default = True
    DisabledImageIndex = 0
    ImageAlignment = iaRight
    ImageIndex = 2
    ImageMargins.Top = 2
    ImageMargins.Right = 10
    Images = DataModule1.ImageList1
    TabOrder = 2
    OnClick = ButtonShowRequestsClick
  end
  object DBGridRequests: TDBGrid
    Left = 8
    Top = 0
    Width = 1117
    Height = 385
    ReadOnly = True
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Visible = False
    OnTitleClick = DBGridRequestsTitleClick
  end
  object ButtonFilter: TButton
    Left = 586
    Top = 597
    Width = 172
    Height = 65
    Anchors = []
    Caption = #1047#1072#1089#1090#1086#1089#1091#1074#1072#1090#1080
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 6
    ImageMargins.Top = 3
    ImageMargins.Right = 10
    Images = DataModule1.ImageList1
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonFilterClick
    ExplicitLeft = 590
  end
  object ButtonClearFilter: TButton
    Left = 372
    Top = 597
    Width = 175
    Height = 65
    Anchors = []
    Caption = #1054#1095#1080#1089#1090#1080#1090#1080
    Default = True
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 1
    ImageMargins.Top = 3
    ImageMargins.Right = 10
    Images = DataModule1.ImageList1
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonClearFilterClick
    ExplicitLeft = 374
  end
  object CheckListBoxChouse: TCheckListBox
    Left = 575
    Top = 473
    Width = 146
    Height = 73
    Color = clMenu
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ItemHeight = 33
    Items.Strings = (
      #1042#1085#1077#1089#1082#1080
      #1047#1072#1087#1080#1090#1080)
    ParentFont = False
    TabOrder = 6
    OnClickCheck = CheckListBoxChouseClickCheck
  end
  object GroupBoxRequests: TGroupBox
    Left = 8
    Top = 473
    Width = 356
    Height = 198
    Caption = #1047#1072#1087#1080#1090#1080
    Enabled = False
    TabOrder = 7
    object Label1: TLabel
      Left = 12
      Top = 31
      Width = 29
      Height = 15
      Caption = #1044#1088#1086#1085
    end
    object Label2: TLabel
      Left = 12
      Top = 76
      Width = 56
      Height = 15
      Caption = #1058#1080#1087' '#1076#1088#1086#1085#1091
    end
    object LabelFrom: TLabel
      Left = 12
      Top = 128
      Width = 7
      Height = 15
      Caption = #1047
    end
    object Label3: TLabel
      Left = 200
      Top = 31
      Width = 26
      Height = 15
      Caption = #1057#1090#1072#1085
    end
    object LabelTo: TLabel
      Left = 196
      Top = 128
      Width = 16
      Height = 15
      Caption = #1055#1086
    end
    object ComboBoxDroneName: TComboBox
      Left = 12
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 0
    end
    object ComboBoxDroneType: TComboBox
      Left = 12
      Top = 92
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 1
    end
    object DateTimePickerRequestsStart: TDateTimePicker
      Left = 12
      Top = 143
      Width = 145
      Height = 23
      Date = 45292.000000000000000000
      Format = 'dd MMMM yyyy'
      Time = 0.885561087961832500
      DateFormat = dfLong
      TabOrder = 2
    end
    object ComboBoxStatus: TComboBox
      Left = 196
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 3
    end
    object DateTimePickerRequestsEnd: TDateTimePicker
      Left = 196
      Top = 143
      Width = 145
      Height = 23
      Date = 45560.000000000000000000
      Format = 'dd MMMM yyyy'
      Time = 0.885561087961832500
      DateFormat = dfLong
      TabOrder = 4
    end
  end
  object GroupBoxContributions: TGroupBox
    Left = 781
    Top = 473
    Width = 344
    Height = 198
    Caption = #1042#1085#1077#1089#1082#1080
    Enabled = False
    TabOrder = 8
    object Label4: TLabel
      Left = 12
      Top = 31
      Width = 64
      Height = 15
      Caption = #1050#1086#1088#1080#1089#1090#1091#1074#1072#1095
    end
    object Label5: TLabel
      Left = 12
      Top = 76
      Width = 29
      Height = 15
      Caption = #1044#1088#1086#1085
    end
    object Label6: TLabel
      Left = 12
      Top = 128
      Width = 7
      Height = 15
      Caption = #1047
    end
    object Label7: TLabel
      Left = 200
      Top = 31
      Width = 64
      Height = 15
      Caption = #1054#1088#1075#1072#1085#1110#1079#1072#1094#1110#1103
    end
    object Label8: TLabel
      Left = 196
      Top = 128
      Width = 16
      Height = 15
      Caption = #1055#1086
    end
    object Label9: TLabel
      Left = 196
      Top = 76
      Width = 56
      Height = 15
      Caption = #1058#1080#1087' '#1076#1088#1086#1085#1072
    end
    object ComboBoxUserName: TComboBox
      Left = 12
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 0
    end
    object ComboBoxDroName: TComboBox
      Left = 12
      Top = 92
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 1
    end
    object DateTimePickerContributionsStart: TDateTimePicker
      Left = 12
      Top = 143
      Width = 145
      Height = 23
      Date = 45292.000000000000000000
      Format = 'dd MMMM yyyy'
      Time = 0.885561087961832500
      DateFormat = dfLong
      TabOrder = 2
    end
    object ComboBoxOrg: TComboBox
      Left = 196
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 3
    end
    object DateTimePickerContributionsEnd: TDateTimePicker
      Left = 196
      Top = 143
      Width = 145
      Height = 23
      Date = 45560.000000000000000000
      Format = 'dd MMMM yyyy'
      Time = 0.885561087961832500
      DateFormat = dfLong
      TabOrder = 4
    end
    object ComboBoxDroType: TComboBox
      Left = 196
      Top = 92
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 5
    end
  end
  object ButtonShowContributions: TButton
    Left = 942
    Top = 400
    Width = 183
    Height = 41
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1074#1085#1077#1089#1082#1080
    Default = True
    ImageAlignment = iaRight
    ImageIndex = 2
    ImageMargins.Top = 2
    ImageMargins.Right = 10
    Images = DataModule1.ImageList1
    TabOrder = 9
    OnClick = ButtonShowContributionsClick
  end
  object DBGridContributions: TDBGrid
    Left = 8
    Top = 0
    Width = 1117
    Height = 385
    ReadOnly = True
    TabOrder = 10
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Visible = False
    OnTitleClick = DBGridContributionsTitleClick
  end
  object MainMenu1: TMainMenu
    Left = 800
    Top = 416
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
    object Close2: TMenuItem
      Action = DataModule1.ActionChangeUser
    end
    object Extra1: TMenuItem
      Caption = #1044#1086#1076#1072#1090#1082#1086#1074#1086
      object AddUser: TMenuItem
        Caption = #1044#1086#1076#1072#1090#1080' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
        ShortCut = 16469
        OnClick = AddUserClick
      end
      object AddOrg: TMenuItem
        Caption = #1044#1086#1076#1072#1090#1080' '#1086#1088#1075#1072#1085#1110#1079#1072#1094#1110#1102
        ShortCut = 16463
        OnClick = AddOrgClick
      end
      object DeleteUser: TMenuItem
        Caption = #1042#1080#1076#1072#1083#1080#1090#1080' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
        ShortCut = 16430
        OnClick = DeleteUserClick
      end
      object ChangeUserData: TMenuItem
        Caption = #1047#1084#1110#1085#1080#1090#1080' '#1076#1072#1085#1110' '#1082#1086#1088#1080#1089#1090#1091#1074#1072#1095#1072
        OnClick = ChangeUserDataClick
      end
      object AddRequests: TMenuItem
        Caption = #1044#1086#1076#1072#1090#1080' '#1079#1072#1087#1080#1090
        ShortCut = 16466
        OnClick = AddRequestsClick
      end
    end
    object Reference: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      object N1: TMenuItem
        Action = DataModule1.ActionHelp
      end
      object N2: TMenuItem
        Action = DataModule1.ActionAboutUs
      end
    end
  end
end
