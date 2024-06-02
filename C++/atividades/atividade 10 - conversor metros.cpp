#include <iostream>
using namespace std;

int main() {

    double metros;
    int escolhas;

    // Introdução
    cout << "\n---- Boas vindas ao conversor de metros! ----";
    cout << "\nDigite o valor em metros: ";
    cin >> metros;
    cout << "\nEscolha uma das seguintes opções:";
    cout << "\n [0] para CANCELAR.";
    cout << "\n [1] para decimetros.";
    cout << "\n [2] para centimetros.";
    cout << "\n [3] para milimetros.";
    cout << "\nSua resposta aqui: ";
    cin >> escolhas;

    // calculos
    double decimetros = metros * 10;
    double centimetros = metros * 100;
    double milimetros = metros * 1000;

    // opçoes de escolha 
    switch (escolhas) {
        case 0: 
            cout << "Tudo bem, vejo voce mais tarde!";
            break;

        case 1:
            cout << "Valor em decimetros: " << decimetros << endl;
            break;

        case 2:
            cout << "Valor em centimetros: " << centimetros << endl;
            break;

        case 3:
            cout << "Valor em milimetros: " << milimetros << endl; 
            break;

        default:
            cout << "Opção inválida!" << endl;
            break;
    }

    return 0;
}
