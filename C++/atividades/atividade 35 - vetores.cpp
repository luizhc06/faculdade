//ex 4: MANIPULAÇÃO DE NUMEROS DE UMA MATRIZ

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int vetor[10];
  int valorReferencia;
  int maiores = 0;
  int menores = 0;
  int ocorrencias = 0;

  cout << "Digite 10 números inteiros: ";
  for (int i = 0; i < 10; i++) {
    cin >> vetor[i];
  }

  cout << "Digite o valor de referência: ";
  cin >> valorReferencia;

  for (int i = 0; i < 10; i++) {
    if (vetor[i] > valorReferencia) {
      maiores++;
      cout << "Número maior que a referência: " << vetor[i] << endl;
    } else if (vetor[i] < valorReferencia) {
      menores++;
    } else if (vetor[i] == valorReferencia) {
      ocorrencias++;
    }
  }

  cout << "Números maiores que a referência: " << maiores << endl;
  cout << "Números menores que a referência: " << menores << endl;
  cout << "O valor de referência aparece " << ocorrencias << " vez(es) no vetor." << endl;

  return 0;
}