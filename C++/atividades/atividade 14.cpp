#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    char letra_grande;

    cout << "Informe a letra do conceito que você espera obter no exame: ";
    cin >> letra_grande;

    switch (letra_grande) {
        case 'A':
        case 'a':
            cout << "Você irá obter acima de 90, estude bastante. ";
            break;
        case 'B':
        case 'b':
            cout << "Você irá obter acima de 80-90, estude bastante. ";
            break;
        case 'C':
        case 'c':
            cout << "Você irá obter acima de 70-80, estude bastante. ";
            break;
        case 'D':
        case 'd':
            cout << "Você irá obter acima de 60-70, estude bastante. ";
            break;
        case 'E':
        case 'e':
            cout << "Você irá obter acima de 50-60, você não será aprovado. ";
            break;
        case 'F':
        case 'f':
            cout << "Você irá obter acima de 30-40, você não será aprovado. ";
            break;
        default:
            cout << "Opção Inválida.";
    }

    char confirma;
    cout << "\nVocê tem certeza? (S/N): ";
    cin >> confirma;

    if (confirma == 'S' || confirma == 's') {
        cout << "OK, você precisa estudar." << endl;
    } else if (confirma == 'N' || confirma == 'n') {
        cout << "OK, quando você tiver certeza do que quer, volte aqui." << endl;
    } else {
        cout << "Escolha Incorreta";
    }

    return 0;
}
