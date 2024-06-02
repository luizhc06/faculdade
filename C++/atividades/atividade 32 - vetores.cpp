// ex 1: maior e menor numero de um vetor
#include <iostream>
#include <vector>

using namespace std;

int main () {
  int vetor[20];
  int maior, menor, posicaoMaior, posicaoMenor;

     cout <<"informe 20 valores inteiros:";
     for (int i = 0; i < 20; i++) {
     cin >> vetor[i];
     }

     maior = vetor[0];
     menor = vetor[0];
     posicaoMaior = 0;
     posicaoMenor = 0;

     for (int i = 0; i < 20; i++) {
         if (vetor[i] > maior) {
         maior = vetor[i];
         posicaoMaior = i;
     }
     if (vetor[i] < menor) {
         menor = vetor[i];
         posicaoMenor = i;
     }
     }
    
     cout << "O maior valor e: " << maior << " (na posicao: " << posicaoMaior + 1 << ")\n" << endl;
     cout << "O menor valor e: " << menor << " (na posicao: " << posicaoMenor + 1 << ")\n" << endl; 

 return 0;

}
