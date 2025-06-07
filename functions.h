/*Esse arquivo é um "cabeçalho", o qual a utilidade é "nomear" as funções presentes em "functions.cpp".
Ao "nomearmos" essas funções aqui, podemos usar esse arquivo "functions.h" para chamar as funções 
que estão no "functions.cpp" no "index.cpp" utilizando o #include "functions.h".
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

/*Criacao de uma classe que registre os usuarios,essa classe devera ser um vetor,que sera redimencionado dinamicamente,o*/
struct modeloBandas{

    int id,numerodeIntegrantes;
    string nome;
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
void adicionar(modeloBandas *&vetorTrabalhado, int &tamanho, string nome, string genero, int numerodeIntegrantes, int tempodeShow);
void removerNome(modeloBandas *&vetorTrabalhado, int &tamanho, string nome);
void removerID(modeloBandas *&vetorTrabalhado, int &tamanho, int ID);
bool verificaADD(modeloBandas* &vet,int tamanho,string nome);

#endif