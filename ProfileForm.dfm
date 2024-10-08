object Form8: TForm8
  Left = 36
  Top = 73
  Caption = #1055#1088#1086#1092#1110#1083#1100
  ClientHeight = 539
  ClientWidth = 1599
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  TextHeight = 15
  object LabelUsername: TLabel
    Left = 8
    Top = 8
    Width = 43
    Height = 33
    Caption = #1055#1030#1041
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 72
    Width = 79
    Height = 33
    Caption = #1055#1086#1096#1090#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 136
    Width = 100
    Height = 33
    Caption = #1058#1077#1083#1077#1092#1086#1085
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 275
    Width = 66
    Height = 33
    Caption = #1051#1086#1075#1110#1085
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 344
    Width = 86
    Height = 33
    Caption = #1055#1072#1088#1086#1083#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 208
    Width = 139
    Height = 33
    Caption = #1054#1088#1075#1072#1085#1110#1079#1072#1094#1110#1103
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object EditUserName: TEdit
    Left = 175
    Top = 5
    Width = 233
    Height = 41
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object ButtonEditName: TButton
    Left = 422
    Top = 5
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonEditNameClick
  end
  object ButtonSaveName: TButton
    Left = 559
    Top = 5
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonSaveNameClick
  end
  object EditEmail: TEdit
    Left = 175
    Top = 69
    Width = 233
    Height = 41
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ButtonEditEmail: TButton
    Left = 422
    Top = 69
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonEditEmailClick
  end
  object ButtonSaveEmail: TButton
    Left = 559
    Top = 69
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = ButtonSaveEmailClick
  end
  object EditPhone: TEdit
    Left = 175
    Top = 133
    Width = 233
    Height = 41
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 6
  end
  object ButtonPhoneNumber: TButton
    Left = 422
    Top = 133
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ButtonPhoneNumberClick
  end
  object ButtonSavePhoneNumber: TButton
    Left = 559
    Top = 133
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = ButtonSavePhoneNumberClick
  end
  object EditLogin: TEdit
    Left = 175
    Top = 272
    Width = 233
    Height = 41
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object ButtonEditLogin: TButton
    Left = 422
    Top = 272
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = ButtonEditLoginClick
  end
  object ButtonSaveLogin: TButton
    Left = 559
    Top = 272
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = ButtonSaveLoginClick
  end
  object EditPassword: TEdit
    Left = 175
    Top = 341
    Width = 233
    Height = 41
    DoubleBuffered = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    PasswordChar = '*'
    TabOrder = 12
  end
  object ButtonExit: TButton
    Left = 232
    Top = 429
    Width = 193
    Height = 68
    Caption = #1042#1080#1081#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImageAlignment = iaRight
    ImageIndex = 8
    ImageMargins.Top = 2
    ImageMargins.Right = 20
    Images = DataModule1.ImageList1
    ParentFont = False
    TabOrder = 13
    OnClick = ButtonExitClick
  end
  object ButtonSavePassword: TButton
    Left = 559
    Top = 341
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    OnClick = ButtonSavePasswordClick
  end
  object ButtonEditPassword: TButton
    Left = 422
    Top = 341
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
    OnClick = ButtonEditPasswordClick
  end
  object MemoHistory: TMemo
    Left = 700
    Top = 8
    Width = 891
    Height = 513
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    Lines.Strings = (
      'MemoHistory')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 16
  end
  object ButtonEditOrganizations: TButton
    Left = 422
    Top = 205
    Width = 120
    Height = 41
    Caption = #1047#1084#1110#1085#1080#1090#1080
    Default = True
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
    OnClick = ButtonEditOrganizationsClick
  end
  object ButtonSaveOrganizations: TButton
    Left = 559
    Top = 205
    Width = 120
    Height = 41
    Caption = #1047#1073#1077#1088#1077#1075#1090#1080
    Default = True
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
    OnClick = ButtonSaveOrganizationsClick
  end
  object ComboBoxOrg: TComboBox
    Left = 175
    Top = 205
    Width = 233
    Height = 41
    Style = csDropDownList
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 19
  end
  object MainMenu1: TMainMenu
    Left = 584
    Top = 384
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
  end
end
