    #include <iostream>
    using namespace std;

    int main() {
        double preco;

        cout << "Digite o preco do produto: ";
        cin >> preco;

        if (preco < 100) {
            preco *= 1.1; // aumento de 10%
        } else {
            preco *= 1.2; // aumento de 20%
        }

        cout << "Preco final: R$ " << preco << endl;

        return 0;
    }
