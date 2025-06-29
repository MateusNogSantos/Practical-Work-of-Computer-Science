/*Esse arquivo é um "cabeçalho", o qual a utilidade é "nomear" as funções presentes em "functions.cpp".
Ao "nomearmos" essas funções aqui, podemos usar esse arquivo "functions.h" para chamar as funções 
que estão no "functions.cpp" no "index.cpp" utilizando o #include "functions.h".
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <cstring>
using namespace std;

/*Criacao de uma classe que registre os usuarios,essa classe devera ser um vetor,que sera redimencionado dinamicamente,o*/
struct modeloBandas{

    int id,numerodeIntegrantes;
    char nome[100];
    char genero[20];
    float tempodeShow;

    };

/*Declaração das Funções contidas no programa*/
void comparaNome(modeloBandas* &vetorTrabalhado,int indiceDoMenor,int indiceComparado,int posicaoDaLetra);
void ordenarPorNome(modeloBandas* &vetorTrabalhado,int tamanho);
int particionaVetorID(modeloBandas* &vetorTrabalhado,int PosInicial,int PosFinal);    
void quicksortID(modeloBandas* &vet,int posPivo,int posFinal);
void ordenarPorID(modeloBandas* &vetOrdem,int tamanho);
int particionaVetorIntegrantes(modeloBandas* &vetorTrabalhado,int posInicial,int posFinal);
void quicksortIntegrantes(modeloBandas* &vetorTrabalhado,int posPivo,int posFinal);
void ordenarPorNumDeIntegrantes(modeloBandas* &vetorTrabalhado,int tamanho);
int particionaVetorTempoDeShow(modeloBandas* &vetor, int posInicial, int posFinal);
void quicksortTempoDeShow(modeloBandas* &vetor, int posPivo, int posFinal);
void ordenaPorTempoDeShow(modeloBandas* &vetor, int tamanho);
int buscaBinaria(int IDuser, int posicaoInicial, int posicaoFinal, modeloBandas *vetordeBusca);
void frontendExibirMenuOrdem(string opcoes[], int totalOpcoes, int selecionado);
int buscaPorID(int IDuser, int tamanho, modeloBandas *vetorTrabalhado);
int buscaPorNome(string nomeDaBanda, int tamanho, modeloBandas *vetorTrabalhado);
float buscadeGeneroTempodeShow(string generoPesquisado, int tamanho, modeloBandas *vetorTrabalhado);
void redimencionar(modeloBandas *&vet, int &tamanho);
void leitura(modeloBandas *&Vetortrabalhado, int &tamanho);
bool verificaRedimencionar(modeloBandas* vet, int &tamanho);
int ultimoID(modeloBandas* vetorTrabalhado,int tamanho);
bool verificaADD(modeloBandas* &vet,int tamanho,string nome);
void adicionar(modeloBandas* &vetorTrabalhado, int &tamanho,bool &confirmacao, string nome, string genero, int numerodeIntegrantes, int tempodeShow);
void removerNome(modeloBandas *&vetorTrabalhado, int &tamanho, string nome,bool &confirmacao);
void removerID(modeloBandas *&vetorTrabalhado, int &tamanho, int ID,bool &confirmacao);
void lerDoBinario(modeloBandas* &vetorTrabalhado,int &tamanho);
void salvarAlteracao(modeloBandas* vet,int tamanho);
void limparTela();
void frontendBuscaPorGenero(modeloBandas* vetorBandas,int tamanho);
void frontendBuscaID(modeloBandas* vetorBandas,int tamanho);
void frontendBuscaNome(modeloBandas* vetorBandas,int tamanho);
void frontendExibirMenuOrdenar(modeloBandas* vetorBandas,int tamanho, int ordem, int tipoOrdenacao);
void frontendRemoverPorID(modeloBandas* &vetorBandas,int tamanho);
void frontendRemoverPorNome(modeloBandas* &vetorBandas,int tamanho);
void frontendMenuPartipantes(modeloBandas* vetorBandas,int tamanho);
void frontendMenuDeRemocao(modeloBandas* &vetorBandas,int tamanho);
void frontendExibirMenuLeitura(string opcoes[], int totalOpcoes, int selecionado);
void frontendExibirMenuParticipantes(string opcoes[], int totalOpcoes, int selecionado);
void frontendExibirMenuDeBusca(string opcoes[], int totalOpcoes, int selecionado);
void frontendMenuPrincipal(modeloBandas* &vetorBandas,int &tamanho);
void frontendLeitura(modeloBandas* &vetorBandas,int &tamanho);
void frontendExibirMenuPrincipal(string opcoes[], int totalOpcoes, int selecionado);
void frontendExibirMenuDeRemocao(string opcoes[], int totalOpcoes, int selecionado);
int frontendMenuSelecionavel(string opcoes[], int totalOpcoes, int menu);
void frontendMenuPrincipal(modeloBandas* &vetorBandas,int &tamanho);
void frontendAdicionar(modeloBandas* &vetor, int &tamanho);

#endif