#include <iostream>

using namespace std;

int main() {
    int numero;

    while (true) {
        cout << "Digite um numero: ";
        cin >> numero;

        if (numero >= 23 && numero <= 47) {
            cout << "O numero " << numero << " esta dentro do intervalo entre 23 e 47." << endl;
        } else {
            cout << "O numero " << numero << " esta fora do intervalo entre 23 e 47. Saindo do loop." << endl;
            break;
        }
    }

    cout << "Fim do programa." << endl;
    return 0;
}
