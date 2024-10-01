object Form2: TForm2
  Left = 559
  Top = 182
  Caption = 'Admin panel'
  ClientHeight = 823
  ClientWidth = 1133
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  DesignSize = (
    1133
    823)
  TextHeight = 15
  object LabelFilter: TLabel
    Left = 25
    Top = 464
    Width = 473
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
  object DBGridUsers: TDBGrid
    Left = 8
    Top = 0
    Width = 1117
    Height = 385
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
    Width = 161
    Height = 41
    Caption = 'Show Users'
    ImageIndex = 0
    TabOrder = 1
    OnClick = ButtonShowUsersClick
  end
  object ButtonAddUser: TButton
    Left = 296
    Top = 400
    Width = 169
    Height = 41
    Caption = 'ButtonAddUser'
    TabOrder = 2
    OnClick = ButtonAddUserClick
  end
  object ButtonShowRequests: TButton
    Left = 942
    Top = 400
    Width = 183
    Height = 41
    Caption = 'Show requests'
    TabOrder = 3
    OnClick = ButtonShowRequestsClick
  end
  object DBGridRequests: TDBGrid
    Left = 8
    Top = 0
    Width = 1117
    Height = 385
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Visible = False
    OnTitleClick = DBGridUsersTitleClick
  end
  object ButtonFilter: TButton
    Left = 212
    Top = 729
    Width = 145
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
    TabOrder = 5
    ExplicitTop = 701
  end
  object ButtonClearFilter: TButton
    Left = 32
    Top = 729
    Width = 145
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
    TabOrder = 6
    ExplicitTop = 701
  end
  object CheckListBox1: TCheckListBox
    Left = 504
    Top = 447
    Width = 137
    Height = 73
    Color = clMenu
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ItemHeight = 33
    Items.Strings = (
      'Volonters'
      'Requests')
    ParentFont = False
    TabOrder = 7
  end
  object GroupBox1: TGroupBox
    Left = 13
    Top = 511
    Width = 344
    Height = 198
    Caption = 'Requests'
    Enabled = False
    TabOrder = 8
    object Label1: TLabel
      Left = 12
      Top = 31
      Width = 65
      Height = 15
      Caption = 'Drone name'
    end
    object Label2: TLabel
      Left = 12
      Top = 76
      Width = 58
      Height = 15
      Caption = 'Drone type'
    end
    object LabelFrom: TLabel
      Left = 12
      Top = 128
      Width = 28
      Height = 15
      Caption = 'From'
    end
    object Label3: TLabel
      Left = 200
      Top = 31
      Width = 32
      Height = 15
      Caption = 'Status'
    end
    object LabelTo: TLabel
      Left = 196
      Top = 128
      Width = 12
      Height = 15
      Caption = 'To'
    end
    object ComboBox1: TComboBox
      Left = 12
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 0
    end
    object ComboBox2: TComboBox
      Left = 12
      Top = 92
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 1
    end
    object DateTimePickerFrom: TDateTimePicker
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
    object ComboBox3: TComboBox
      Left = 196
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 3
    end
    object DateTimePickerTo: TDateTimePicker
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
  object GroupBox2: TGroupBox
    Left = 765
    Top = 511
    Width = 344
    Height = 198
    Caption = 'Volunter Contributions'
    Enabled = False
    TabOrder = 9
    object Label4: TLabel
      Left = 12
      Top = 31
      Width = 65
      Height = 15
      Caption = 'Drone name'
    end
    object Label5: TLabel
      Left = 12
      Top = 76
      Width = 58
      Height = 15
      Caption = 'Drone type'
    end
    object Label6: TLabel
      Left = 12
      Top = 128
      Width = 28
      Height = 15
      Caption = 'From'
    end
    object Label7: TLabel
      Left = 200
      Top = 31
      Width = 32
      Height = 15
      Caption = 'Status'
    end
    object Label8: TLabel
      Left = 196
      Top = 128
      Width = 12
      Height = 15
      Caption = 'To'
    end
    object ComboBox4: TComboBox
      Left = 12
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 0
    end
    object ComboBox5: TComboBox
      Left = 12
      Top = 92
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 1
    end
    object DateTimePicker1: TDateTimePicker
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
    object ComboBox6: TComboBox
      Left = 196
      Top = 47
      Width = 145
      Height = 23
      AutoComplete = False
      TabOrder = 3
    end
    object DateTimePicker2: TDateTimePicker
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
end
