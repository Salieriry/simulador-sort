object FormOptions: TFormOptions
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'FormOptions'
  ClientHeight = 278
  ClientWidth = 501
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 24
    Top = 8
    Width = 185
    Height = 184
    Caption = 'Par'#226'metros Gerais'
    TabOrder = 0
    object Label1: TLabel
      Left = 21
      Top = 127
      Width = 116
      Height = 13
      Caption = 'Valores quando gerados'
    end
    object rgMaxValue: TRadioGroup
      Left = 0
      Top = 16
      Width = 185
      Height = 105
      Caption = 'Valor M'#225'ximo'
      TabOrder = 0
    end
    object btnGrande: TRadioButton
      Left = 24
      Top = 40
      Width = 113
      Height = 17
      Caption = 'Grande'
      TabOrder = 1
    end
    object btnMedio: TRadioButton
      Left = 24
      Top = 63
      Width = 113
      Height = 17
      Caption = 'M'#233'dio'
      Checked = True
      TabOrder = 2
      TabStop = True
    end
    object btnPequeno: TRadioButton
      Left = 24
      Top = 86
      Width = 113
      Height = 17
      Caption = 'Pequeno'
      TabOrder = 3
    end
    object ComboBox1: TComboBox
      Left = 21
      Top = 146
      Width = 145
      Height = 21
      TabOrder = 4
      Text = 'Valores Aleat'#243'rios'
      Items.Strings = (
        'Valores Aleat'#243'rios'
        'Valores Equilibrados'
        'Valores Decrescentes')
    end
  end
  object GroupBox2: TGroupBox
    Left = 240
    Top = 8
    Width = 185
    Height = 217
    Caption = 'Velocidade'
    TabOrder = 1
    object rgCompareSpeed: TRadioGroup
      Left = 0
      Top = 16
      Width = 185
      Height = 105
      Caption = 'Compara'#231#227'o'
      TabOrder = 0
    end
    object btncompLenta: TRadioButton
      Left = 16
      Top = 40
      Width = 113
      Height = 17
      Caption = 'Lenta'
      TabOrder = 1
    end
    object btncompNormal: TRadioButton
      Left = 16
      Top = 63
      Width = 113
      Height = 17
      Caption = 'Normal'
      Checked = True
      TabOrder = 2
      TabStop = True
    end
    object btncompRapida: TRadioButton
      Left = 16
      Top = 86
      Width = 113
      Height = 17
      Caption = 'R'#225'pida'
      TabOrder = 3
    end
    object rgSwapSpeed: TRadioGroup
      Left = 0
      Top = 109
      Width = 185
      Height = 108
      Caption = 'Trocas'
      TabOrder = 4
    end
  end
  object btntrocaLenta: TRadioButton
    Left = 256
    Top = 146
    Width = 113
    Height = 17
    Caption = 'Lenta'
    TabOrder = 2
  end
  object btntrocaRapida: TRadioButton
    Left = 256
    Top = 192
    Width = 113
    Height = 17
    Caption = 'R'#225'pida'
    TabOrder = 3
  end
  object btntrocaNormal: TRadioButton
    Left = 256
    Top = 169
    Width = 113
    Height = 17
    Caption = 'Normal'
    Checked = True
    TabOrder = 4
    TabStop = True
  end
  object Button1: TButton
    Left = -8
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Confirmar'
    TabOrder = 5
    OnClick = evConfirmar
  end
  object Button2: TButton
    Left = 216
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 6
    OnClick = evCancelar
  end
  object Button3: TButton
    Left = 430
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Resetar'
    TabOrder = 7
    OnClick = evResetar
  end
end
