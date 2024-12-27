object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Simulador de Algorimos de Ordena'#231#227'o'
  ClientHeight = 540
  ClientWidth = 1003
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 10
    Top = 88
    Width = 985
    Height = 331
    Legend.Visible = False
    Title.Text.Strings = (
      'TChart')
    ParentColor = True
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      Marks.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Panel3: TPanel
    Left = 8
    Top = 8
    Width = 185
    Height = 65
    ParentColor = True
    TabOrder = 1
    object Label1: TLabel
      Left = 8
      Top = 14
      Width = 109
      Height = 13
      Caption = 'Quantidade de Valores'
    end
    object btnValueGen: TButton
      Left = 40
      Top = 33
      Width = 105
      Height = 25
      Caption = 'Gerar Valores'
      TabOrder = 0
      OnClick = evGerarValores
    end
    object tbValor: TEdit
      Left = 129
      Top = 6
      Width = 48
      Height = 21
      ParentColor = True
      TabOrder = 1
      OnKeyPress = evApenasNumeros
    end
  end
  object Panel4: TPanel
    Left = 199
    Top = 8
    Width = 410
    Height = 65
    ParentColor = True
    TabOrder = 2
    object Label2: TLabel
      Left = 16
      Top = 14
      Width = 264
      Height = 13
      Caption = 'Escolha o m'#233'todo com o qual deseja fazer a ordena'#231#227'o'
    end
    object Button2: TButton
      Left = 304
      Top = 9
      Width = 89
      Height = 47
      Caption = 'Ordenar Valores'
      TabOrder = 0
      OnClick = evOrdenarValores
    end
  end
  object Panel6: TPanel
    Left = 8
    Top = 425
    Width = 89
    Height = 107
    ParentColor = True
    TabOrder = 3
    object Label3: TLabel
      Left = 8
      Top = 8
      Width = 65
      Height = 13
      Caption = 'Compara'#231#245'es'
    end
    object Label4: TLabel
      Left = 8
      Top = 58
      Width = 32
      Height = 13
      Caption = 'Trocas'
    end
    object tbComparacao: TEdit
      Left = 8
      Top = 27
      Width = 73
      Height = 21
      Enabled = False
      ParentColor = True
      TabOrder = 0
    end
    object tbTrocas: TEdit
      Left = 8
      Top = 77
      Width = 73
      Height = 21
      Enabled = False
      ParentColor = True
      TabOrder = 1
    end
  end
  object cbSort: TComboBox
    Left = 215
    Top = 41
    Width = 264
    Height = 21
    ItemIndex = 0
    ParentColor = True
    TabOrder = 4
    Text = 'Bubble Sort'
    Items.Strings = (
      'Bubble Sort'
      'Insertion Sort'
      'Shell Sort'
      'Selection Sort '
      'Merge Sort'
      'Quick Sort'
      'Heap Sort ')
  end
  object Panel7: TPanel
    Left = 729
    Top = 8
    Width = 266
    Height = 65
    ParentColor = True
    TabOrder = 5
    object Label5: TLabel
      Left = 8
      Top = 12
      Width = 89
      Height = 13
      Caption = 'Valor para a busca'
    end
    object tbBusca: TEdit
      Left = 103
      Top = 8
      Width = 74
      Height = 21
      ParentColor = True
      TabOrder = 0
      OnKeyPress = evApenasNumeros
    end
    object Button10: TButton
      Left = 183
      Top = 8
      Width = 75
      Height = 52
      Caption = 'Buscar Valor'
      TabOrder = 1
      OnClick = evBuscarValor
    end
    object cbBusca: TComboBox
      Left = 8
      Top = 35
      Width = 169
      Height = 21
      ParentColor = True
      TabOrder = 2
      Text = 'Escolha um m'#233'todo de busca...'
      Items.Strings = (
        'Linear Search'
        'Binary Search')
    end
  end
  object reResultados: TRichEdit
    Left = 103
    Top = 425
    Width = 699
    Height = 107
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = True
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 6
    Zoom = 100
  end
  object Panel1: TPanel
    Left = 615
    Top = 8
    Width = 108
    Height = 65
    TabOrder = 7
    object btnVoltarOriginal: TButton
      Left = 8
      Top = 9
      Width = 89
      Height = 48
      Caption = 'Original'
      TabOrder = 0
      OnClick = evTrocarOriginal
    end
  end
  object Panel5: TPanel
    Left = 904
    Top = 425
    Width = 91
    Height = 107
    TabOrder = 8
    object Button9: TButton
      Left = 8
      Top = 72
      Width = 75
      Height = 25
      Caption = 'Sair'
      TabOrder = 0
      OnClick = evSair
    end
    object Button8: TButton
      Left = 8
      Top = 41
      Width = 75
      Height = 25
      Caption = 'Limpar'
      TabOrder = 1
      OnClick = evLimpar
    end
    object btnMostrarValores: TButton
      Left = 8
      Top = 10
      Width = 75
      Height = 25
      Caption = 'Exibir Valores'
      TabOrder = 2
      OnClick = evMostrarValores
    end
  end
  object Panel2: TPanel
    Left = 808
    Top = 425
    Width = 90
    Height = 107
    TabOrder = 9
    object Button4: TButton
      Left = 7
      Top = 10
      Width = 75
      Height = 25
      Caption = 'Estat'#237'sticas'
      TabOrder = 0
      OnClick = evAbrirEstatisticas
    end
    object btnOptions: TButton
      Left = 8
      Top = 41
      Width = 73
      Height = 25
      Caption = 'Op'#231#245'es'
      TabOrder = 1
      OnClick = evAbrirOpcoes
    end
    object Button1: TButton
      Left = 8
      Top = 72
      Width = 73
      Height = 25
      Caption = 'Cr'#233'ditos'
      TabOrder = 2
      OnClick = evCreditos
    end
  end
end
