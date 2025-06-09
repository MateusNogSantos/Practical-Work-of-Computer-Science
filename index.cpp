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

    salvarAlteracao(vetorBandas,tamanho);

    return 0;
}