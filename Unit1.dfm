object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 716
  ClientWidth = 950
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object StringGrid1: TStringGrid
    Left = 232
    Top = 312
    Width = 320
    Height = 120
    TabOrder = 0
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      'User_Name=admintest'
      'Password=admin'
      'Server=192.168.11.3'
      'Database=testdb'
      'DriverID=MyPhysDriver')
    Connected = True
    Left = 920
    Top = 648
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    DriverID = 'MyPhysDriver'
    VendorLib = 'C:\Users\Roman\Desktop\TRPZ\BPLA-Support\lib\libmysql.dll'
    Left = 920
    Top = 688
  end
end
