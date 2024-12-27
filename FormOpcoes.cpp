//---------------------------------------------------------------------------

#include <vcl.h>  // Inclui a biblioteca da Visual Component Library (VCL) do C++ Builder
#pragma hdrstop

#include "FormOpcoes.h"  // Inclui o cabeçalho do formulário de opções
#include "Unit1.h"       // Inclui o cabeçalho do formulário principal ou outro módulo necessário
//---------------------------------------------------------------------------

#pragma package(smart_init)  // Indica ao compilador que o pacote de componentes está configurado corretamente
#pragma resource "*.dfm"    // Define que o arquivo de recursos (layout do formulário) está incluído

// Declaração da variável global para o formulário de opções
TFormOptions *FormOptions;

//---------------------------------------------------------------------------
// Construtor do formulário TFormOptions
__fastcall TFormOptions::TFormOptions(TComponent* Owner)
	: TForm(Owner)  // Chama o construtor da classe base TForm para inicializar o formulário
{
    // Carrega as configurações globais para os RadioButtons no formulário

    // Verifica a configuração global de delay para comparações e marca o RadioButton correspondente
	if (delayCompare == 1000) btncompLenta->Checked = true;
	else if (delayCompare == 100) btncompNormal->Checked = true;
	else btncompRapida->Checked = true;

    // Verifica a configuração global de delay para trocas e marca o RadioButton correspondente
	if (delaySwap == 1000) btntrocaLenta->Checked = true;
	else if (delaySwap == 100) btntrocaNormal->Checked = true;
	else btntrocaRapida->Checked = true;

    // Verifica a configuração global de valor máximo e marca o RadioButton correspondente
	if (maxVal == 1000) btnGrande->Checked = true;
	else if (maxVal == 100) btnMedio->Checked = true;
	else btnPequeno->Checked = true;

    // Verifica o modo de geração atual e seleciona o ItemIndex correto no ComboBox
	if (modoGeracao == 0) ComboBox1->ItemIndex = 0;
	else if (modoGeracao == 1) ComboBox1->ItemIndex = 1;
	else ComboBox1->ItemIndex = 2;
}
//---------------------------------------------------------------------------

// Evento de cancelamento: fecha o formulário sem aplicar mudanças
void __fastcall TFormOptions::evCancelar(TObject *Sender)
{
    this->Close();  // Fecha o formulário
}
//---------------------------------------------------------------------------

// Evento de confirmação: atualiza as variáveis globais com os valores selecionados
void __fastcall TFormOptions::evConfirmar(TObject *Sender)
{
    // Atualiza o valor de delayCompare com base no RadioButton selecionado
	if (btncompLenta->Checked) delayCompare = 1000;
	else if (btncompNormal->Checked) delayCompare = 100;
	else delayCompare = 1;

    // Atualiza o valor de delaySwap com base no RadioButton selecionado
	if (btntrocaLenta->Checked) delaySwap = 1000;
	else if (btntrocaNormal->Checked) delaySwap = 100;
    else delaySwap = 1;

    // Atualiza o valor de maxVal com base no RadioButton selecionado
	if (btnGrande->Checked) maxVal = 1000;
	else if (btnMedio->Checked) maxVal = 100;
	else maxVal = 10;

    // Atualiza o valor de modoGeracao com base no item selecionado no ComboBox
	if (ComboBox1->ItemIndex == 0) modoGeracao = 0;
	else if (ComboBox1->ItemIndex == 1) modoGeracao = 1;
	else modoGeracao = 2;

    // Fecha o formulário após aplicar as mudanças
	Close();
}
//---------------------------------------------------------------------------

// Evento de reset: restaura os valores padrão para os controles de configuração
void __fastcall TFormOptions::evResetar(TObject *Sender)
{
    // Marca as opções padrão nos RadioButtons
	btncompNormal->Checked = true;  // Delay de comparação normal
	btntrocaNormal->Checked = true;  // Delay de troca normal
	btnMedio->Checked = true;       // Valor máximo médio

    // Restaura as configurações globais para os valores padrão
	delayCompare = 100;
	delaySwap = 100;
	maxVal = 100;

    // Restaura o valor padrão do ComboBox
	ComboBox1->ItemIndex = 0;  // Modo de geração padrão
}
//---------------------------------------------------------------------------


