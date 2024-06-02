//ex 3: INDICES DE VETOR
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int vetor[20];
  int maior, menor, posicaoMaior, posicaoMenor;

  cout << "Informe 20 valores inteiros: ";
  for (int i = 0; i < 20; i++) {
    cin >> vetor[i];
  }

  maior = vetor[0];
  menor = vetor[0];
  posicaoMaior = 0;
  posicaoMenor = 0;

  cout << "Valores pares: ";
  for (int i = 0; i < 20; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
      posicaoMaior = i;
    }
    if (vetor[i] < menor) {
      menor = vetor[i];
      posicaoMenor = i;
    }
    if (vetor[i] % 2 == 0) {
      cout << vetor[i] << " ";
    }
  }

  cout << "\nValores ímpares: ";
  for (int i = 0; i < 20; i++) {
    if (vetor[i] % 2 != 0) {
      cout << vetor[i] << " ";
    }
  }

  cout << "\n\nO maior valor é: " << maior << " (na posição: " << posicaoMaior + 1 << ")\n" << endl;
  cout << "O menor valor é: " << menor << " (na posição: " << posicaoMenor + 1 << ")\n" << endl;

  return 0;
}