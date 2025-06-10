#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

int main(){

    int tamanho = 40;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    leitura(vetorBandas,tamanho);


    /*Parte de testes*/

    bool confirmation = 0;

    adicionar(vetorBandas,tamanho,confirmation,"U22","Rock",2,2.0);

    cout << confirmation;

    salvarAlteracao(vetorBandas,tamanho);

    return 0;
}