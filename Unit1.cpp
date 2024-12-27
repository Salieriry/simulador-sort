// Inclusão de bibliotecas necessárias
#include <vcl.h>      // Biblioteca principal para aplicações na VCL (Visual Component Library)
#include <time.h>     // Biblioteca para manipulação de tempo
#include <algorithm>  // Biblioteca para funções como std::swap (troca de valores)
#pragma hdrstop       // Diretiva para otimizar a compilação, interrompendo a inclusão de cabeçalhos

// Inclusão de arquivos de cabeçalho personalizados do projeto
#include "Unit1.h"         // Arquivo de cabeçalho do formulário principal
#include "FormOpcoes.h"    // Arquivo de cabeçalho para o formulário de opções
#include "UFormGraficos.h" // Arquivo de cabeçalho para o formulário de gráficos

// Configuração de pacotes e recursos do C++ Builder
#pragma package(smart_init)   // Configuração para inicialização eficiente de pacotes
#pragma resource "*.dfm"      // Associação com o arquivo de descrição do formulário (DFM)

// Declaração da instância global do formulário principal
TForm1 *Form1;

// Variáveis globais utilizadas no programa
int vetor[1000], vetor2[1000]; // Vetores para armazenar dados numéricos
int pos;		   			   // Variáveis auxiliares usadas em cálculos e manipulações
int compara, troca;            // Contadores de comparações e trocas realizadas pelos algoritmos
int delayCompare = 100;        // Atraso para animação de comparações (em milissegundos)
int delaySwap = 100;           // Atraso para animação de trocas (em milissegundos)
int maxVal = 100;              // Valor máximo permitido para os números no vetor
int modoGeracao = 0;           // Modo de geração de números (ex.: aleatório, ordenado)
boolean preenchido = false;    // Indicador se o vetor foi preenchido
boolean ordenado = false;      // Indicador se o vetor foi ordenado
clock_t inicio, fim;           // Variáveis para registrar o tempo inicial e final da execução
float tempo;                   // Tempo total de execução em segundos

// Estrutura para armazenar estatísticas de execução dos algoritmos
Estatisticas estatisticas[7];  // Array para até 7 algoritmos

// Implementação de funções auxiliares e algoritmos de ordenação

// Função para atualizar o gráfico com os valores do vetor
void atualizarGrafico(int vetor[], TChart *chart, TBarSeries *series, int idx1 = -1, int idx2 = -1) {
    series->Clear(); // Remove os dados antigos do gráfico

    // Adiciona os valores do vetor ao gráfico
	for (int i = 0; i < pos; ++i) {
        if (i == idx1 || i == idx2) {
            // Destaca os elementos atualmente em comparação ou troca
            series->AddXY(i, vetor[i], "", RGB(239, 242, 61)); // Amarelo para destaque
        } else {
            // Adiciona os valores com cor padrão
            series->AddXY(i, vetor[i], "", RGB(179, 89, 255)); // Roxo para valores normais
        }
    }
    chart->Repaint();              // Atualiza a exibição do gráfico
    Application->ProcessMessages(); // Garante que a interface continue responsiva
}

// Função para introduzir atraso nas comparações
void delayComparacao() {
    Sleep(delayCompare); // Pausa a execução por um tempo definido
}

// Função para introduzir atraso nas trocas
void delayTroca() {
    Sleep(delaySwap); // Pausa a execução por um tempo definido
}

// Implementação do algoritmo Bubble Sort
void bubbleSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
    compara = troca = 0; // Inicializa os contadores
    inicio = clock();    // Marca o tempo inicial

    // Loop externo que percorre o vetor
    for (int i = 0; i < pos; ++i) {
        // Loop interno para comparar pares de elementos adjacentes
        for (int j = 0; j < pos - i - 1; ++j) {
            compara++; // Incrementa o contador de comparações
            atualizarGrafico(vetor, chart, series, j, j + 1); // Destaca os elementos sendo comparados
            delayComparacao(); // Pausa para animação

            if (vetor[j] > vetor[j + 1]) {
                std::swap(vetor[j], vetor[j + 1]); // Troca os elementos
                troca++; // Incrementa o contador de trocas
                atualizarGrafico(vetor, chart, series, j, j + 1); // Atualiza o gráfico após a troca
                delayTroca(); // Pausa para animação
            }
        }
    }

    fim = clock(); // Marca o tempo final
    tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
}

// Implementação do algoritmo Insertion Sort
void insertionSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
    compara = troca = 0; // Inicializa os contadores
    inicio = clock();    // Marca o tempo inicial

    // Percorre os elementos do vetor
    for (int i = 1; i < pos; ++i) {
        int key = vetor[i]; // Define o elemento atual como chave
        int j = i;

        while (j > 0) {
            compara++; // Incrementa o contador de comparações
            atualizarGrafico(vetor, chart, series, j, j - 1); // Atualiza o gráfico
            delayComparacao(); // Pausa para animação

            if (vetor[j - 1] > key) {
                vetor[j] = vetor[j - 1]; // Move o elemento maior para a direita
                troca++; // Incrementa o contador de trocas
                atualizarGrafico(vetor, chart, series, j, j - 1); // Atualiza o gráfico
                delayTroca(); // Pausa para animação
                j--; // Move o índice para a esquerda
            } else {
                break; // Sai do loop se encontrar a posição correta
            }
        }
        vetor[j] = key; // Insere a chave na posição correta
        atualizarGrafico(vetor, chart, series); // Atualiza o gráfico
    }

    fim = clock(); // Marca o tempo final
    tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução
}

// Implementação do algoritmo Shell Sort
void shellSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o início do tempo

	// Define o intervalo inicial (gap) e reduz iterativamente
	for (int gap = pos / 2; gap > 0; gap /= 2) {
		// Percorre o vetor a partir do índice "gap"
		for (int i = gap; i < pos; i++) {
			int temp = vetor[i]; // Armazena temporariamente o elemento atual
			int j;

			// Realiza inserção com base no intervalo (gap)
			for (j = i; j >= gap; j -= gap) {
				compara++; // Incrementa o contador de comparações
				atualizarGrafico(vetor, chart, series, j, j - gap); // Destaca comparação
				delayComparacao();

				if (vetor[j - gap] > temp) {
					vetor[j] = vetor[j - gap]; // Desloca elemento maior
					troca++; // Incrementa o contador de trocas
					atualizarGrafico(vetor, chart, series, j, j - gap); // Destaca troca
					delayTroca();
				} else {
					break; // Interrompe se a posição correta foi encontrada
				}
			}
			vetor[j] = temp; // Insere o elemento armazenado na posição correta
			atualizarGrafico(vetor, chart, series); // Atualização geral do gráfico
		}
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execução
}

// Implementação do algoritmo Selection Sort
void selectionSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o início do tempo

	// Percorre o vetor até o penúltimo elemento
	for (int i = 0; i < pos - 1; ++i) {
		int minIdx = i; // Assume o índice atual como o menor
		for (int j = i + 1; j < pos; ++j) {
			compara++; // Incrementa o contador de comparações
			atualizarGrafico(vetor, chart, series, minIdx, j); // Destaca comparação
			delayComparacao();

			if (vetor[j] < vetor[minIdx]) {
				minIdx = j; // Atualiza o índice do menor elemento
			}
		}

		// Troca o menor elemento encontrado com o elemento na posição atual
		if (minIdx != i) {
			std::swap(vetor[i], vetor[minIdx]);
			troca++; // Incrementa o contador de trocas
			atualizarGrafico(vetor, chart, series, i, minIdx); // Destaca troca
			delayTroca();
		}
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execução
}

// Função auxiliar para combinar duas metades em um vetor (Merge Sort)
void merge(int vetor[], int left, int mid, int right, TChart *chart, TBarSeries *series) {
	// Determina os tamanhos das sublistas
	int n1 = mid - left + 1, n2 = right - mid;
	int* L = new int[n1]; // Sublista esquerda
	int* R = new int[n2]; // Sublista direita

	// Copia os elementos para as sublistas
	for (int i = 0; i < n1; ++i) L[i] = vetor[left + i];
	for (int i = 0; i < n2; ++i) R[i] = vetor[mid + 1 + i];

	int i = 0, j = 0, k = left; // Índices para sublistas e vetor principal
	// Combina os elementos das sublistas no vetor principal
	while (i < n1 && j < n2) {
		compara++; // Incrementa o contador de comparações
		atualizarGrafico(vetor, chart, series, k, -1); // Destaque do índice
		delayComparacao();

		if (L[i] <= R[j]) {
			vetor[k] = L[i++];
		} else {
			vetor[k] = R[j++];
		}
		troca++; // Incrementa o contador de trocas
		atualizarGrafico(vetor, chart, series, k, -1);
		delayTroca();
		k++;
	}

	// Copia os elementos restantes da sublista esquerda
	while (i < n1) {
		vetor[k++] = L[i++];
		troca++;
		atualizarGrafico(vetor, chart, series, k - 1, -1);
		delayTroca();
	}

	// Copia os elementos restantes da sublista direita
	while (j < n2) {
		vetor[k++] = R[j++];
		troca++;
		atualizarGrafico(vetor, chart, series, k - 1, -1);
		delayTroca();
	}

	delete[] L; // Libera memória alocada
	delete[] R;
}

// Implementação do algoritmo Merge Sort
void mergeSort(int vetor[], int left, int right, TChart *chart, TBarSeries *series) {
	if (left == 0 && right == pos - 1) {
		compara = troca = 0; // Inicializa contadores
		inicio = clock();    // Marca o início do tempo
	}

	if (left < right) {
		int mid = left + (right - left) / 2; // Determina o ponto médio
		mergeSort(vetor, left, mid, chart, series);      // Ordena a metade esquerda
		mergeSort(vetor, mid + 1, right, chart, series); // Ordena a metade direita
		merge(vetor, left, mid, right, chart, series);   // Combina as metades
	}

	if (left == 0 && right == pos - 1) {
		fim = clock(); // Marca o final do tempo
		tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total
	}
}

// Implementação do algoritmo Quick Sort
void quickSort(int vetor[], int low, int high, TChart *chart, TBarSeries *series) {
	if (low == 0 && high == pos - 1) {
		compara = troca = 0; // Inicializa contadores
		inicio = clock();    // Marca o início do tempo
	}

	if (low < high) {
		int pivot = vetor[high]; // Define o pivô
		int i = low;

		// Particiona os elementos em relação ao pivô
		for (int j = low; j < high; ++j) {
			compara++;
			atualizarGrafico(vetor, chart, series, j, high); // Destaque do pivô
			delayComparacao();

			if (vetor[j] <= pivot) {
				std::swap(vetor[i], vetor[j]);
				troca++;
				atualizarGrafico(vetor, chart, series, i, j); // Destaque da troca
				delayTroca();
				i++;
			}
		}
		std::swap(vetor[i], vetor[high]); // Coloca o pivô na posição correta
		troca++;
		atualizarGrafico(vetor, chart, series, i, high); // Destaque do pivô finalizado
		delayTroca();

		quickSort(vetor, low, i - 1, chart, series);  // Ordena a parte esquerda
		quickSort(vetor, i + 1, high, chart, series); // Ordena a parte direita
	}

	if (low == 0 && high == pos - 1) {
		fim = clock(); // Marca o final do tempo
		tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total
	}
}

// Função auxiliar para ajustar a estrutura de heap
void heapify(int vetor[], int pos, int i, TChart *chart, TBarSeries *series) {
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;

	// Compara o nó pai com o filho esquerdo
	if (left < pos) {
		compara++;
		atualizarGrafico(vetor, chart, series, i, left); // Destaque da comparação
		delayComparacao();
		if (vetor[left] > vetor[largest]) largest = left;
	}

	// Compara o nó pai com o filho direito
	if (right < pos) {
		compara++;
		atualizarGrafico(vetor, chart, series, i, right); // Destaque da comparação
		delayComparacao();
		if (vetor[right] > vetor[largest]) largest = right;
	}

	// Realiza a troca, se necessário
	if (largest != i) {
		std::swap(vetor[i], vetor[largest]);
		troca++;
		atualizarGrafico(vetor, chart, series, i, largest); // Destaque da troca
		delayTroca();

		// Ajusta recursivamente a sub-árvore afetada
		heapify(vetor, pos, largest, chart, series);
	} else {
		// Atualiza o gráfico mesmo sem troca
		atualizarGrafico(vetor, chart, series, i, -1);
	}
}

// Implementação do algoritmo Heap Sort
void heapSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o início do tempo

	// Constrói a heap máxima
	for (int i = pos / 2 - 1; i >= 0; --i) {
		heapify(vetor, pos, i, chart, series);
		atualizarGrafico(vetor, chart, series, i, -1); // Atualiza após cada ajuste da heap
		delayTroca();
	}

	// Extração dos elementos da heap
	for (int i = pos - 1; i > 0; --i) {
		std::swap(vetor[0], vetor[i]); // Move o maior elemento para o final
		troca++;
		atualizarGrafico(vetor, chart, series, 0, i); // Destaque da troca
		delayTroca();

		// Ajusta a heap reduzida
		heapify(vetor, i, 0, chart, series);
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execução
}




// Algoritmos de Busca
// Implementação da busca linear
int linearSearch(int vetor[], int pos, int valor, int &comparar, TChart *chart, TBarSeries *series) {
	comparar = 0; // Inicializa o contador de comparações

	// Percorre o vetor elemento por elemento
	for (int i = 0; i < pos; ++i) {
		comparar++; // Incrementa o contador de comparações
		atualizarGrafico(vetor, chart, series, i); // Atualiza o gráfico destacando o índice atual
		delayComparacao(); // Insere um atraso para visualizar a comparação

		// Verifica se o elemento atual é igual ao valor procurado
		if (vetor[i] == valor) {
			return i; // Retorna a posição do elemento encontrado
		}
	}

	return -1; // Retorna -1 caso o valor não seja encontrado
}

// Implementação da busca binária (assume vetor ordenado)
int binarySearch(int vetor[], int low, int high, int valor, int &comparar, TChart *chart, TBarSeries *series) {
	comparar = 0; // Inicializa o contador de comparações

	// Enquanto os limites não se cruzarem
	while (low <= high) {
		int mid = low + (high - low) / 2; // Calcula o índice do meio

		atualizarGrafico(vetor, chart, series, mid); // Atualiza o gráfico destacando o índice do meio
		delayComparacao(); // Insere um atraso para visualizar a comparação
		comparar++; // Incrementa o contador de comparações

		// Verifica se o elemento do meio é o valor procurado
		if (vetor[mid] == valor) {
			return mid; // Retorna a posição do valor encontrado
		} else if (vetor[mid] < valor) {
			low = mid + 1; // Ajusta o limite inferior para buscar na metade direita
		} else {
			high = mid - 1; // Ajusta o limite superior para buscar na metade esquerda
		}
	}

	return -1; // Retorna -1 caso o valor não seja encontrado
}

// Função para formatar o tempo em horas:minutos:segundos:milissegundos
String formatarTempo(float tempoSegundos) {
	int horas = tempoSegundos / 3600; // Calcula a quantidade de horas
	int minutos = (tempoSegundos - horas * 3600) / 60; // Calcula os minutos restantes
	int segundos = (int)tempoSegundos % 60; // Calcula os segundos restantes
	int milissegundos = (tempoSegundos - (int)tempoSegundos) * 1000; // Calcula os milissegundos

	// Formata o tempo em uma string no formato "hh:mm:ss:ms"
	return FormatFloat("00", horas) + ":" +
		   FormatFloat("00", minutos) + ":" +
		   FormatFloat("00", segundos) + ":" +
		   FormatFloat("000", milissegundos);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner) {

	}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento de ordenar os valores selecionados
void __fastcall TForm1::evOrdenarValores(TObject *Sender) {
	int selectedIndex = cbSort->ItemIndex; // Obtém o índice do algoritmo selecionado no ComboBox

	// Verifica se o índice selecionado é válido
	if (selectedIndex < 0 || selectedIndex > 6) { // Há 7 opções (índices 0 a 6)
		ShowMessage("Selecione um algoritmo válido!"); // Exibe mensagem de erro
		return;
	}

	// Verifica se os valores foram gerados anteriormente
	if (preenchido) {
		switch (selectedIndex) { // Seleciona o algoritmo de ordenação com base no índice
			case 0: // BubbleSort
				bubbleSort(vetor, pos, Chart1, Series1); // Executa o BubbleSort
				reResultados->SelAttributes->Color = clRed; // Define a cor do texto para o resultado
				reResultados->Lines->Add("Método BubbleSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo)); // Adiciona as estatísticas
				estatisticas[0].comparacoes = compara;
				estatisticas[0].trocas = troca;
				estatisticas[0].tempoExecucao = tempo;
				break;

			case 1: // InsertionSort
				insertionSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clPurple;
				reResultados->Lines->Add("Método InsertionSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[1].comparacoes = compara;
				estatisticas[1].trocas = troca;
				estatisticas[1].tempoExecucao = tempo;
				break;

			case 2: // ShellSort
				shellSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clTeal;
				reResultados->Lines->Add("Método ShellSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[2].comparacoes = compara;
				estatisticas[2].trocas = troca;
				estatisticas[2].tempoExecucao = tempo;
				break;

			case 3: // SelectionSort
				selectionSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clOlive;
				reResultados->Lines->Add("Método SelectionSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[3].comparacoes = compara;
				estatisticas[3].trocas = troca;
				estatisticas[3].tempoExecucao = tempo;
				break;

			case 4: // MergeSort
				mergeSort(vetor, 0, pos - 1, Chart1, Series1);
				reResultados->SelAttributes->Color = clNavy;
				reResultados->Lines->Add("Método MergeSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[4].comparacoes = compara;
				estatisticas[4].trocas = troca;
				estatisticas[4].tempoExecucao = tempo;
				break;

			case 5: // QuickSort
				quickSort(vetor, 0, pos - 1, Chart1, Series1);
				reResultados->SelAttributes->Color = clMaroon;
				reResultados->Lines->Add("Método QuickSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[5].comparacoes = compara;
				estatisticas[5].trocas = troca;
				estatisticas[5].tempoExecucao = tempo;
				break;

			case 6: // HeapSort
				heapSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clFuchsia;
				reResultados->Lines->Add("Método HeapSort - Comparações: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execução: " + formatarTempo(tempo));
				estatisticas[6].comparacoes = compara;
				estatisticas[6].trocas = troca;
				estatisticas[6].tempoExecucao = tempo;
				break;
		}

		// Atualiza o gráfico e exibe as estatísticas
		atualizarGrafico(vetor, Chart1, Series1);
		tbComparacao->Text = IntToStr(compara); // Mostra o número de comparações
		tbTrocas->Text = IntToStr(troca); // Mostra o número de trocas
		ordenado = true; // Marca o vetor como ordenado

	} else {
		// Caso os valores ainda não tenham sido gerados
		ShowMessage("Gráfico não preenchido.");
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para gerar novos valores
void __fastcall TForm1::evGerarValores(TObject *Sender) {
	// Obtém o número de valores desejado
	int numValores = StrToIntDef(tbValor->Text, -1);
	if (numValores < 2 || numValores > maxVal) { // Verifica se está dentro do limite permitido
		ShowMessage("Por favor, insira um valor entre 2 e " + IntToStr(maxVal) + ".");
		return;
	}

	pos = numValores; // Define a quantidade de valores
	Series1->Clear(); // Limpa o gráfico anterior
	Randomize(); // Inicializa o gerador de números aleatórios

	// Gera os valores com base no modo selecionado
	if (modoGeracao == 0) { // Aleatórios
		for (int i = 0; i < pos; ++i) vetor[i] = Random(500);
	} else if (modoGeracao == 1) { // Equilibrados
		for (int i = 0; i < pos; ++i) vetor[i] = Random(100) + 200;
	} else if (modoGeracao == 2) { // Decrescentes
		for (int i = 0; i < pos; ++i) vetor[i] = pos - i;
	}

	// Popula o gráfico
	for (int i = 0; i < pos; ++i) {
		vetor2[i] = vetor[i];
		Series1->AddXY(i, vetor2[i], "", RGB(179, 89, 255));
	}

	// Limpa as estatísticas dos algoritmos
	for (int i = 0; i < 7; i++) {
		estatisticas[i].Clear();
	}

	preenchido = true; // Marca o gráfico como preenchido
	Chart1->Repaint(); // Atualiza o gráfico
	ShowMessage("Gráfico atualizado com " + IntToStr(pos) + " valores.");
	ordenado = false; // Marca como não ordenado
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para restaurar os valores originais
void __fastcall TForm1::evTrocarOriginal(TObject *Sender) {
	// Restaura os valores do vetor para o estado original (armazenado em vetor2)
	for (int i = 0; i < pos; ++i) {
		vetor[i] = vetor2[i];
	}
	atualizarGrafico(vetor, Chart1, Series1); // Atualiza o gráfico com os valores restaurados
	ordenado = false; // Marca o vetor como não ordenado
	ShowMessage("Valores restaurados para o original."); // Mensagem de confirmação
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para permitir apenas entrada de números
void __fastcall TForm1::evApenasNumeros(TObject *Sender, System::WideChar &Key) {
	if (!isdigit(Key) && Key != VK_BACK) { // Permite apenas dígitos e backspace
		Key = 0; // Ignora caracteres inválidos
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para limpar o gráfico e campos de resultados
void __fastcall TForm1::evLimpar(TObject *Sender) {
	Series1->Clear(); // Limpa os dados do gráfico
	reResultados->Lines->Clear(); // Limpa o texto de resultados
	tbComparacao->Clear(); // Limpa o campo de comparações
	tbTrocas->Clear(); // Limpa o campo de trocas
	preenchido = false; // Marca que o gráfico não está preenchido
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para fechar o programa
void __fastcall TForm1::evSair(TObject *Sender) {
	this->Close(); // Fecha a aplicação
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para buscar um valor no vetor
void __fastcall TForm1::evBuscarValor(TObject *Sender) {
	if (!preenchido) { // Verifica se o gráfico foi preenchido
		ShowMessage("Gráfico não preenchido.");
		return;
	}

	int valor = StrToIntDef(tbBusca->Text, -1); // Lê o valor a ser buscado
	if (valor < 0) { // Verifica se o valor é válido
		ShowMessage("Por favor, insira um valor válido para buscar.");
		return;
	}

	int resultado; // Armazena a posição do valor encontrado (-1 se não encontrado)
	clock_t inicio, fim; // Para medir o tempo de execução
	int comparar = 0; // Número de comparações realizadas
	float tempo; // Tempo de execução

	// Seleciona o algoritmo de busca com base no índice do ComboBox
	switch (cbBusca->ItemIndex) {
		case 0: // Busca Linear
			inicio = clock(); // Inicia o cronômetro
			resultado = linearSearch(vetor, pos, valor, comparar, Chart1, Series1); // Executa a busca linear
			fim = clock(); // Termina o cronômetro
			tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execução

			reResultados->SelAttributes->Color = clBlue; // Define a cor do texto para o resultado
			// Exibe os resultados
			if (resultado != -1) {
				reResultados->Lines->Add("Método LinearSearch - Comparações: " +
					IntToStr(comparar) + " | Tempo de execução: " +
					formatarTempo(tempo) + " | Resultado: " +
					"Valor encontrado na posição " + IntToStr(resultado));
			} else {
				reResultados->Lines->Add("Método LinearSearch - Comparações: " +
					IntToStr(comparar) + " | Tempo de execução: " +
					formatarTempo(tempo) + " | Resultado: Valor não encontrado.");
			}
			break;

		case 1: // Busca Binária
			if (!ordenado) { // A busca binária requer um vetor ordenado
				ShowMessage("Vetor não está ordenado. Ordene o vetor antes de realizar a busca binária.");
				return;
			}
			inicio = clock();
			resultado = binarySearch(vetor, 0, pos - 1, valor, comparar, Chart1, Series1); // Executa a busca binária
			fim = clock();
			tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC;

			reResultados->SelAttributes->Color = clGreen;
			// Exibe os resultados
			if (resultado != -1) {
				reResultados->Lines->Add("Método BinarySearch - Comparações: " +
					IntToStr(comparar) + " | Tempo de execução: " +
					formatarTempo(tempo) + " | Resultado: " +
					"Valor encontrado na posição " + IntToStr(resultado));
			} else {
				reResultados->Lines->Add("Método BinarySearch - Comparações: " +
					IntToStr(comparar) + " | Tempo de execução: " +
					formatarTempo(tempo) + " | Resultado: Valor não encontrado.");
			}
			break;

		default: // Caso nenhum algoritmo válido seja selecionado
			ShowMessage("Selecione um algoritmo de busca válido!");
			return;
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para alternar a exibição dos valores no gráfico
void __fastcall TForm1::evMostrarValores(TObject *Sender) {
	static bool valoresVisiveis = false; // Estado inicial: valores escondidos
	valoresVisiveis = !valoresVisiveis; // Alterna o estado
	Series1->Marks->Visible = valoresVisiveis; // Exibe ou oculta os valores no gráfico
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para abrir a janela de opções
void __fastcall TForm1::evAbrirOpcoes(TObject *Sender) {
	TFormOptions *formOptions = new TFormOptions(this); // Cria a janela de opções

	if (formOptions->Visible) { // Se já estiver visível, esconde
		formOptions->Hide();
	}

	formOptions->ShowModal(); // Exibe a janela de opções
	delete formOptions; // Libera a memória após fechar
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para abrir a janela de estatísticas
void __fastcall TForm1::evAbrirEstatisticas(TObject *Sender) {
	TFormGraficos *formGraficos = new TFormGraficos(this); // Cria a janela de estatísticas

	if (formGraficos->Visible) { // Se já estiver visível, esconde
		formGraficos->Hide();
	}

	formGraficos->exibirEstatisticas(estatisticas); // Passa as estatísticas para exibição
	formGraficos->ShowModal(); // Exibe a janela de estatísticas
	delete formGraficos; // Libera a memória após fechar
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para exibir os créditos do programa
void __fastcall TForm1::evCreditos(TObject *Sender) {
	ShowMessage("Feito por: Rychard Gimenez dos Santos \n6o Termo Engenharia da Computação 2024"); // Exibe os créditos
}
//---------------------------------------------------------------------------

