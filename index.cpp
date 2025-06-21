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

    //leitura(vetorBandas,tamanho);

    //ordenarPorNome(vetorBandas,tamanho);

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

    //salvarAlteracao(vetorBandas,tamanho);

    lerDoBinario(vetorBandas,tamanho);


    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].nome << " " << vetorBandas[i].numerodeIntegrantes << endl;
    }

    cout << tamanho;

    return 0;
}