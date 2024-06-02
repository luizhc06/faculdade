#include <iostream>
using namespace std;

int main() {
    bool vestircasaco = false;
    double temperatura;
    double velocidade;

    cout << boolalpha;
    const int velocidadecasaco = 40;
    const double temperaturacasaco = 15;

    cout << "Informe a temperatura em Celsius: ";
    cin >> temperatura;
    cout << "\nQual a velocidade do vento? (em KM/H) ";
    cin >> velocidade;

    // Verifica se deve vestir o casaco
    vestircasaco = (temperatura < temperaturacasaco || velocidade > velocidadecasaco);

    // Imprime a decisão
    if (vestircasaco) {
        cout << "\nVocê precisa levar o seu casaco!\n";
    } else {
        cout << "\nVocê não precisa levar o seu casaco!\n";
    }

    return 0;
}
