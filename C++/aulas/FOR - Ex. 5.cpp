#include <iostream>
using namespace std;

int main() {

     int numeros[10], pares = 0, impares = 0;
 
     for (int i = 0; i < 10; i++) {
         cout << "Digite o " << i+1 << "° numero: ";
         cin >> numeros[i];
 
         if (numeros[i] % 2 == 0) {
             pares++;
         } else {
             impares++;
         }
     }
 
     cout << "Quantidade de numeros pares: " << pares << endl;
     cout << "Quantidade de numeros impares: " << impares << endl;
 
     return 0;
 }
