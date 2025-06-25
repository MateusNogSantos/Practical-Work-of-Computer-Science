#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

/*DE EXTREMA IMPORTÂNCIA:ao acabar o programa mudar o ofstream para ("lolapalufla.txt") e desalocar dinamicamente os vetores*/

int main(){

    int tamanho = 40;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    frontendLeitura(vetorBandas,tamanho);

    /*
    leitura(vetorBandas, tamanho);

    cout << endl << "_______________________________________________________________" << endl;
    cout << "VETOR ANTES DE SER ORDENADO POR TEMPO DE SHOW: " << endl << endl;
    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " " 
             << vetorBandas[i].nome << " " 
             << vetorBandas[i].genero << " " 
             << vetorBandas[i].tempodeShow << " " << endl;
    }

    cout << endl << "_______________________________________________________________" << endl;
    cout << endl <<"VETOR DEPOIS DE SER ORDENADO POR TEMPO DE SHOW: " << endl << endl;

    ordenaPorTempoDeShow(vetorBandas, tamanho);*/
    
    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " " 
             << vetorBandas[i].nome << " " 
             << vetorBandas[i].genero << " " 
             << vetorBandas[i].tempodeShow << " " << endl;
    }

  

    return 0;
}