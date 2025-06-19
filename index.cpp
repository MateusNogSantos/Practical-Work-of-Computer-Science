#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.h"
using namespace std;

/*DE EXTREMA IMPORTÂNCIA:ao acabar o programa mudar o ofstream para ("lolapalufla.txt")*/

int main(){

    int tamanho = 40;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    leitura(vetorBandas,tamanho);


    /*Parte de testes*/

    //Vetornovo = ordenarPorNumerodeIntegrantes(vetorBandas,tamanho);

    /*
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
    */

    for(int i = 0;i < 100;i++){

        cout << vetorBandas[i].nome << endl;
    }

    return 0;
}