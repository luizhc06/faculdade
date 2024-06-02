#include <iostream>
using namespace std;

int main() {
    int numero;
    int maior;

    cout << "Digite o 1 numero: ";
    cin >> maior;

    for (int i = 2; i <= 10; i++) {
        cout << "Digite o " << i << " numero: ";
        cin >> numero;

        if (numero > maior) {
            maior = numero;
        }
    }

    cout << "O maior numero digitado e: " << maior << endl;

    return 0;
}
