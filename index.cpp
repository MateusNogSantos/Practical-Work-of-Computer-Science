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
    int num, tempo;
    string nome, genero;
    bool conf;

    getline(cin, nome);
    cin >>  genero
        >>  num
        >>  tempo;

    cout    << "Nome: " << nome << " "
            << "Gênero: " << genero << " "
            << "Integrantes: " << num << " "
            << "Tempo de Show: " << tempo << " " << endl;

    adicionar(vetorBandas, tamanho, conf,nome, genero, num, tempo);

    salvarAlteracao(vetorBandas, tamanho);

    return 0;
}