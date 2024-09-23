object Form5: TForm5
  Left = 0
  Top = 0
  Caption = 'Add Form'
  ClientHeight = 595
  ClientWidth = 729
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object ButtonAdd: TButton
    Left = 136
    Top = 328
    Width = 305
    Height = 25
    Caption = 'Add'
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object LabeledEditQuantity: TLabeledEdit
    Left = 416
    Top = 232
    Width = 121
    Height = 23
    EditLabel.Width = 46
    EditLabel.Height = 15
    EditLabel.Caption = 'Quantity'
    TabOrder = 1
    Text = ''
  end
  object LabeledEditDroneName: TLabeledEdit
    Left = 80
    Top = 232
    Width = 121
    Height = 23
    EditLabel.Width = 59
    EditLabel.Height = 15
    EditLabel.Caption = 'Drone Type'
    TabOrder = 2
    Text = ''
  end
  object DateTimePickerRequestDate: TDateTimePicker
    Left = 176
    Top = 64
    Width = 185
    Height = 23
    Date = 45551.000000000000000000
    Time = 0.906328009259596000
    DoubleBuffered = False
    ParentDoubleBuffered = False
    TabOrder = 3
    Visible = False
  end
  object ComboBoxDroneType: TComboBox
    Left = 233
    Top = 232
    Width = 145
    Height = 23
    TabOrder = 4
    Items.Strings = (
      #1056#1086#1079#1074#1110#1076#1091#1074#1072#1083#1100#1085#1110
      'FPV'
      #1044#1083#1103' '#1089#1082#1080#1076#1091
      #1040#1090#1072#1082#1091#1102#1095#1110
      #1058#1088#1072#1085#1089#1087#1086#1088#1090#1085#1110)
  end
  object FDQuery1: TFDQuery
    Left = 240
    Top = 488
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MyPhysDriver'
    VendorLib = 'C:\Users\Roman\Desktop\proj\BPLA-Support\lib\libmysql.dll'
    Left = 200
    Top = 488
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=admin'
      'Password=admin'
      'Server=192.168.11.3'
      'Database=Drone_Management'
      'DriverID=MyPhysDriver')
    Left = 280
    Top = 488
  end
end
