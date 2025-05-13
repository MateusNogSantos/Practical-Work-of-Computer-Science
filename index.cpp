#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){

    //int lixoint;
    string lixostr;
    ifstream entrada("lollapalufla.csv");
    getline(entrada, lixostr);
    cout<< lixostr;
    
    return 0;
}
