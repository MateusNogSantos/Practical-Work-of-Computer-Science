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
#include <cstring>
using namespace std;

//Função que compara a palavra que deve ser a primeira na ordem alfabética
void comparaNome(modeloBandas* &vetorTrabalhado,int indiceDoMenor,int indiceComparado,int posicaoDaLetra){

    //struct auxiliar
    modeloBandas aux;

    //variáveis para controle de igualdade
    int controleDoMenor,controleDoComparado;

    //variável que garante que todas as letras(maiúsculas e minúsculas)sejam comparadas da mesma forma
    if((int)vetorTrabalhado[indiceDoMenor].nome[posicaoDaLetra] < 97)controleDoMenor = 32;
    else controleDoMenor = 0;

    if((int)vetorTrabalhado[indiceComparado].nome[posicaoDaLetra] < 97)controleDoComparado = 32;
    else controleDoComparado = 0;


    //Se forem letras iguais
    if((int)vetorTrabalhado[indiceDoMenor].nome[posicaoDaLetra] + controleDoMenor == (int)vetorTrabalhado[indiceComparado].nome[posicaoDaLetra] + controleDoComparado){

        //Soma uma unidade na posição dos indices das letras que serão comparadas
        posicaoDaLetra++;
        //Faz recursão com a nova posição comparada
        comparaNome(vetorTrabalhado,indiceDoMenor,indiceComparado,posicaoDaLetra);

    }

    //Condicional que verifica se há uma letra anterior,se sim,coloca em sua posição adequada e passa a que estava como menor para a posição comparada.
    else if((int)vetorTrabalhado[indiceDoMenor].nome[posicaoDaLetra] + controleDoMenor > (int)vetorTrabalhado[indiceComparado].nome[posicaoDaLetra] + controleDoComparado and vetorTrabalhado[indiceComparado].nome[posicaoDaLetra] != 0){

        //Troca dos dados nas structs 
        aux = vetorTrabalhado[indiceDoMenor];
        vetorTrabalhado[indiceDoMenor] = vetorTrabalhado[indiceComparado];
        vetorTrabalhado[indiceComparado] = aux;
        
    }

}

//Função que recebe o vetorBandas e ordena em ordem alfabética
void ordenarPorNome(modeloBandas* &vetorTrabalhado,int tamanho){

    //Laço que marca a posição onde a palavra ordenada alfabeticamente(com base na tabeça ASCII) deve estar
    for(int indiceDoMenor = 0;indiceDoMenor < tamanho;indiceDoMenor++){

        //Laço que marca os valores que serão comparados
        for(int indiceComparado = indiceDoMenor+1;indiceComparado < tamanho;indiceComparado++){

            //Chamada da função comparaNome com o indice 0 para o vetor de char "nome"
            comparaNome(vetorTrabalhado,indiceDoMenor,indiceComparado,0);

        }
    }

}

//Função que move e retorna a posição do pivo no vetor trabalhado(base da função quicksort voltada ao ID)
int particionaVetorID(modeloBandas* &vetorTrabalhado,int PosInicial,int PosFinal){

    //inicialização de variaveis internas e necessárias à função
    modeloBandas pivo = vetorTrabalhado[PosInicial];
    modeloBandas aux;
    int i = PosInicial + 1;
    int j = PosFinal;

    //Laço de repetição que roda enquanto os contadores não se encontram e ao se encontrarem roda uma vez(j roda decrescendo e i roda crescendo).
    while(i <= j){

        //Se o pivo for maior que o ID do vetor no indice i,acresce o valor de i em uma unidade,mostrando que o ID está na posição correta.
        if(pivo.id >= vetorTrabalhado[i].id){
            i++;
        }
        //Se o pivo for menor que o ID do vetor no indice j,decresce o valor de j em uma unidade,mostrando que o ID está na posição correta.
        else if(pivo.id <= vetorTrabalhado[j].id or vetorTrabalhado[j].id == 0){
            j--;
        }
        //caso nenhuma das duas condicionais acima inicie,mostra que o total contrário ocorreu e soluciona trocando o lugar dos ID's.
        else{

            aux = vetorTrabalhado[j];
            vetorTrabalhado[j] = vetorTrabalhado[i];
            vetorTrabalhado[i] = aux;

            //move os contadores,mostrando que os ID's estão na posição correta
            i++;
            j--;

        }

    }

    //troca de lugar o pivo(que está na posição inicial com a posição onde ele deveria está)
    vetorTrabalhado[PosInicial] = vetorTrabalhado[j];
    vetorTrabalhado[j] = pivo;

    return j;

}

//Função de ordenação do tipo quicksort voltada para a ordenação por ID
void quicksortID(modeloBandas* &vet,int posPivo,int posFinal){

    //variável que recebe o valor do novo pivo,que vai ser comparado
    int novoPivo;

    //enquanto o pivo não ter o mesmo valor da posição final(mostra que a ordenação acabou)faz uso da recursividade.
    if(posPivo < posFinal){

        //recebe a posição correta do pivo no vetor trabalhado.
        novoPivo = particionaVetorID(vet,posPivo,posFinal);

        //recursividade da função em ambas as partes do vetor
        quicksortID(vet,posPivo,novoPivo - 1);
        quicksortID(vet,novoPivo + 1,posFinal);
    }

}

//Função com o objetivo de simplificar a passagem de parametros
void ordenarPorID(modeloBandas* &vetOrdem,int tamanho){

//chama a função quicksort
quicksortID(vetOrdem,0,tamanho);

}

int particionaVetorIntegrantes(modeloBandas* &vetorTrabalhado,int posInicial,int posFinal){

    //Atribui ao pivo o primeira struct da partição
    modeloBandas pivo = vetorTrabalhado[posInicial];
    modeloBandas aux;

    //Atribui os extremos de onde a partição vai ocorrer
    int i = posInicial+1;
    int j = posFinal;

    //enquanto as duas variáveis não se passarem,o laço roda
    while (i <= j){

        //Se o valor do pivo for menor ou igual ao do vetorTrabalhado e nâo é uma struct vazia,indica que sua posição está correta,então é decrescido à variável j
        if(pivo.numerodeIntegrantes <= vetorTrabalhado[j].numerodeIntegrantes or vetorTrabalhado[j].numerodeIntegrantes == 0){

            j--;
        }
        //Se o valor do pivo for maior ou igual ao do vetorTrabalhado,indica que sua posição está correta,então é acrescido à variável i
        else if(pivo.numerodeIntegrantes >= vetorTrabalhado[i].numerodeIntegrantes){

            i++;
        }
        //Caso não,foi o total contrário que ocorreu,então as variáveis são trocadas
        else{

            aux = vetorTrabalhado[j];
            vetorTrabalhado[j] = vetorTrabalhado[i];
            vetorTrabalhado[i] = aux;

            //Respectivas variáveis são manipuladas
            j--;
            i++;

        }

        

    }

    //troca de lugar a posição inicial com a do local adequado ao pivo
    vetorTrabalhado[posInicial] = vetorTrabalhado[j];
    vetorTrabalhado[j] = pivo;

    //retorna a posição do pivo
    return j;
}

//Função que faz a recursividade antes e depois do novo pivo
void quicksortIntegrantes(modeloBandas* &vetorTrabalhado,int posPivo,int posFinal){

    int novoPivo;

    if(posPivo < posFinal) {

        //Atribui ao novo pivo o retorno da função particionaVetorIntegrantes
        novoPivo = particionaVetorIntegrantes(vetorTrabalhado,posPivo,posFinal);

        //Recursividade da função antes e depois da posição do novo pivo
        quicksortIntegrantes(vetorTrabalhado,posPivo,novoPivo - 1);
        quicksortIntegrantes(vetorTrabalhado,novoPivo + 1,posFinal);

    }


};

//Função que faz a primeira chamada do quicksortIntegrantes com posição do pivo no indice 0
void ordenarPorNumDeIntegrantes(modeloBandas* &vetorTrabalhado,int tamanho){

    quicksortIntegrantes(vetorTrabalhado,0,tamanho);

}

//Função que retorna a posição do pivo, assim como as acima, porém para o Tempo de Show.
int particionaVetorTempoDeShow(modeloBandas* &vetor, int posInicial, int posFinal){
    modeloBandas pivo = vetor[posInicial];
    modeloBandas aux;

    int i = posInicial+1;
    int j = posFinal;

    while (i <= j){
        if(pivo.tempodeShow <= vetor[j].tempodeShow or vetor[j].tempodeShow == 0){
            j--;
        }else if(pivo.tempodeShow >= vetor[i].tempodeShow){ 
            i++;
        }else{
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
            j--;
            i++;
        }
    }

    vetor[posInicial] = vetor[j];
    vetor[j] = pivo;
    return j;
}

//Ordenação quicksort para o Tempo de Show.
void quicksortTempoDeShow(modeloBandas* &vetor, int posPivo, int posFinal){
    int novoPivo;

    if(posPivo < posFinal){
        novoPivo = particionaVetorTempoDeShow(vetor, posPivo, posFinal);
        quicksortTempoDeShow(vetor,posPivo,novoPivo - 1);
        quicksortTempoDeShow(vetor,novoPivo + 1,posFinal);
    }
}

//Chamada mais "clara" do quicksort.
void ordenaPorTempoDeShow(modeloBandas* &vetor, int tamanho){
    quicksortTempoDeShow(vetor, 0, tamanho);
}

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

        newVet[i].numerodeIntegrantes = 0;
        newVet[i].id = 0;
        newVet[i].tempodeShow = 0;
        newVet[i].nome[0] = 0;
       
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
        entrada.getline(reinterpret_cast<char*>(Vetortrabalhado[i].nome),100,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome dentro da struct,convertendo uma string para um vetor de char
        entrada.ignore(1);//Desconsidera a vírgula
        entrada.getline(reinterpret_cast<char*>(Vetortrabalhado[i].genero),100,',');//Lê o genero
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
int ultimoID(modeloBandas *vetorTrabalhado,int tamanho){

   //Define como o maior id o número que está no inicio do vetor.
    int maior = vetorTrabalhado[0].id;

    //Laço de repetição que percorre todos os elementos(ID) do vetor
    for(int i = 0;i < tamanho;i++){

        //Condicional que compara se algum valor maior que o que está na variável maior,e se for verdadeira a comparação,atribui à variável maior.
        if(maior < vetorTrabalhado[i].id){
            maior = vetorTrabalhado[i].id;
        }

    }

    //retorno o maior ID
    return maior;

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
void adicionar(modeloBandas* &vetorTrabalhado,int &tamanho,bool &confirmacao,string nome,string genero,int numerodeIntegrantes,int tempodeShow){

    if(verificaADD(vetorTrabalhado,tamanho,nome)){

    //Verifica se é necessário redimencionar o vetor.
    if(verificaRedimencionar(vetorTrabalhado,tamanho)){

        redimencionar(vetorTrabalhado,tamanho);

    }

    //Atribui ao retorno da função ultimoID acrescido de uma unidade à variável newID
    int newID = ultimoID(vetorTrabalhado,tamanho)+1;
    int indiceADD;

    //variável que garante apenas uma execução do comando dentro da condicional.
    bool primeiraVez = true;

    //percorre o vetorTrabalhado até achar um id que seja igual a zero(ou seja,não há bandas registradas)
    for(int i = 0;i < tamanho;i++){

        //ao achar um id diferente de zero irá atribuir o valor,quando não achar mais valores diferentes de zero,o valor atribuido será do ultimo id que há banda registrada
        if(vetorTrabalhado[i].id == 0 and primeiraVez){

            //adiciona uma unidade para ser o índice que não há bandas adicionadas
            indiceADD = i;

            //inviabiliza todas as outras execuções.
            primeiraVez = false;

        }

    }

    //atribui os atributos da função para o vetorBandas
    vetorTrabalhado[indiceADD].id = indiceADD;
    strcpy(vetorTrabalhado[indiceADD].genero,genero.c_str());
    //uso do strcpy() para copiar o conteudo lido e fazer o casting para um vetor de char;
    strcpy(vetorTrabalhado[indiceADD].nome,nome.c_str());
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

//Função que lê do arquivo binário
void lerDoBinario(modeloBandas* &vetorTrabalhado,int &tamanho){

    //Inicialização de uma variável contadora
    int i = 0;

    //Abertura do arquivo binário
    ifstream entradaBinario("saidaBinario.dat",ios::binary);

    //Laço de repetição com condição de passagem dos valores do binário para o vetorTrabalhado
    while(entradaBinario.read(reinterpret_cast <char*> (&vetorTrabalhado[i]),sizeof(modeloBandas))){

        //Contador
        i++;

        //Redimenciona toda vez que o contador chega ao tamanho total do vetor e o ultimo id é diferente de 0(para evitar contagem de indices não usados dentro do vetor)
        if(i == tamanho and vetorTrabalhado[i-1].id != 0)redimencionar(vetorTrabalhado,tamanho);

    }
    

}   

//Função que deleta e cria um novo arquivo com o novo vetor
void salvarAlteracao(modeloBandas* vet,int tamanho){

    //OBS:Temporariamente o arquivo que irá salvar será o "saida.csv",para em casos de erros nn perder o banco de dados original.
    ofstream saida("saida.csv");
    ofstream saidaBinario("saidaBinario.dat",ios::binary);

    //Representa o molde que o csv irá seguir
    saida << "#ID da Banda,Nome da Banda,Genero Musical,Quantidade de Integrantes,Tempo de Show" << endl;

    //Um laço de repetição que irá gravar todo o vetor(já ajustado) no csv e no arquivo binário.
    for(int i = 0;i < tamanho;i++){

        //compara se é maior que 0,pois exclui campos não gravados e excluídos
        if(vet[i].id > 0){

            //CSV
            saida << vet[i].id  << ',' << '"' << vet[i].nome << '"' << ',' << vet[i].genero << ',' << vet[i].numerodeIntegrantes << ',' << vet[i].tempodeShow << endl;
            
        }
    };

    //Binário
    int i = 0;

    //Verifica se o índice é menor que o tamanho e se o id é zero(se sim,quer dizer que nâo há nada naquele indice do vetorBandas)
    while(i < tamanho and vet[i].id !=0){

        saidaBinario.write(reinterpret_cast<const char*>(&vet[i]),sizeof(modeloBandas));
        i++;

    }

    //Descarrega os Buffer's
    saidaBinario.close();
    saida.close();

}

//Função que faz a interface no terminal dos comandos de adição de usuário
void frontendAdicionar(modeloBandas* &vetorBandas,int &tamanho){

    string nome,genero;
    bool tamanhoCorreto,confirmacao;
    int numeroDeIntegrantes;
    float tempoDeShow;

    //Laço de repetição que roda enquanto o tamanho da variável não for adequada ao tamanho da string no binário.
    do{

        //Escrita no terminal.
        cout << endl << "_______________________________________________________________" << endl << endl;
        cout << "Digite o nome da banda(máximo 100 caracteres).";
        cout << endl << "_______________________________________________________________" << endl << endl;

        //Coleta da variável nome do terminal.
        cin >> nome;

        //Compara se o tamanho da string se adequa ao tamanho de char*100.
        if(sizeof(nome) <= 800){

            //Atribui que o tamanho está adequado.
            tamanhoCorreto = true;

        }else{

            //Atribui que o tamanho está inadequado.
            tamanhoCorreto = false;
        }

    }while(!tamanhoCorreto);

    do{

        //Escrita no terminal.
        cout << endl << "_______________________________________________________________" << endl << endl;
        cout << "Digite o gênero da banda(máximo 20 caracteres).";
        cout << endl << "_______________________________________________________________" << endl << endl;

        //Coleta da variável genero digitada pelo usuário no terminal.
        cin >> genero;

         //Compara se o tamanho da string se adequa ao tamanho de char*20.
        if(sizeof(genero) <= 160){

            //Atribui que o tamanho está adequado.
            tamanhoCorreto = true;

        }else{

            //Atribui que o comando está inadequado.
            tamanhoCorreto = false;
        }

    }while(!tamanhoCorreto);

    //Escrita no terminal.
    cout << endl << "_______________________________________________________________" << endl << endl;
    cout << "Digite a quantidade de integrantes.";
    cout << endl << "_______________________________________________________________" << endl << endl;

    //Coleta da variável numeroDeIntegrantes escrita no teminal pelo usuário.
    cin >> numeroDeIntegrantes;

    //Escrita no terminal.
    cout << endl << "_______________________________________________________________" << endl << endl;
    cout << "Digite o tempo de show.";
    cout << endl << "_______________________________________________________________" << endl << endl;

    //Coleta da variável tempoDeShow escrita no terminal pelo usuário.
    cin >> tempoDeShow;

    //Chama a função de adição
    adicionar(vetorBandas,tamanho,confirmacao,nome,genero,numeroDeIntegrantes,tempoDeShow);

    //Condicional que mostra que a já esxite uma banda com aquele nome e adição não foi realizada(de acordo com o retorno da variável de confirmação).
    if(!confirmacao){

        //Escrita no terminal
        cout << endl << "_______________________________________________________________" << endl << endl;
        cout << "Nome já existente,adição interrompida.";
        cout << endl << "_______________________________________________________________" << endl << endl;

    }

}

//Funçao menu do programa.
void frontendMenu(modeloBandas* &vetorBandas,int &tamanho){

    int digito;
    bool comandoReconhecido;

    //Laço de repetição que roda enquanto nenhum comando de saída do programa for dado.
    do{

        //Interface no terminal
        cout << endl << "_______________________________________________________________" << endl << endl;
        cout << "Para sair sem salvar: 0" << endl << "Para sair e salvar: 1"<< endl << "Para adicionar uma banda: 2" << endl << "Para remover uma banda: 3" << endl << "Para pesquisar: 4" << endl << "Para mostrar as bandas participantes: 5";
        cout << endl << "_______________________________________________________________" << endl << endl;

        //Roda enquanto o comandoReconhecido for falso(não for reconhecido um comando).
        do{

            //Atribuição do digito de interação captado da digitação do usuário no terminal.
            cin >> digito;

            //Caso 1:Comando de saída do programa(sem salvar).
            if(digito == 0){

                //Aponta que o comando foi reconhecido.
                comandoReconhecido = true;

            }
            //Caso 2:Comando de saída do programa(salvando no CSV e binário)
            else if(digito == 1){

                //Chama a função de  salvar as alterações e aponta que o comando foi reconhecido
                salvarAlteracao(vetorBandas,tamanho);
                comandoReconhecido = true;

            }
            //Caso 3:Comando de adicionar um usuário.
            else if(digito == 2){

                //Chama a interface de adição de usuário(função frontendAdicionar) e aponta que o comando foi reconhecido.
                frontendAdicionar(vetorBandas,tamanho);
                comandoReconhecido = true;

            }
            //Caso 0:Aponta que não foi reconhecido nenhum comando de interação.
            else{

                cout << endl << "_______________________________________________________________" << endl << endl;
                cout << "Comando não reconhecido,digite novamente.";
                cout << endl << "_______________________________________________________________" << endl << endl;

                //comandoReconhecido recebe falso,mostrando que nenhum comando foi reconhecido.
                comandoReconhecido = false;

            }

        }while(!comandoReconhecido);

    }while((digito != 0 and digito != 1) or digito == 7);

}

//Função que faz a interface de leitura. 
void frontendLeitura(modeloBandas* &vetorBandas,int &tamanho){

    int digito;
    bool comandoReconhecido;

    //Interface no terminal.
    cout << endl << "_______________________________________________________________" << endl << endl;
    cout << "Para sair: 0" << endl << "Para ler do arquivo Binário: 1 " << endl << "Para ler do arquivo CSV: 2";
    cout << endl << "_______________________________________________________________" << endl << endl;

    //Laço de repetição que roda enquanto algum comando não for reconhecido.
    do{

        //Entrada do digito de interação.
        cin >> digito;

        //Caso 1:quer sair do programa.
        if(digito == 0){

            //Corta o laço de repetição.
            comandoReconhecido = true;

        }

        //Caso 2:Aponta que a leitura do Binário foi feita.
        else if(digito == 1){

            //Escrita no terminal.
            cout << endl << "_______________________________________________________________" << endl << endl;
            cout << "Leitura realizada.";
            cout << endl << "_______________________________________________________________" << endl;

            //Atribui verdadeiro ao comandoReconhecido e chama a função de leitura do arquivo binário.
            comandoReconhecido = true;
            lerDoBinario(vetorBandas,tamanho);

        }

        //Caso 3:Aponta que a leitura do CSV foi feita.
        else if(digito == 2){

            //Escrita no terminal.
            cout << endl << "_______________________________________________________________" << endl << endl;
            cout << "Leitura realizada.";
            cout << endl << "_______________________________________________________________" << endl;
            
            //Atribui verdadeiro ao comandoReconhecido e chama a função de leitura do arquivo CSV.
            leitura(vetorBandas,tamanho);
            comandoReconhecido = true;
        
        }

        //Caso 0:Aponta que não foi reconhecido um comando.
        else{

            //Escrita no terminal.
            cout << endl << "_______________________________________________________________" << endl << endl;
            cout << "Comando não reconhecido,digite novamente.";
            cout << endl << "_______________________________________________________________" << endl << endl;

            //comando reconhecido recebe falso(mostra que não foi reconhecido nenhum comando interativo).
            comandoReconhecido = false;

        }

    }while(!comandoReconhecido);

    //Se a leitura foi feita(Binário ou CSV) chama a função frontendMenu.
    if(digito == 1 or digito == 2){

        frontendMenu(vetorBandas,tamanho);

    }

}