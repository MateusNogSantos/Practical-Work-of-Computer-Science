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


//Funçao recursiva que divide o vetorTrabalhado ao meio compara e usa recursão para melhor desempenho
int buscaBinaria(int IDuser,int posicaoInicial,int posicaoFinal,modeloBandas *vetordeBusca){


    //define o meio para a comparação do ID buscado com o meio do vetor 
    int meio = (posicaoFinal+posicaoInicial)/2;


    //caso base:elemento e encontrado e a função retorna sua posição no vetor.
    if(IDuser == vetordeBusca[meio].id){

        return meio;
    }
    // verifica se o ID buscado ainda pode ser buscado no vetor,pois quando a posição inicial for igual a posição final,quer dizer que o elemento não esta no vetor
    else if(posicaoInicial < posicaoFinal){

        //verifica se o IDuser é menor que o meio do vetor,se sim faz recursão,porém a posição final recebe (meio-1),dividindo o vetor.
        if(IDuser < vetordeBusca[meio].id){

            return buscaBinaria(IDuser,posicaoInicial,meio-1,vetordeBusca);
        }
        //verifica se o IDuser é maior que o meio do vetor,se sim faz recursão,porém a posição inicial recebe (meio+1),dividindo o vetor
        else if(IDuser > vetordeBusca[meio].id){

            return buscaBinaria(IDuser,meio+1,posicaoFinal,vetordeBusca);
        }

    }
    //caso base:ao verificar que o elemento não está no vetor,retorna -1
    else{

        return -1;
    }

    return 0;

}

/*Função que recebe o o id do usuário,tamanho do vetor trabalhado e o próprio vetor,e retorna a posição da banda(índice do vetorBandas) no vetor de classes*/
int buscaPorID(int IDuser,int tamanho,modeloBandas *vetorTrabalhado){

    int posicao;
    int posInicial = 0,posFinal = tamanho;


    //posição recebe o retorno da função buscaBinária
    posicao = buscaBinaria(IDuser,posInicial,posFinal,vetorTrabalhado);

    return posicao;

}


/*Função que recebe o um nome escrito pelo usuário e compara ao vetor,retornando a posição(índice do vetorBandas)*/
int buscaPorNome(string nomeDaBanda,int tamanho,modeloBandas *vetorTrabalhado){

    int posicao,i = 0;
    bool encontrado = false;
    

    //Laço de repetição que percorre todas os índices do vetorBandas
    while(i < tamanho and (!encontrado)){

        //ao encontrar,a posição recebe a variável i(índice do vetorBandas)
        if(vetorTrabalhado[i].nome == nomeDaBanda){

            posicao = i;
            encontrado = true;//sentinela para evitar repetição desnecessária
        }

    i++;
    }

    //caso não encontrar,a posição é marcada com -1
    if(!encontrado){

        posicao = -1;
    }

    return posicao;
}

/*Função que percorre todo o vetor comparando o gênero ao gêneroPesquisado,e retorna o o tempo de show daquele gênero.*/
float buscadeGeneroTempodeShow(string generoPesquisado,int tamanho,modeloBandas *vetorTrabalhado){

    float tempodeShow = 0;
    
    //laço de repetição que percorre todo o vetorTrabalhado
    for(int i = 0;i < tamanho;i++){

        //compara se o genero é o mesmo da posição comparada,se sim soma ao tempodeShow.
        if(generoPesquisado == vetorTrabalhado[i].genero){
        
            tempodeShow += vetorTrabalhado[i].tempodeShow;

        }
    }

    return tempodeShow;
}

modeloBandas* redimencionar(modeloBandas *vet,int &tamanho){

    tamanho += 5;

    modeloBandas* newVet = new modeloBandas[tamanho];

    for(int i = 0;i < (tamanho-5);i++){

        newVet[i].id = vet[i].id;
        newVet[i].nome = vet[i].nome;
        newVet[i].genero = vet[i].genero;
        newVet[i].numerodeIntegrantes = vet[i].numerodeIntegrantes;
        newVet[i].tempodeShow = vet[i].tempodeShow;
    }

    for(int i = tamanho-5;i < tamanho;i++){

        newVet[i].id = 0;

    }

    delete [] vet;

    return newVet;

}

void leitura(modeloBandas *Vetortrabalhado){

int i = 0; //Contador de repetições possíveis
int tamanho = 40;
string lixo;

ifstream entrada("lollapalufla.csv");

getline(entrada,lixo); //Passa a primeira linha do csv para a variável lixo



while(entrada >> Vetortrabalhado[i].id){

    entrada.ignore(2); //Desconsidera a primeira , e a primeira "
    getline(entrada,Vetortrabalhado[i].nome,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome dentro da struct
    entrada.ignore(1);//Desconsidera a vírgula
    getline(entrada,Vetortrabalhado[i].genero,',');//Lê o genero
    entrada >> Vetortrabalhado[i].numerodeIntegrantes;//Lê o número de integrantes
    entrada.ignore(1);//Desconsidera a vírgurla
    entrada >> Vetortrabalhado[i].tempodeShow;//Lê o tempo de show

    i++;

    /*if(i == tamanho){

        Vetortrabalhado = redimencionar(Vetortrabalhado,tamanho);

    }*/
   
}

} 

int main(){

    modeloBandas* vetorBandas = new modeloBandas[100];

    leitura(vetorBandas);


    /*Parte de testes*/

    int idProcura;
    string genero;
    string nomeProcura;


    for(int i = 0;i < 100;i++){
    cout << vetorBandas[i].id << " " << vetorBandas[i].nome << endl;
    }

    //cin >> genero;

    //cout << buscadeGeneroTempodeShow(genero,100,vetorBandas) << endl;

    return 0;
}
