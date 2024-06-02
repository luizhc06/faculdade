#include <iostream>

using namespace std;

int main() {
    int numIdades;
    cout << "Quantas idades você quer fornecer? ";
    cin >> numIdades;

    if (numIdades <= 0) {
        cout << "Numero invalido de idades.\n";
        return 1; 
    }

    int somaIdades = 0;
    int idade;

    for (int i = 0; i < numIdades; ++i) {
        cout << "Digite a idade " << (i + 1) << ": ";
        cin >> idade;
        somaIdades += idade;
    }

    double mediaIdades = static_cast<double>(somaIdades) / numIdades;

    cout << "A média das idades fornecidas é: " << mediaIdades << endl;

    return 0; // Saída sem erros
}

