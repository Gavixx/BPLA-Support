object Form8: TForm8
  Left = 126
  Top = 128
  Caption = 'Form8'
  ClientHeight = 444
  ClientWidth = 1599
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnCreate = FormCreate
  TextHeight = 15
  object LabelUsername: TLabel
    Left = 8
    Top = 8
    Width = 116
    Height = 33
    Caption = 'User name'
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
    Width = 65
    Height = 33
    Caption = 'Email'
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
    Width = 160
    Height = 33
    Caption = 'Phone number'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 203
    Width = 65
    Height = 33
    Caption = 'Login'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 272
    Width = 106
    Height = 33
    Caption = 'Password'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object EditUserName: TEdit
    Left = 197
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
    Left = 454
    Top = 5
    Width = 97
    Height = 41
    Caption = 'Edit'
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
    Left = 582
    Top = 5
    Width = 97
    Height = 41
    Caption = 'Save'
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
    Left = 197
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
    Left = 454
    Top = 69
    Width = 97
    Height = 41
    Caption = 'Edit'
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
    Left = 582
    Top = 69
    Width = 97
    Height = 41
    Caption = 'Save'
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
    Left = 197
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
    Left = 454
    Top = 133
    Width = 97
    Height = 41
    Caption = 'Edit'
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
    Left = 582
    Top = 133
    Width = 97
    Height = 41
    Caption = 'Save'
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
    Left = 197
    Top = 200
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
    Left = 454
    Top = 200
    Width = 97
    Height = 41
    Caption = 'Edit'
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
    Left = 582
    Top = 200
    Width = 97
    Height = 41
    Caption = 'Save'
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
    Left = 197
    Top = 269
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
    Left = 8
    Top = 333
    Width = 671
    Height = 100
    Caption = 'Exit'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = ButtonExitClick
  end
  object ButtonSavePassword: TButton
    Left = 582
    Top = 269
    Width = 97
    Height = 41
    Caption = 'Save'
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
    Left = 454
    Top = 269
    Width = 97
    Height = 41
    Caption = 'Edit'
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
    Left = 694
    Top = 5
    Width = 891
    Height = 428
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
  object MainMenu1: TMainMenu
    Left = 584
    Top = 384
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
  end
end
