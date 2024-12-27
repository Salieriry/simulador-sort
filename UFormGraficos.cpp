#include <vcl.h>
#pragma hdrstop

#include "UFormGraficos.h"  // Inclui o cabeçalho do formulário que exibe os gráficos
#include "Unit1.h"          // Inclui o cabeçalho do formulário principal, que contém os dados

#pragma package(smart_init)  // Indica ao compilador que a biblioteca de pacotes está configurada
#pragma resource "*.dfm"    // Define que o arquivo de recursos do formulário está incluído

// Declaração de uma variável global para o formulário
TFormGraficos *FormGraficos;

//---------------------------------------------------------------------------
// Construtor do formulário
__fastcall TFormGraficos::TFormGraficos(TComponent* Owner)
    : TForm(Owner)  // Chama o construtor da classe base TForm
{
}

//---------------------------------------------------------------------------
// Método para exibir as estatísticas nos gráficos
void TFormGraficos::exibirEstatisticas(Estatisticas estatisticas[]) {
    // Limpa os gráficos de comparações, trocas e tempo, removendo quaisquer valores antigos
    ChartComparacoes->Series[0]->Clear();
    ChartTrocas->Series[0]->Clear();
    ChartTempo->Series[0]->Clear();

    // Nomes dos algoritmos de ordenação
    String algoritmos[] = { "BubbleSort", "InsertionSort", "ShellSort", "SelectionSort",
                            "MergeSort", "QuickSort", "HeapSort" };

    // Define uma cor personalizada para os gráficos
    TColor corPersonalizada = TColor(RGB(179, 89, 255));

    // Loop para adicionar os dados de cada algoritmo nos gráficos
    for (int i = 0; i < 7; i++) {
        // Adiciona o número de comparações ao gráfico de comparações com a cor personalizada
        ChartComparacoes->Series[0]->Add(estatisticas[i].comparacoes, algoritmos[i], corPersonalizada);

        // Adiciona o número de trocas ao gráfico de trocas com a cor personalizada
        ChartTrocas->Series[0]->Add(estatisticas[i].trocas, algoritmos[i], corPersonalizada);

        // Adiciona o tempo de execução ao gráfico de tempo com a cor personalizada
        ChartTempo->Series[0]->Add(estatisticas[i].tempoExecucao, algoritmos[i], corPersonalizada);
    }
}

