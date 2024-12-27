//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------

// Vari�veis globais externas (declaradas em outro arquivo e usadas neste)
// Representam os atrasos em milissegundos para compara��es e trocas, utilizados na anima��o ou simula��o do algoritmo
extern int delayCompare; // Atraso para simular uma compara��o entre elementos
extern int delaySwap;    // Atraso para simular uma troca entre elementos

// Representa o valor m�ximo permitido para o tamanho do vetor ou valores gerados
extern int maxVal; // Limite superior do n�mero ou tamanho dos elementos no vetor

// Representa o modo de gera��o dos valores no vetor (aleat�rios, equilibrados ou decrescentes)
extern int modoGeracao; // Define o m�todo de gera��o de dados: 0 para aleat�rios, 1 para equilibrados, 2 para decrescentes

// Estrutura para armazenar estat�sticas de execu��o de um algoritmo de ordena��o ou busca
struct Estatisticas {
	int comparacoes;      // N�mero de compara��es realizadas durante a execu��o do algoritmo
	int trocas;           // N�mero de trocas realizadas durante a execu��o do algoritmo
	float tempoExecucao;  // Tempo total de execu��o do algoritmo em segundos

	// M�todo para limpar os valores armazenados na estrutura
	void Clear() {
		comparacoes = 0;    // Reseta o contador de compara��es
		trocas = 0;         // Reseta o contador de trocas
		tempoExecucao = 0;  // Reseta o tempo de execu��o
	}
};


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart1;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel6;
	TLabel *Label1;
	TButton *btnValueGen;
	TEdit *tbValor;
	TButton *Button2;
	TLabel *Label2;
	TComboBox *cbSort;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *tbComparacao;
	TEdit *tbTrocas;
	TPanel *Panel7;
	TLabel *Label5;
	TEdit *tbBusca;
	TButton *Button10;
	TComboBox *cbBusca;
	TBarSeries *Series1;
	TRichEdit *reResultados;
	TPanel *Panel1;
	TButton *btnVoltarOriginal;
	TPanel *Panel5;
	TButton *Button9;
	TButton *Button8;
	TButton *btnMostrarValores;
	TPanel *Panel2;
	TButton *Button4;
	TButton *btnOptions;
	TButton *Button1;
	void __fastcall evOrdenarValores(TObject *Sender);
	void __fastcall evApenasNumeros(TObject *Sender, System::WideChar &Key);
	void __fastcall evGerarValores(TObject *Sender);
	void __fastcall evTrocarOriginal(TObject *Sender);
	void __fastcall evLimpar(TObject *Sender);
	void __fastcall evSair(TObject *Sender);
	void __fastcall evBuscarValor(TObject *Sender);
	void __fastcall evMostrarValores(TObject *Sender);
	void __fastcall evAbrirOpcoes(TObject *Sender);
	void __fastcall evAbrirEstatisticas(TObject *Sender);
	void __fastcall evCreditos(TObject *Sender);



private:	// User declarations

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
