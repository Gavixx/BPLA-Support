object Form7: TForm7
  Left = 1010
  Top = 201
  Caption = 'Form7'
  ClientHeight = 538
  ClientWidth = 568
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  TextHeight = 15
  object LabelMaxQuantity: TLabel
    Left = 8
    Top = 168
    Width = 148
    Height = 33
    Caption = 'MaxQuantity'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object LabelDroneName: TLabel
    Left = 8
    Top = 104
    Width = 195
    Height = 33
    Caption = 'LabelDroneName'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 237
    Width = 379
    Height = 33
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1082#1110#1083#1100#1082#1110#1089#1090#1100' '#1076#1083#1103' '#1074#1110#1076#1087#1088#1072#1074#1082#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -28
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object EditQuantity: TEdit
    Left = 410
    Top = 248
    Width = 145
    Height = 23
    TabOrder = 0
    OnKeyPress = EditQuantityKeyPress
  end
  object ButtonSend: TButton
    Left = 8
    Top = 336
    Width = 257
    Height = 113
    Caption = 'Send'
    TabOrder = 1
    OnClick = ButtonSendClick
  end
  object ButtonCancel: TButton
    Left = 298
    Top = 336
    Width = 257
    Height = 113
    Caption = 'Cancel'
    TabOrder = 2
    OnClick = ButtonCancelClick
  end
  object MainMenu1: TMainMenu
    Left = 376
    Top = 424
    object CLose1: TMenuItem
      Action = DataModule1.ActionClose
    end
    object CLose2: TMenuItem
      Caption = 'Reference'
      object Help1: TMenuItem
        Caption = 'Help'
      end
      object Help2: TMenuItem
        Caption = 'About us'
      end
    end
  end
end
