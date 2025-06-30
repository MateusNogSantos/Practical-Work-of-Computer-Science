#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

/*
Tema: Bandas.

Nomes:  > Mateus Nogueira dos Santos Turma:10B.
        > Bruno dos Santos Custódio
        > Gabriel Carvalho Batista

*/

int main(){
    #if defined(_WIN32)
        system("chcp 65001 > nul");
    #endif

    int tamanho = 40;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    //Chama a função em outro arquivo.
    frontendLeitura(vetorBandas, tamanho);

    //Desaloca o vetor.
    delete [] vetorBandas;

    return 0;
}