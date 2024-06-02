// ex 2: positivos, negativos e zero
#include <iostream>

using namespace std;

int main() {
  int numero, positivos = 0, negativos = 0, zeros = 0;

  cout << "Digite 10 números: " << endl;

  for (int i = 0; i < 10; i++) {
    cin >> numero;

    if (numero > 0) {
      positivos++;
    } else if (numero < 0) {
      negativos++;
    } else {
      zeros++;
    }
  }

  cout << "Números positivos: " << positivos << endl;
  cout << "Números negativos: " << negativos << endl;
  cout << "Números zeros: " << zeros << endl;

  return 0;
}