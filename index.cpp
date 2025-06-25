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

    frontendMenuPrincipal(vetorBandas, tamanho);

    return 0;
}