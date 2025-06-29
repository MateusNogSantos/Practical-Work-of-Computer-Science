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

/*DE EXTREMA IMPORTÂNCIA:ao acabar o programa mudar o ofstream para ("lolapalufla.txt") e desalocar dinamicamente os vetores*/

int main(){
    #if defined(_WIN32)
        system("chcp 65001 > nul");
    #endif

    int tamanho = 40;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    frontendLeitura(vetorBandas, tamanho);

    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].nome << endl;
    }

    return 0;
}