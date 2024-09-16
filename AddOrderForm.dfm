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
    Left = 208
    Top = 352
    Width = 305
    Height = 25
    Caption = 'Add'
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object LabeledEditQuantity: TLabeledEdit
    Left = 392
    Top = 232
    Width = 121
    Height = 23
    EditLabel.Width = 46
    EditLabel.Height = 15
    EditLabel.Caption = 'Quantity'
    TabOrder = 1
    Text = ''
  end
  object LabeledEditDroneType: TLabeledEdit
    Left = 216
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
    Left = 240
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
