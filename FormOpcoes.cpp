//---------------------------------------------------------------------------

#include <vcl.h>  // Inclui a biblioteca da Visual Component Library (VCL) do C++ Builder
#pragma hdrstop

#include "FormOpcoes.h"  // Inclui o cabe�alho do formul�rio de op��es
#include "Unit1.h"       // Inclui o cabe�alho do formul�rio principal ou outro m�dulo necess�rio
//---------------------------------------------------------------------------

#pragma package(smart_init)  // Indica ao compilador que o pacote de componentes est� configurado corretamente
#pragma resource "*.dfm"    // Define que o arquivo de recursos (layout do formul�rio) est� inclu�do

// Declara��o da vari�vel global para o formul�rio de op��es
TFormOptions *FormOptions;

//---------------------------------------------------------------------------
// Construtor do formul�rio TFormOptions
__fastcall TFormOptions::TFormOptions(TComponent* Owner)
	: TForm(Owner)  // Chama o construtor da classe base TForm para inicializar o formul�rio
{
    // Carrega as configura��es globais para os RadioButtons no formul�rio

    // Verifica a configura��o global de delay para compara��es e marca o RadioButton correspondente
	if (delayCompare == 1000) btncompLenta->Checked = true;
	else if (delayCompare == 100) btncompNormal->Checked = true;
	else btncompRapida->Checked = true;

    // Verifica a configura��o global de delay para trocas e marca o RadioButton correspondente
	if (delaySwap == 1000) btntrocaLenta->Checked = true;
	else if (delaySwap == 100) btntrocaNormal->Checked = true;
	else btntrocaRapida->Checked = true;

    // Verifica a configura��o global de valor m�ximo e marca o RadioButton correspondente
	if (maxVal == 1000) btnGrande->Checked = true;
	else if (maxVal == 100) btnMedio->Checked = true;
	else btnPequeno->Checked = true;

    // Verifica o modo de gera��o atual e seleciona o ItemIndex correto no ComboBox
	if (modoGeracao == 0) ComboBox1->ItemIndex = 0;
	else if (modoGeracao == 1) ComboBox1->ItemIndex = 1;
	else ComboBox1->ItemIndex = 2;
}
//---------------------------------------------------------------------------

// Evento de cancelamento: fecha o formul�rio sem aplicar mudan�as
void __fastcall TFormOptions::evCancelar(TObject *Sender)
{
    this->Close();  // Fecha o formul�rio
}
//---------------------------------------------------------------------------

// Evento de confirma��o: atualiza as vari�veis globais com os valores selecionados
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

    // Fecha o formul�rio ap�s aplicar as mudan�as
	Close();
}
//---------------------------------------------------------------------------

// Evento de reset: restaura os valores padr�o para os controles de configura��o
void __fastcall TFormOptions::evResetar(TObject *Sender)
{
    // Marca as op��es padr�o nos RadioButtons
	btncompNormal->Checked = true;  // Delay de compara��o normal
	btntrocaNormal->Checked = true;  // Delay de troca normal
	btnMedio->Checked = true;       // Valor m�ximo m�dio

    // Restaura as configura��es globais para os valores padr�o
	delayCompare = 100;
	delaySwap = 100;
	maxVal = 100;

    // Restaura o valor padr�o do ComboBox
	ComboBox1->ItemIndex = 0;  // Modo de gera��o padr�o
}
//---------------------------------------------------------------------------


