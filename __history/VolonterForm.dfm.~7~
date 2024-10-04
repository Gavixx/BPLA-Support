object Form4: TForm4
  Left = 234
  Top = 146
  Caption = 'Volonter '
  ClientHeight = 784
  ClientWidth = 1403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnShow = FormShow
  TextHeight = 15
  object LabelWelcom: TLabel
    Left = 0
    Top = 0
    Width = 1403
    Height = 55
    Align = alTop
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 12
  end
  object LabelRequests: TLabel
    Left = 0
    Top = 55
    Width = 1403
    Height = 55
    Align = alTop
    Alignment = taCenter
    Caption = 'Active Tasks'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
    ExplicitWidth = 258
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 110
    Width = 1403
    Height = 330
    Align = alTop
    DataSource = DataModule1.DataSource1
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
  end
  object ButtonShowRequests: TButton
    Left = 0
    Top = 446
    Width = 225
    Height = 51
    Caption = 'Show Active Requests'
    TabOrder = 1
    OnClick = ButtonShowRequestsClick
  end
  object ButtonDonate: TButton
    Left = 328
    Top = 446
    Width = 241
    Height = 51
    Hint = 'First chose a row on table '
    Caption = 'DONATE'
    Enabled = False
    TabOrder = 2
    OnClick = ButtonDonateClick
  end
  object MainMenu1: TMainMenu
    Left = 728
    Top = 408
    object Close1: TMenuItem
      Action = DataModule1.ActionClose
    end
    object Close2: TMenuItem
      Caption = 'Reference'
      object Help1: TMenuItem
        Caption = 'Help'
      end
      object Help2: TMenuItem
        Caption = 'About us'
      end
    end
    object ChangeUser1: TMenuItem
      Caption = 'Change User'
    end
  end
end
