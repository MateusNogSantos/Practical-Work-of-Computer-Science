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
    string genero;
    float tempodeShow;

    };

int buscaBinaria(int IDuser, int posicaoInicial, int posicaoFinal, modeloBandas *vetordeBusca);
int buscaPorID(int IDuser, int tamanho, modeloBandas *vetorTrabalhado);
int buscaPorNome(string nomeDaBanda, int tamanho, modeloBandas *vetorTrabalhado);
float buscadeGeneroTempodeShow(string generoPesquisado, int tamanho, modeloBandas *vetorTrabalhado);
void redimencionar(modeloBandas *&vet, int &tamanho);
void leitura(modeloBandas *&Vetortrabalhado, int &tamanho);
bool verificaRedimencionar(modeloBandas* vet, int &tamanho);
int ultimoID(modeloBandas* vetorTrabalhado);
bool verificaADD(modeloBandas* &vet,int tamanho,string nome);
void adicionar(modeloBandas *&vetorTrabalhado, int &tamanho,bool &confirmacao, string nome, string genero, int numerodeIntegrantes, int tempodeShow);
void removerNome(modeloBandas *&vetorTrabalhado, int &tamanho, string nome,bool &confirmacao);
void removerID(modeloBandas *&vetorTrabalhado, int &tamanho, int ID,bool &confirmacao);
modeloBandas* ordenarPorNome(modeloBandas *vet,int tamanho);
modeloBandas* ordenarPorTempoDeShow();
modeloBandas* ordenarPorNumerodeIntegrantes(modeloBandas *vet,int tamanho);
void salvarAlteracao(modeloBandas* vet,int tamanho);

#endif