#include <iostream>
using namespace std;

 int main() {
  
  int maior = 20;
  int menor = 10;
  int num;

     cout << boolalpha;
     
     cout << "informe um numero fora dos limites entre "<<maior<<" e "<<menor<<" : ";
     cin>>num;

     bool foralimite = (num < menor) || (num>maior);
     cout << "Esta fora do intervalo = " << foralimite;


   return 0;
}