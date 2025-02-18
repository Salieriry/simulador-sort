object FormGraficos: TFormGraficos
  Left = 0
  Top = 0
  Caption = 'FormGraficos'
  ClientHeight = 530
  ClientWidth = 1246
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ChartComparacoes: TChart
    Left = 24
    Top = 41
    Width = 400
    Height = 481
    Legend.Visible = False
    Title.Color = clBlack
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      'Estat'#237'sticas de Compara'#231#227'o na Ordena'#231#227'o')
    LeftAxis.Title.Caption = 'N'#250'mero de Compara'#231#245'es'
    RightAxis.Title.Position = tpStart
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      29
      15
      29
      15)
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object ChartTrocas: TChart
    Left = 430
    Top = 41
    Width = 400
    Height = 481
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      'Estat'#237'sticas de Troca de Valores na Ordena'#231#227'o')
    LeftAxis.Title.Caption = 'N'#250'mero de Trocas'
    TabOrder = 1
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      Legend.Visible = False
      ShowInLegend = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object ChartTempo: TChart
    Left = 836
    Top = 41
    Width = 400
    Height = 481
    Title.Font.Color = clBlack
    Title.Text.Strings = (
      'Estat'#237'sticas de Tempo na Ordena'#231#227'o')
    LeftAxis.Title.Caption = 'Tempo (ms)'
    TabOrder = 2
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series3: TBarSeries
      Legend.Visible = False
      ShowInLegend = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
end
