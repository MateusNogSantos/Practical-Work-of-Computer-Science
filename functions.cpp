/*Esse aquivo é apenas a modularização das funções utilizadas em "index.cpp".

Para que essas funções funcionem no "index.cpp" é nessessário um arquivo "cabeçalho",
o qual identificará cada função contida nesse arquivo, para que posteriormente seja utilizado na main.

É IMPORTANTE QUE O "Makefile" inclua o "index.cpp" e esse arquivo, para que seja gerado um executável 
que rode "index.cpp" e este arquivo paralelamente, pois como "index.cpp" utiliza as funções deste arquivo
é necessário que ambos rodem paralelamente, o que será feito pelo executável criado pelo Makefile.
*/

#include "functions.h"
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

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

//Função que redimenciona o vetor trabalhado de 5 em 5 posições
void redimencionar(modeloBandas *&vet,int &tamanho){

    //adiciona 5 ao tamanho antigo do vetor
    tamanho += 5;

    //cria um novo vetor com o espaco adequado na memória(acrescido)
    modeloBandas* newVet = new modeloBandas[tamanho];

    //passa os dados da struct antiga ao novo vetor
    for(int i = 0;i < (tamanho-5);i++){

        newVet[i] = vet[i];

    }


    //atribui os novos índices adicionados o valor 0.
    for(int i = tamanho-5;i < tamanho;i++){

        newVet[i].id = 0;
    }

    //Deleta o espaco do vetor antigo e aponta para o novo local
    delete [] vet;
    vet = newVet;

}

//Função que faz a leitura leitura dos dados no arquivo CSV e quando necessário chama a função redimencionar
void leitura(modeloBandas *&Vetortrabalhado,int &tamanho){

    int i = 0; //Contador de repetições possíveis
    string lixo;//caracteres que não serão lidos

    ifstream entrada("lollapalufla.csv");

    getline(entrada,lixo); //Passa a primeira linha do csv para a variável lixo

    //enquanto o id for diferente de 0,a leitura ocorrerá normalmente
    while(entrada >> Vetortrabalhado[i].id){

        entrada.ignore(2); //Desconsidera a primeira , e a primeira "
        getline(entrada,Vetortrabalhado[i].nome,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome dentro da struct
        entrada.ignore(1);//Desconsidera a vírgula
        getline(entrada,Vetortrabalhado[i].genero,',');//Lê o genero
        entrada >> Vetortrabalhado[i].numerodeIntegrantes;//Lê o número de integrantes
        entrada.ignore(1);//Desconsidera a vírgurla
        entrada >> Vetortrabalhado[i].tempodeShow;//Lê o tempo de show

        i++;

        //compara a repetição(variável i) ao tamanho do vetor,e se for igual chama a função redimencionar.
        if(i == tamanho){

           redimencionar(Vetortrabalhado,tamanho);
        }

    }
}

//Função que verifica se ha vaga para adicionar uma banda no vetor;
bool verificaRedimencionar(modeloBandas* vet,int &tamanho){

    //percorre o vetor buscando id's em branco
    for(int i = 0;i < tamanho;i++){

        //ao encontrar o id em branco retorna 0(não necessário redimencionar)
        if(vet[i].id == 0){

            return 0;
        }

    }

    //se nao encontrar retorna 1(necessário redimencionar)
    return 1;

}

//Função que retorna o ultimo id adicionado do vetorTrabalhado
int ultimoID(modeloBandas* vetorTrabalhado){

    int i = 0,ultID;

    //Laço que percorre o vetor enquanto o indice não for 0
    while(vetorTrabalhado[i].id){

        //atribui ao ultID,o id que está na posição i do vetor trabalhado
        ultID = vetorTrabalhado[i].id;

        i++;

    }

    return ultID;

}

//Função que verifica se o nome escolhido para uma banda já existe dentro do vetor.
bool verificaADD(modeloBandas* &vet,int tamanho,string nome){

    //chama a função buscaPorNome(caso o nome não seja encontrado o retorno é -1)e compara com -1.
    //caso base 1:o nome não é encontrado e o retorno será 1.
    if(buscaPorNome(nome,tamanho,vet) == -1){

        return 1;

    }
    //o nome é encontrado e o retorno será 0.
    else{

        return 0;
    }
}

//Função que adiciona novas bandas ao vetorBandas,e se necessário redimenciona;
void adicionar(modeloBandas *&vetorTrabalhado,int &tamanho,bool &confirmacao,string nome,string genero,int numerodeIntegrantes,int tempodeShow){

    if(verificaADD(vetorTrabalhado,tamanho,nome)){

    //Verifica se é necessário redimencionar o vetor.
    if(verificaRedimencionar(vetorTrabalhado,tamanho)){

        redimencionar(vetorTrabalhado,tamanho);

    }

    //Atribui ao retorno da função ultimoID acrescido de uma unidade à variável newID
    int newID = ultimoID(vetorTrabalhado)+1,indiceADD;

    //percorre o vetorTrabalhado ate achar um id que seja igual a zero(ou seja,não há bandas registradas)
    for(int i = 0;i < tamanho;i++){

        //ao achar um id diferente de zero irá atribuir o valor,quando não achar mais valores diferentes de zero,o valor atribuido será do ultimo id que há banda registrada
        if(vetorTrabalhado[i].id != 0){

            //adiciona uma unidade para ser o índice que não há bandas adicionadas
            indiceADD = i+1;
        }

    }

    //atribui os atributos da função para o vetorBandas
    vetorTrabalhado[indiceADD].id = newID;
    vetorTrabalhado[indiceADD].genero = genero;
    vetorTrabalhado[indiceADD].nome = nome;
    vetorTrabalhado[indiceADD].numerodeIntegrantes = numerodeIntegrantes;
    vetorTrabalhado[indiceADD].tempodeShow = tempodeShow;

    //Retorna true a variável de confirmação da adicao no vetor.
    confirmacao = true;

    }
    //Retorna a variável de confirmação que a adição não foi efetuada,por existir uma banda ja com esse nome dentro do vetor.
    else{

        confirmacao = false;
    }

}

//Função que remove pelo nome,caso não encontrado,retorna falso à variável confirmacao.
void removerNome(modeloBandas *&vetorTrabalhado,int &tamanho,string nome,bool &confirmacao){

    confirmacao = false;

    //Laço de repetição que percorre as posições do vetor.
    for(int i= 0; i<tamanho; i++){

        //Condicional que compara o nome ao do vetor na posição i e,ao encontrar,marca o id como -1 e a variável confirmação recebe true.
        if(nome == vetorTrabalhado[i].nome){
            
            vetorTrabalhado[i].id = -1;
            confirmacao = true;

        }
    }

}

//Função que remove pelo ID,caso não encontrado,retorna falso à variável confirmação.
void removerID(modeloBandas *&vetorTrabalhado,int &tamanho, int ID,bool &confirmacao){

    confirmacao = false;

    //Laço de repetição que percorre o vetor trabalhado.
    for(int i= 0; i<tamanho; i++){

        //Condicional que compara o ID ao do vetor na posição i e,ao encontrar,marca a variáver confirmacao como true e o id como -1.
        if(ID == vetorTrabalhado[i].id){

            vetorTrabalhado[i].id=-1;
            confirmacao = true;

        }
    }

}

modeloBandas* ordenarPorNome(modeloBandas *vet,int tamanho){}
modeloBandas* ordenarPorTempoDeShow(){}
modeloBandas* ordenarPorNumerodeIntegrantes(modeloBandas *vet,int tamanho){}


//Função que deleta e cria um novo arquivo com o novo vetor
void salvarAlteracao(modeloBandas* vet,int tamanho){

    //OBS:Temporariamente o arquivo que irá salvar será o "saida.csv",para em casos de erros nn perder o banco de dados original.
    ofstream saida("saida.csv");
    ofstream saidaBinario("saidaBinario.dat");

    //Representa o molde que o csv irá seguir
    saida << "#ID da Banda,Nome da Banda,Genero Musical,Quantidade de Integrantes,Tempo de Show" << endl;

    //Um laço de repetição que irá gravar todo o vetor(já ajustado) no csv e no arquivo binário.
    for(int i = 0;i < tamanho;i++){

        //compara se é maior que 0,pois exclui campos não gravados e excluídos
        if(vet[i].id > 0){
            //CSV
            saida << vet[i].id  << ',' << '"' << vet[i].nome << '"' << ',' << vet[i].genero << ',' << vet[i].numerodeIntegrantes << ',' << vet[i].tempodeShow << endl;
            
            //Binário
            saidaBinario.write(reinterpret_cast<char*>(&vet[i].id), sizeof(int));

            unsigned int tamNome = vet[i].nome.size();
            saidaBinario.write(reinterpret_cast<char*>(&tamNome), sizeof(unsigned int));
            saidaBinario.write(vet[i].nome.c_str(), tamNome);

            unsigned int tamGenero = vet[i].genero.size();
            saidaBinario.write(reinterpret_cast<char*>(&tamGenero), sizeof(unsigned int));
            saidaBinario.write(vet[i].genero.c_str(), tamGenero);

            saidaBinario.write(reinterpret_cast<char*>(&vet[i].numerodeIntegrantes), sizeof(int));

            saidaBinario.write(reinterpret_cast<char*>(&vet[i].tempodeShow), sizeof(float));
        }
    };

    saidaBinario.close();
    saida.close();

}