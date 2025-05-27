#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*criacao de uma classe que registre os usuarios,essa classe devera ser um vetor,que sera redimencionado dinamicamente,o*/
struct modeloBandas{

    int id,numerodeIntegrantes;
    string nome;
    string genero;
    float tempodeShow;

    };


int main(){

    //mecanismos de leitura
    int tamanho;
    string lixo;
    ifstream entrada("lollapalufla.csv");
    entrada >> tamanho;

    modeloBandas* vetorBandas = new modeloBandas[tamanho];


    getline(entrada,lixo); //Passa a primeira Linha do CSV para lixoStr

    for(int i = 0;i < tamanho;i++){
    entrada >> vetorBandas[i].id; //Lê do CSV o valor #ID da Banda para a variável id
    entrada.ignore(2); //Desconsidera a primeira , e a primeira "
    getline(entrada,vetorBandas[i].nome,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome dentro da struct
    entrada.ignore(2);//Desconsidera a virgula e a aspas duplas
    entrada >> vetorBandas[i].genero;
    entrada.ignore(1);
    entrada >> vetorBandas[i].numerodeIntegrantes;
    entrada.ignore(1);
    entrada >> vetorBandas[i].tempodeShow;

    }



    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " " << vetorBandas[i].nome << " " << vetorBandas[i].genero << " " << vetorBandas[i].numerodeIntegrantes;

    }




    return 0;
}
