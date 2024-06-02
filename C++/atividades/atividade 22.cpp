#include <iostream>
using namespace std;

int main() {
    int escolha;
    int verificavoto;
    bool votoValido = false;

    cout << "Bem-vindo à Urna Eletrônica!" << endl;
    cout << "Escolha um candidato:" << endl;
    cout << "1 - Antonio" << endl;
    cout << "2 - Simao" << endl;
    cout << "3 - Voto nulo" << endl;
    cin >> escolha;

    switch (escolha) {
        case 1:
        case 2:
        case 3:
            cout << "Digite o número do seu candidato para verificação: ";
            cin >> verificavoto;

            if (verificavoto == escolha) {
                votoValido = true;
                cout << "Obrigado por votar! Tenha um ótimo dia!" << endl;
            } else {
                cout << "Voto inválido. Tente novamente." << endl;
            }
            break;

        default:
            cout << "Opção inválida. Escolha um candidato válido (1, 2 ou 3)." << endl;
            break;
    }

    if (votoValido) {
        switch (escolha) {
            case 1:
                cout << "Você votou em Antonio." << endl;
                break;
            case 2:
                cout << "Você votou em Simao." << endl;
                break;
            case 3:
                cout << "Seu voto foi nulo." << endl;
                break;
        }
    }

    cout << "F I M!" << endl;

    return 0;
}
