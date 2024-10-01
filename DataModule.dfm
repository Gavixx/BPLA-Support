object DataModule1: TDataModule1
  Height = 1080
  Width = 1440
  PixelsPerInch = 144
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=admin'
      'Password=admin'
      'Server=192.168.11.3'
      'Database=Drone_Management'
      'CharacterSet=utf8'
      'DriverID=MyPhysDriver')
    Left = 128
    Top = 312
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MyPhysDriver'
    Left = 88
    Top = 536
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT username FROM Users WHERE user_id = :id')
    Left = 672
    Top = 296
    ParamData = <
      item
        Name = 'ID'
        ParamType = ptInput
      end>
  end
  object ActionManager1: TActionManager
    Left = 1112
    Top = 560
    StyleName = 'Platform Default'
    object ActionChangeUser: TAction
      Caption = 'Change User'
      OnExecute = ActionChangeUserExecute
    end
    object ActionHelp: TAction
      Caption = 'Help'
      OnExecute = ActionHelpExecute
    end
    object ActionAboutUs: TAction
      Caption = 'About Us'
      OnExecute = ActionAboutUsExecute
    end
    object ActionClose: TAction
      Caption = 'Close'
      OnExecute = ActionCloseExecute
    end
  end
  object DataSource1: TDataSource
    Left = 488
    Top = 304
  end
end
