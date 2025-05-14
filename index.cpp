#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int id;
    string lixoStr,nome;
    ifstream entrada("lollapalufla.csv");

    getline(entrada,lixoStr); //Passa a primeira Linha do CSV para lixoStr

    entrada >> id; //Lê do CSV o valor #ID da Banda para a variável id
    entrada.ignore(2); //Desconsidera a primeira , e a primeira "
    getline(entrada,nome,'"'); //Lê do CSV o valor do Nome da Banda para a variável nome 
    cout << nome; //Printa o valor de nome na tela
    
    return 0;
}
