object Form6: TForm6
  Left = 613
  Top = 219
  Caption = 'Form6'
  ClientHeight = 411
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  TextHeight = 15
  object LabelName: TLabel
    Left = 32
    Top = 131
    Width = 61
    Height = 15
    Caption = 'Input name'
  end
  object Label1: TLabel
    Left = 32
    Top = 179
    Width = 54
    Height = 15
    Caption = 'Input mail'
  end
  object Label2: TLabel
    Left = 33
    Top = 214
    Width = 114
    Height = 15
    Caption = 'Input phone mumber'
  end
  object EditName: TEdit
    Left = 171
    Top = 128
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object EditMail: TEdit
    Left = 171
    Top = 171
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object EditNumber: TEdit
    Left = 171
    Top = 211
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object ButtonAddUser: TButton
    Left = 123
    Top = 288
    Width = 169
    Height = 25
    Caption = 'Add'
    TabOrder = 3
    OnClick = ButtonAddUserClick
  end
  object MainMenu1: TMainMenu
    Left = 560
    Top = 253
    object Reference1: TMenuItem
      Caption = 'Reference'
      object Help1: TMenuItem
        Action = DataModule1.ActionHelp
      end
      object Aboutus1: TMenuItem
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
