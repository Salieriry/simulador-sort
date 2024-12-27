#include <vcl.h>
#pragma hdrstop

#include "UFormGraficos.h"  // Inclui o cabe�alho do formul�rio que exibe os gr�ficos
#include "Unit1.h"          // Inclui o cabe�alho do formul�rio principal, que cont�m os dados

#pragma package(smart_init)  // Indica ao compilador que a biblioteca de pacotes est� configurada
#pragma resource "*.dfm"    // Define que o arquivo de recursos do formul�rio est� inclu�do

// Declara��o de uma vari�vel global para o formul�rio
TFormGraficos *FormGraficos;

//---------------------------------------------------------------------------
// Construtor do formul�rio
__fastcall TFormGraficos::TFormGraficos(TComponent* Owner)
    : TForm(Owner)  // Chama o construtor da classe base TForm
{
}

//---------------------------------------------------------------------------
// M�todo para exibir as estat�sticas nos gr�ficos
void TFormGraficos::exibirEstatisticas(Estatisticas estatisticas[]) {
    // Limpa os gr�ficos de compara��es, trocas e tempo, removendo quaisquer valores antigos
    ChartComparacoes->Series[0]->Clear();
    ChartTrocas->Series[0]->Clear();
    ChartTempo->Series[0]->Clear();

    // Nomes dos algoritmos de ordena��o
    String algoritmos[] = { "BubbleSort", "InsertionSort", "ShellSort", "SelectionSort",
                            "MergeSort", "QuickSort", "HeapSort" };

    // Define uma cor personalizada para os gr�ficos
    TColor corPersonalizada = TColor(RGB(179, 89, 255));

    // Loop para adicionar os dados de cada algoritmo nos gr�ficos
    for (int i = 0; i < 7; i++) {
        // Adiciona o n�mero de compara��es ao gr�fico de compara��es com a cor personalizada
        ChartComparacoes->Series[0]->Add(estatisticas[i].comparacoes, algoritmos[i], corPersonalizada);

        // Adiciona o n�mero de trocas ao gr�fico de trocas com a cor personalizada
        ChartTrocas->Series[0]->Add(estatisticas[i].trocas, algoritmos[i], corPersonalizada);

        // Adiciona o tempo de execu��o ao gr�fico de tempo com a cor personalizada
        ChartTempo->Series[0]->Add(estatisticas[i].tempoExecucao, algoritmos[i], corPersonalizada);
    }
}

