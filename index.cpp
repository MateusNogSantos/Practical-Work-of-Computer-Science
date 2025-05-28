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


/*Função que recebe o o id do usuário,tamanho do vetor trabalhado e o próprio vetor,e retorna a posição da banda(índice) no vetor de classes*/
int buscaPorID(int IDuser,int tamanho,modeloBandas *vetorTrabalhado){

    int posicao,i = 0;
    bool encontrado = false;

    //Laço de repetição que percorre o vetorTrabalhado e para ao encontrar.
    while(i < tamanho and !encontrado){

        //Compara o id do usuário ao do vetorTrabalhado e ao encontrar atribui i à variável posição.
        if(IDuser == vetorTrabalhado[i].id){

            posicao = i;
            encontrado = true;//sentinela de controle

        }

        i++;
    }

    //Caso não encontrado a variável posicao e marcada com -1.
    if(!encontrado){

        posicao = -1;
    }

    return posicao;
}

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

    /*Parte de testes*/

    int idProcura;

    cin >> idProcura;

    cout << buscaPorID(idProcura,tamanho,vetorBandas) << endl;

    
    for(int i = 0;i < tamanho;i++){

        cout << vetorBandas[i].id << " "<< vetorBandas[i].nome << " " <<
        vetorBandas[i].genero << " " << vetorBandas[i].numerodeIntegrantes << " " <<
        vetorBandas[i].tempodeShow << endl;
    }

    return 0;
}
