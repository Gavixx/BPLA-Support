object Form5: TForm5
  Left = 577
  Top = 237
  Caption = 'Add Form'
  ClientHeight = 595
  ClientWidth = 729
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
  object LabelDroneType: TLabel
    Left = 238
    Top = 214
    Width = 59
    Height = 15
    Caption = 'Drone Type'
  end
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
    Left = 408
    Top = 232
    Width = 121
    Height = 23
    EditLabel.Width = 46
    EditLabel.Height = 15
    EditLabel.Caption = 'Quantity'
    TabOrder = 1
    Text = ''
    OnChange = LabeledEditQuantityChange
    OnKeyPress = LabeledEditQuantityKeyPress
  end
  object LabeledEditDroneName: TLabeledEdit
    Left = 80
    Top = 232
    Width = 121
    Height = 23
    EditLabel.Width = 67
    EditLabel.Height = 15
    EditLabel.Caption = 'Drone Name'
    TabOrder = 2
    Text = ''
    OnChange = LabeledEditDroneNameChange
  end
  object DateTimePickerRequestDate: TDateTimePicker
    Left = 320
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
    Left = 238
    Top = 235
    Width = 145
    Height = 23
    TabOrder = 4
    OnChange = ComboBoxDroneTypeChange
    Items.Strings = (
      'Reconnaissance'
      'FPV'
      'Combat'
      'Logistics'
      'Surveillance')
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
  object MainMenu1: TMainMenu
    Left = 520
    Top = 424
    object Reference1: TMenuItem
      Caption = 'Reference'
      object Help1: TMenuItem
        Action = DataModule1.ActionHelp
      end
      object AboutUs1: TMenuItem
        Action = DataModule1.ActionAboutUs
      end
    end
    object ChangeUser1: TMenuItem
      Action = DataModule1.ActionChangeUser
    end
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
  end
end
