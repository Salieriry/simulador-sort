#ifndef UFormGraficosH
#define UFormGraficosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include "Unit1.h" // Para incluir a defini��o de Estatisticas
//---------------------------------------------------------------------------
class TFormGraficos : public TForm
{
__published: // IDE-managed Components
    TChart *ChartComparacoes;
    TChart *ChartTrocas;
    TChart *ChartTempo;
    TBarSeries *Series3;
	TBarSeries *Series1;
	TBarSeries *Series2;

private: // User declarations
public:  // User declarations
    __fastcall TFormGraficos(TComponent* Owner);
    void TFormGraficos::exibirEstatisticas(Estatisticas estatisticas[]);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGraficos *FormGraficos;
//---------------------------------------------------------------------------
#endif

