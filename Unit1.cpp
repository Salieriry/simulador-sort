// Inclus�o de bibliotecas necess�rias
#include <vcl.h>      // Biblioteca principal para aplica��es na VCL (Visual Component Library)
#include <time.h>     // Biblioteca para manipula��o de tempo
#include <algorithm>  // Biblioteca para fun��es como std::swap (troca de valores)
#pragma hdrstop       // Diretiva para otimizar a compila��o, interrompendo a inclus�o de cabe�alhos

// Inclus�o de arquivos de cabe�alho personalizados do projeto
#include "Unit1.h"         // Arquivo de cabe�alho do formul�rio principal
#include "FormOpcoes.h"    // Arquivo de cabe�alho para o formul�rio de op��es
#include "UFormGraficos.h" // Arquivo de cabe�alho para o formul�rio de gr�ficos

// Configura��o de pacotes e recursos do C++ Builder
#pragma package(smart_init)   // Configura��o para inicializa��o eficiente de pacotes
#pragma resource "*.dfm"      // Associa��o com o arquivo de descri��o do formul�rio (DFM)

// Declara��o da inst�ncia global do formul�rio principal
TForm1 *Form1;

// Vari�veis globais utilizadas no programa
int vetor[1000], vetor2[1000]; // Vetores para armazenar dados num�ricos
int pos;		   			   // Vari�veis auxiliares usadas em c�lculos e manipula��es
int compara, troca;            // Contadores de compara��es e trocas realizadas pelos algoritmos
int delayCompare = 100;        // Atraso para anima��o de compara��es (em milissegundos)
int delaySwap = 100;           // Atraso para anima��o de trocas (em milissegundos)
int maxVal = 100;              // Valor m�ximo permitido para os n�meros no vetor
int modoGeracao = 0;           // Modo de gera��o de n�meros (ex.: aleat�rio, ordenado)
boolean preenchido = false;    // Indicador se o vetor foi preenchido
boolean ordenado = false;      // Indicador se o vetor foi ordenado
clock_t inicio, fim;           // Vari�veis para registrar o tempo inicial e final da execu��o
float tempo;                   // Tempo total de execu��o em segundos

// Estrutura para armazenar estat�sticas de execu��o dos algoritmos
Estatisticas estatisticas[7];  // Array para at� 7 algoritmos

// Implementa��o de fun��es auxiliares e algoritmos de ordena��o

// Fun��o para atualizar o gr�fico com os valores do vetor
void atualizarGrafico(int vetor[], TChart *chart, TBarSeries *series, int idx1 = -1, int idx2 = -1) {
    series->Clear(); // Remove os dados antigos do gr�fico

    // Adiciona os valores do vetor ao gr�fico
	for (int i = 0; i < pos; ++i) {
        if (i == idx1 || i == idx2) {
            // Destaca os elementos atualmente em compara��o ou troca
            series->AddXY(i, vetor[i], "", RGB(239, 242, 61)); // Amarelo para destaque
        } else {
            // Adiciona os valores com cor padr�o
            series->AddXY(i, vetor[i], "", RGB(179, 89, 255)); // Roxo para valores normais
        }
    }
    chart->Repaint();              // Atualiza a exibi��o do gr�fico
    Application->ProcessMessages(); // Garante que a interface continue responsiva
}

// Fun��o para introduzir atraso nas compara��es
void delayComparacao() {
    Sleep(delayCompare); // Pausa a execu��o por um tempo definido
}

// Fun��o para introduzir atraso nas trocas
void delayTroca() {
    Sleep(delaySwap); // Pausa a execu��o por um tempo definido
}

// Implementa��o do algoritmo Bubble Sort
void bubbleSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
    compara = troca = 0; // Inicializa os contadores
    inicio = clock();    // Marca o tempo inicial

    // Loop externo que percorre o vetor
    for (int i = 0; i < pos; ++i) {
        // Loop interno para comparar pares de elementos adjacentes
        for (int j = 0; j < pos - i - 1; ++j) {
            compara++; // Incrementa o contador de compara��es
            atualizarGrafico(vetor, chart, series, j, j + 1); // Destaca os elementos sendo comparados
            delayComparacao(); // Pausa para anima��o

            if (vetor[j] > vetor[j + 1]) {
                std::swap(vetor[j], vetor[j + 1]); // Troca os elementos
                troca++; // Incrementa o contador de trocas
                atualizarGrafico(vetor, chart, series, j, j + 1); // Atualiza o gr�fico ap�s a troca
                delayTroca(); // Pausa para anima��o
            }
        }
    }

    fim = clock(); // Marca o tempo final
    tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execu��o
}

// Implementa��o do algoritmo Insertion Sort
void insertionSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
    compara = troca = 0; // Inicializa os contadores
    inicio = clock();    // Marca o tempo inicial

    // Percorre os elementos do vetor
    for (int i = 1; i < pos; ++i) {
        int key = vetor[i]; // Define o elemento atual como chave
        int j = i;

        while (j > 0) {
            compara++; // Incrementa o contador de compara��es
            atualizarGrafico(vetor, chart, series, j, j - 1); // Atualiza o gr�fico
            delayComparacao(); // Pausa para anima��o

            if (vetor[j - 1] > key) {
                vetor[j] = vetor[j - 1]; // Move o elemento maior para a direita
                troca++; // Incrementa o contador de trocas
                atualizarGrafico(vetor, chart, series, j, j - 1); // Atualiza o gr�fico
                delayTroca(); // Pausa para anima��o
                j--; // Move o �ndice para a esquerda
            } else {
                break; // Sai do loop se encontrar a posi��o correta
            }
        }
        vetor[j] = key; // Insere a chave na posi��o correta
        atualizarGrafico(vetor, chart, series); // Atualiza o gr�fico
    }

    fim = clock(); // Marca o tempo final
    tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execu��o
}

// Implementa��o do algoritmo Shell Sort
void shellSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o in�cio do tempo

	// Define o intervalo inicial (gap) e reduz iterativamente
	for (int gap = pos / 2; gap > 0; gap /= 2) {
		// Percorre o vetor a partir do �ndice "gap"
		for (int i = gap; i < pos; i++) {
			int temp = vetor[i]; // Armazena temporariamente o elemento atual
			int j;

			// Realiza inser��o com base no intervalo (gap)
			for (j = i; j >= gap; j -= gap) {
				compara++; // Incrementa o contador de compara��es
				atualizarGrafico(vetor, chart, series, j, j - gap); // Destaca compara��o
				delayComparacao();

				if (vetor[j - gap] > temp) {
					vetor[j] = vetor[j - gap]; // Desloca elemento maior
					troca++; // Incrementa o contador de trocas
					atualizarGrafico(vetor, chart, series, j, j - gap); // Destaca troca
					delayTroca();
				} else {
					break; // Interrompe se a posi��o correta foi encontrada
				}
			}
			vetor[j] = temp; // Insere o elemento armazenado na posi��o correta
			atualizarGrafico(vetor, chart, series); // Atualiza��o geral do gr�fico
		}
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execu��o
}

// Implementa��o do algoritmo Selection Sort
void selectionSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o in�cio do tempo

	// Percorre o vetor at� o pen�ltimo elemento
	for (int i = 0; i < pos - 1; ++i) {
		int minIdx = i; // Assume o �ndice atual como o menor
		for (int j = i + 1; j < pos; ++j) {
			compara++; // Incrementa o contador de compara��es
			atualizarGrafico(vetor, chart, series, minIdx, j); // Destaca compara��o
			delayComparacao();

			if (vetor[j] < vetor[minIdx]) {
				minIdx = j; // Atualiza o �ndice do menor elemento
			}
		}

		// Troca o menor elemento encontrado com o elemento na posi��o atual
		if (minIdx != i) {
			std::swap(vetor[i], vetor[minIdx]);
			troca++; // Incrementa o contador de trocas
			atualizarGrafico(vetor, chart, series, i, minIdx); // Destaca troca
			delayTroca();
		}
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execu��o
}

// Fun��o auxiliar para combinar duas metades em um vetor (Merge Sort)
void merge(int vetor[], int left, int mid, int right, TChart *chart, TBarSeries *series) {
	// Determina os tamanhos das sublistas
	int n1 = mid - left + 1, n2 = right - mid;
	int* L = new int[n1]; // Sublista esquerda
	int* R = new int[n2]; // Sublista direita

	// Copia os elementos para as sublistas
	for (int i = 0; i < n1; ++i) L[i] = vetor[left + i];
	for (int i = 0; i < n2; ++i) R[i] = vetor[mid + 1 + i];

	int i = 0, j = 0, k = left; // �ndices para sublistas e vetor principal
	// Combina os elementos das sublistas no vetor principal
	while (i < n1 && j < n2) {
		compara++; // Incrementa o contador de compara��es
		atualizarGrafico(vetor, chart, series, k, -1); // Destaque do �ndice
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

	delete[] L; // Libera mem�ria alocada
	delete[] R;
}

// Implementa��o do algoritmo Merge Sort
void mergeSort(int vetor[], int left, int right, TChart *chart, TBarSeries *series) {
	if (left == 0 && right == pos - 1) {
		compara = troca = 0; // Inicializa contadores
		inicio = clock();    // Marca o in�cio do tempo
	}

	if (left < right) {
		int mid = left + (right - left) / 2; // Determina o ponto m�dio
		mergeSort(vetor, left, mid, chart, series);      // Ordena a metade esquerda
		mergeSort(vetor, mid + 1, right, chart, series); // Ordena a metade direita
		merge(vetor, left, mid, right, chart, series);   // Combina as metades
	}

	if (left == 0 && right == pos - 1) {
		fim = clock(); // Marca o final do tempo
		tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total
	}
}

// Implementa��o do algoritmo Quick Sort
void quickSort(int vetor[], int low, int high, TChart *chart, TBarSeries *series) {
	if (low == 0 && high == pos - 1) {
		compara = troca = 0; // Inicializa contadores
		inicio = clock();    // Marca o in�cio do tempo
	}

	if (low < high) {
		int pivot = vetor[high]; // Define o piv�
		int i = low;

		// Particiona os elementos em rela��o ao piv�
		for (int j = low; j < high; ++j) {
			compara++;
			atualizarGrafico(vetor, chart, series, j, high); // Destaque do piv�
			delayComparacao();

			if (vetor[j] <= pivot) {
				std::swap(vetor[i], vetor[j]);
				troca++;
				atualizarGrafico(vetor, chart, series, i, j); // Destaque da troca
				delayTroca();
				i++;
			}
		}
		std::swap(vetor[i], vetor[high]); // Coloca o piv� na posi��o correta
		troca++;
		atualizarGrafico(vetor, chart, series, i, high); // Destaque do piv� finalizado
		delayTroca();

		quickSort(vetor, low, i - 1, chart, series);  // Ordena a parte esquerda
		quickSort(vetor, i + 1, high, chart, series); // Ordena a parte direita
	}

	if (low == 0 && high == pos - 1) {
		fim = clock(); // Marca o final do tempo
		tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total
	}
}

// Fun��o auxiliar para ajustar a estrutura de heap
void heapify(int vetor[], int pos, int i, TChart *chart, TBarSeries *series) {
	int largest = i, left = 2 * i + 1, right = 2 * i + 2;

	// Compara o n� pai com o filho esquerdo
	if (left < pos) {
		compara++;
		atualizarGrafico(vetor, chart, series, i, left); // Destaque da compara��o
		delayComparacao();
		if (vetor[left] > vetor[largest]) largest = left;
	}

	// Compara o n� pai com o filho direito
	if (right < pos) {
		compara++;
		atualizarGrafico(vetor, chart, series, i, right); // Destaque da compara��o
		delayComparacao();
		if (vetor[right] > vetor[largest]) largest = right;
	}

	// Realiza a troca, se necess�rio
	if (largest != i) {
		std::swap(vetor[i], vetor[largest]);
		troca++;
		atualizarGrafico(vetor, chart, series, i, largest); // Destaque da troca
		delayTroca();

		// Ajusta recursivamente a sub-�rvore afetada
		heapify(vetor, pos, largest, chart, series);
	} else {
		// Atualiza o gr�fico mesmo sem troca
		atualizarGrafico(vetor, chart, series, i, -1);
	}
}

// Implementa��o do algoritmo Heap Sort
void heapSort(int vetor[], int pos, TChart *chart, TBarSeries *series) {
	compara = troca = 0; // Inicializa contadores
	inicio = clock();    // Marca o in�cio do tempo

	// Constr�i a heap m�xima
	for (int i = pos / 2 - 1; i >= 0; --i) {
		heapify(vetor, pos, i, chart, series);
		atualizarGrafico(vetor, chart, series, i, -1); // Atualiza ap�s cada ajuste da heap
		delayTroca();
	}

	// Extra��o dos elementos da heap
	for (int i = pos - 1; i > 0; --i) {
		std::swap(vetor[0], vetor[i]); // Move o maior elemento para o final
		troca++;
		atualizarGrafico(vetor, chart, series, 0, i); // Destaque da troca
		delayTroca();

		// Ajusta a heap reduzida
		heapify(vetor, i, 0, chart, series);
	}

	fim = clock(); // Marca o final do tempo
	tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo total de execu��o
}




// Algoritmos de Busca
// Implementa��o da busca linear
int linearSearch(int vetor[], int pos, int valor, int &comparar, TChart *chart, TBarSeries *series) {
	comparar = 0; // Inicializa o contador de compara��es

	// Percorre o vetor elemento por elemento
	for (int i = 0; i < pos; ++i) {
		comparar++; // Incrementa o contador de compara��es
		atualizarGrafico(vetor, chart, series, i); // Atualiza o gr�fico destacando o �ndice atual
		delayComparacao(); // Insere um atraso para visualizar a compara��o

		// Verifica se o elemento atual � igual ao valor procurado
		if (vetor[i] == valor) {
			return i; // Retorna a posi��o do elemento encontrado
		}
	}

	return -1; // Retorna -1 caso o valor n�o seja encontrado
}

// Implementa��o da busca bin�ria (assume vetor ordenado)
int binarySearch(int vetor[], int low, int high, int valor, int &comparar, TChart *chart, TBarSeries *series) {
	comparar = 0; // Inicializa o contador de compara��es

	// Enquanto os limites n�o se cruzarem
	while (low <= high) {
		int mid = low + (high - low) / 2; // Calcula o �ndice do meio

		atualizarGrafico(vetor, chart, series, mid); // Atualiza o gr�fico destacando o �ndice do meio
		delayComparacao(); // Insere um atraso para visualizar a compara��o
		comparar++; // Incrementa o contador de compara��es

		// Verifica se o elemento do meio � o valor procurado
		if (vetor[mid] == valor) {
			return mid; // Retorna a posi��o do valor encontrado
		} else if (vetor[mid] < valor) {
			low = mid + 1; // Ajusta o limite inferior para buscar na metade direita
		} else {
			high = mid - 1; // Ajusta o limite superior para buscar na metade esquerda
		}
	}

	return -1; // Retorna -1 caso o valor n�o seja encontrado
}

// Fun��o para formatar o tempo em horas:minutos:segundos:milissegundos
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
	int selectedIndex = cbSort->ItemIndex; // Obt�m o �ndice do algoritmo selecionado no ComboBox

	// Verifica se o �ndice selecionado � v�lido
	if (selectedIndex < 0 || selectedIndex > 6) { // H� 7 op��es (�ndices 0 a 6)
		ShowMessage("Selecione um algoritmo v�lido!"); // Exibe mensagem de erro
		return;
	}

	// Verifica se os valores foram gerados anteriormente
	if (preenchido) {
		switch (selectedIndex) { // Seleciona o algoritmo de ordena��o com base no �ndice
			case 0: // BubbleSort
				bubbleSort(vetor, pos, Chart1, Series1); // Executa o BubbleSort
				reResultados->SelAttributes->Color = clRed; // Define a cor do texto para o resultado
				reResultados->Lines->Add("M�todo BubbleSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo)); // Adiciona as estat�sticas
				estatisticas[0].comparacoes = compara;
				estatisticas[0].trocas = troca;
				estatisticas[0].tempoExecucao = tempo;
				break;

			case 1: // InsertionSort
				insertionSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clPurple;
				reResultados->Lines->Add("M�todo InsertionSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[1].comparacoes = compara;
				estatisticas[1].trocas = troca;
				estatisticas[1].tempoExecucao = tempo;
				break;

			case 2: // ShellSort
				shellSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clTeal;
				reResultados->Lines->Add("M�todo ShellSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[2].comparacoes = compara;
				estatisticas[2].trocas = troca;
				estatisticas[2].tempoExecucao = tempo;
				break;

			case 3: // SelectionSort
				selectionSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clOlive;
				reResultados->Lines->Add("M�todo SelectionSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[3].comparacoes = compara;
				estatisticas[3].trocas = troca;
				estatisticas[3].tempoExecucao = tempo;
				break;

			case 4: // MergeSort
				mergeSort(vetor, 0, pos - 1, Chart1, Series1);
				reResultados->SelAttributes->Color = clNavy;
				reResultados->Lines->Add("M�todo MergeSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[4].comparacoes = compara;
				estatisticas[4].trocas = troca;
				estatisticas[4].tempoExecucao = tempo;
				break;

			case 5: // QuickSort
				quickSort(vetor, 0, pos - 1, Chart1, Series1);
				reResultados->SelAttributes->Color = clMaroon;
				reResultados->Lines->Add("M�todo QuickSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[5].comparacoes = compara;
				estatisticas[5].trocas = troca;
				estatisticas[5].tempoExecucao = tempo;
				break;

			case 6: // HeapSort
				heapSort(vetor, pos, Chart1, Series1);
				reResultados->SelAttributes->Color = clFuchsia;
				reResultados->Lines->Add("M�todo HeapSort - Compara��es: " +
					IntToStr(compara) + " | Trocas: " + IntToStr(troca) +
					" | Tempo de execu��o: " + formatarTempo(tempo));
				estatisticas[6].comparacoes = compara;
				estatisticas[6].trocas = troca;
				estatisticas[6].tempoExecucao = tempo;
				break;
		}

		// Atualiza o gr�fico e exibe as estat�sticas
		atualizarGrafico(vetor, Chart1, Series1);
		tbComparacao->Text = IntToStr(compara); // Mostra o n�mero de compara��es
		tbTrocas->Text = IntToStr(troca); // Mostra o n�mero de trocas
		ordenado = true; // Marca o vetor como ordenado

	} else {
		// Caso os valores ainda n�o tenham sido gerados
		ShowMessage("Gr�fico n�o preenchido.");
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para gerar novos valores
void __fastcall TForm1::evGerarValores(TObject *Sender) {
	// Obt�m o n�mero de valores desejado
	int numValores = StrToIntDef(tbValor->Text, -1);
	if (numValores < 2 || numValores > maxVal) { // Verifica se est� dentro do limite permitido
		ShowMessage("Por favor, insira um valor entre 2 e " + IntToStr(maxVal) + ".");
		return;
	}

	pos = numValores; // Define a quantidade de valores
	Series1->Clear(); // Limpa o gr�fico anterior
	Randomize(); // Inicializa o gerador de n�meros aleat�rios

	// Gera os valores com base no modo selecionado
	if (modoGeracao == 0) { // Aleat�rios
		for (int i = 0; i < pos; ++i) vetor[i] = Random(500);
	} else if (modoGeracao == 1) { // Equilibrados
		for (int i = 0; i < pos; ++i) vetor[i] = Random(100) + 200;
	} else if (modoGeracao == 2) { // Decrescentes
		for (int i = 0; i < pos; ++i) vetor[i] = pos - i;
	}

	// Popula o gr�fico
	for (int i = 0; i < pos; ++i) {
		vetor2[i] = vetor[i];
		Series1->AddXY(i, vetor2[i], "", RGB(179, 89, 255));
	}

	// Limpa as estat�sticas dos algoritmos
	for (int i = 0; i < 7; i++) {
		estatisticas[i].Clear();
	}

	preenchido = true; // Marca o gr�fico como preenchido
	Chart1->Repaint(); // Atualiza o gr�fico
	ShowMessage("Gr�fico atualizado com " + IntToStr(pos) + " valores.");
	ordenado = false; // Marca como n�o ordenado
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para restaurar os valores originais
void __fastcall TForm1::evTrocarOriginal(TObject *Sender) {
	// Restaura os valores do vetor para o estado original (armazenado em vetor2)
	for (int i = 0; i < pos; ++i) {
		vetor[i] = vetor2[i];
	}
	atualizarGrafico(vetor, Chart1, Series1); // Atualiza o gr�fico com os valores restaurados
	ordenado = false; // Marca o vetor como n�o ordenado
	ShowMessage("Valores restaurados para o original."); // Mensagem de confirma��o
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para permitir apenas entrada de n�meros
void __fastcall TForm1::evApenasNumeros(TObject *Sender, System::WideChar &Key) {
	if (!isdigit(Key) && Key != VK_BACK) { // Permite apenas d�gitos e backspace
		Key = 0; // Ignora caracteres inv�lidos
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para limpar o gr�fico e campos de resultados
void __fastcall TForm1::evLimpar(TObject *Sender) {
	Series1->Clear(); // Limpa os dados do gr�fico
	reResultados->Lines->Clear(); // Limpa o texto de resultados
	tbComparacao->Clear(); // Limpa o campo de compara��es
	tbTrocas->Clear(); // Limpa o campo de trocas
	preenchido = false; // Marca que o gr�fico n�o est� preenchido
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para fechar o programa
void __fastcall TForm1::evSair(TObject *Sender) {
	this->Close(); // Fecha a aplica��o
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para buscar um valor no vetor
void __fastcall TForm1::evBuscarValor(TObject *Sender) {
	if (!preenchido) { // Verifica se o gr�fico foi preenchido
		ShowMessage("Gr�fico n�o preenchido.");
		return;
	}

	int valor = StrToIntDef(tbBusca->Text, -1); // L� o valor a ser buscado
	if (valor < 0) { // Verifica se o valor � v�lido
		ShowMessage("Por favor, insira um valor v�lido para buscar.");
		return;
	}

	int resultado; // Armazena a posi��o do valor encontrado (-1 se n�o encontrado)
	clock_t inicio, fim; // Para medir o tempo de execu��o
	int comparar = 0; // N�mero de compara��es realizadas
	float tempo; // Tempo de execu��o

	// Seleciona o algoritmo de busca com base no �ndice do ComboBox
	switch (cbBusca->ItemIndex) {
		case 0: // Busca Linear
			inicio = clock(); // Inicia o cron�metro
			resultado = linearSearch(vetor, pos, valor, comparar, Chart1, Series1); // Executa a busca linear
			fim = clock(); // Termina o cron�metro
			tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execu��o

			reResultados->SelAttributes->Color = clBlue; // Define a cor do texto para o resultado
			// Exibe os resultados
			if (resultado != -1) {
				reResultados->Lines->Add("M�todo LinearSearch - Compara��es: " +
					IntToStr(comparar) + " | Tempo de execu��o: " +
					formatarTempo(tempo) + " | Resultado: " +
					"Valor encontrado na posi��o " + IntToStr(resultado));
			} else {
				reResultados->Lines->Add("M�todo LinearSearch - Compara��es: " +
					IntToStr(comparar) + " | Tempo de execu��o: " +
					formatarTempo(tempo) + " | Resultado: Valor n�o encontrado.");
			}
			break;

		case 1: // Busca Bin�ria
			if (!ordenado) { // A busca bin�ria requer um vetor ordenado
				ShowMessage("Vetor n�o est� ordenado. Ordene o vetor antes de realizar a busca bin�ria.");
				return;
			}
			inicio = clock();
			resultado = binarySearch(vetor, 0, pos - 1, valor, comparar, Chart1, Series1); // Executa a busca bin�ria
			fim = clock();
			tempo = ((float)(fim - inicio)) / CLOCKS_PER_SEC;

			reResultados->SelAttributes->Color = clGreen;
			// Exibe os resultados
			if (resultado != -1) {
				reResultados->Lines->Add("M�todo BinarySearch - Compara��es: " +
					IntToStr(comparar) + " | Tempo de execu��o: " +
					formatarTempo(tempo) + " | Resultado: " +
					"Valor encontrado na posi��o " + IntToStr(resultado));
			} else {
				reResultados->Lines->Add("M�todo BinarySearch - Compara��es: " +
					IntToStr(comparar) + " | Tempo de execu��o: " +
					formatarTempo(tempo) + " | Resultado: Valor n�o encontrado.");
			}
			break;

		default: // Caso nenhum algoritmo v�lido seja selecionado
			ShowMessage("Selecione um algoritmo de busca v�lido!");
			return;
	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para alternar a exibi��o dos valores no gr�fico
void __fastcall TForm1::evMostrarValores(TObject *Sender) {
	static bool valoresVisiveis = false; // Estado inicial: valores escondidos
	valoresVisiveis = !valoresVisiveis; // Alterna o estado
	Series1->Marks->Visible = valoresVisiveis; // Exibe ou oculta os valores no gr�fico
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para abrir a janela de op��es
void __fastcall TForm1::evAbrirOpcoes(TObject *Sender) {
	TFormOptions *formOptions = new TFormOptions(this); // Cria a janela de op��es

	if (formOptions->Visible) { // Se j� estiver vis�vel, esconde
		formOptions->Hide();
	}

	formOptions->ShowModal(); // Exibe a janela de op��es
	delete formOptions; // Libera a mem�ria ap�s fechar
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para abrir a janela de estat�sticas
void __fastcall TForm1::evAbrirEstatisticas(TObject *Sender) {
	TFormGraficos *formGraficos = new TFormGraficos(this); // Cria a janela de estat�sticas

	if (formGraficos->Visible) { // Se j� estiver vis�vel, esconde
		formGraficos->Hide();
	}

	formGraficos->exibirEstatisticas(estatisticas); // Passa as estat�sticas para exibi��o
	formGraficos->ShowModal(); // Exibe a janela de estat�sticas
	delete formGraficos; // Libera a mem�ria ap�s fechar
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Evento para exibir os cr�ditos do programa
void __fastcall TForm1::evCreditos(TObject *Sender) {
	ShowMessage("Feito por: Rychard Gimenez dos Santos \n6o Termo Engenharia da Computa��o 2024"); // Exibe os cr�ditos
}
//---------------------------------------------------------------------------

