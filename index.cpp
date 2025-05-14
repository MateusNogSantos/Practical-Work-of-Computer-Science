#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){

    int id;
    string lixostr,nome;
    ifstream entrada("lollapalufla.csv");

    getline(entrada,lixostr);

    entrada >> id;
    entrada.ignore(2);
    getline(entrada,nome,'"');
    cout << nome;
    
    return 0;
}
