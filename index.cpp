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

    
    for(int i = 0;i < 20;i++){

        string nomedabanda,generodabanda;
        int numerodeint;
        float tempodes;

        cin >> nomedabanda >> generodabanda >> numerodeint >> tempodes;

        adicionar(vetorBandas,tamanho,nomedabanda,generodabanda,numerodeint,tempodes);

    }

    
    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " "<< vetorBandas[i].nome << " " << vetorBandas[i].genero << " " << vetorBandas[i] .numerodeIntegrantes << " " << vetorBandas[i].tempodeShow << endl;

    }

    return 0;
}