#include <iostream>
using namespace std;

int main() {
    int vetor[10];
    int count = 0;

    for (int i = 0; i < 10; i++) {
        cin >> vetor[i];
    }

    for (int i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            count++;
        }
    }

    cout << "Quantidade de valores pares: " << count << endl;

    return 0;
}
