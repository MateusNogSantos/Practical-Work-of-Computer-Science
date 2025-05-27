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
    entrada.ignore(1);

    modeloBandas* vetorBandas = new modeloBandas[tamanho];

    getline(entrada,lixo); //Passa a primeira Linha do CSV para lixoStr

    for(int i = 0;i < tamanho;i++){
    entrada >> vetorBandas[i].id; //Lê do CSV o valor #ID da Banda para a variável id
    entrada.ignore(2); //Desconsidera a primeira , e a primeira "
    getline(entrada,vetorBandas[i].nome,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome dentro da struct
    entrada.ignore(1);//Desconsidera a vírgula
    getline(entrada,vetorBandas[i].genero,',');//Lê o genero
    entrada >> vetorBandas[i].numerodeIntegrantes;//Lê o número de integrantes
    entrada.ignore(1);//Desconsidera a vírgurla
    entrada >> vetorBandas[i].tempodeShow;//Lê o tempo de show

    }


    



    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " "<< vetorBandas[i].nome << " " <<
        vetorBandas[i].genero << " " << vetorBandas[i].numerodeIntegrantes << " " <<
        vetorBandas[i].tempodeShow << endl;

    }




    return 0;
}
