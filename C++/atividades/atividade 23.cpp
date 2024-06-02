#include <iostream>
using namespace std;

int main() {
    char continuar;

    do {
    
        double nota1, nota2, nota3, nota4;
        const double peso1 = 1, peso2 = 3, peso3 = 4, peso4 = 5;

        cout << "Digite a primeira nota: ";
        cin >> nota1;
        cout << "Digite a segunda nota: ";
        cin >> nota2;
        cout << "Digite a terceira nota: ";
        cin >> nota3;
        cout << "Digite a quarta nota: ";
        cin >> nota4;

        double media = (nota1 * peso1 + nota2 * peso2 + nota3 * peso3 + nota4 * peso4) / (peso1 + peso2 + peso3 + peso4);

        cout << "Media anual: " << media << endl;
        if (media >= 7.0) {
            cout << "Situacao: Aprovado" << endl;
        } 
        else if (media >= 4.0 && media < 7.0) {
            cout << "Situacao: Em recuperação" << endl;
        }
        else {
            cout << "Situacao: Reprovado" << endl;
        }

        cout << "Deseja calcular uma nova media? (S/N): ";
        cin >> continuar;

    } 
    
    while (continuar == 'S' || continuar == 's');

    cout << "FIM DO PROGRAMA" << endl;

    return 0;
}
