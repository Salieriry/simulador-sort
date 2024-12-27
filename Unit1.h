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

// Variáveis globais externas (declaradas em outro arquivo e usadas neste)
// Representam os atrasos em milissegundos para comparações e trocas, utilizados na animação ou simulação do algoritmo
extern int delayCompare; // Atraso para simular uma comparação entre elementos
extern int delaySwap;    // Atraso para simular uma troca entre elementos

// Representa o valor máximo permitido para o tamanho do vetor ou valores gerados
extern int maxVal; // Limite superior do número ou tamanho dos elementos no vetor

// Representa o modo de geração dos valores no vetor (aleatórios, equilibrados ou decrescentes)
extern int modoGeracao; // Define o método de geração de dados: 0 para aleatórios, 1 para equilibrados, 2 para decrescentes

// Estrutura para armazenar estatísticas de execução de um algoritmo de ordenação ou busca
struct Estatisticas {
	int comparacoes;      // Número de comparações realizadas durante a execução do algoritmo
	int trocas;           // Número de trocas realizadas durante a execução do algoritmo
	float tempoExecucao;  // Tempo total de execução do algoritmo em segundos

	// Método para limpar os valores armazenados na estrutura
	void Clear() {
		comparacoes = 0;    // Reseta o contador de comparações
		trocas = 0;         // Reseta o contador de trocas
		tempoExecucao = 0;  // Reseta o tempo de execução
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
