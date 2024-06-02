#include <iostream>
using namespace std;

int main() {
    int escolha;

    cout << "------- Vamos Calcular! -------" << endl;

    while (true) {
        cout << "Por favor, selecione uma das opcoes:" << endl;
        cout << "1 - Soma" << endl;
        cout << "2 - Subtracao" << endl;
        cout << "3 - Multiplicacao" << endl;
        cout << "4 - Divisao" << endl;
        cout << "5 - Sair" << endl;
        cout << "Qual sua escolha? ";
        cin >> escolha;

        if (escolha == 5) {
            cout << "Obrigado por usar a calculadora. Ate logo!" << endl;
            break;
        }

        cout << "Escreva o primeiro numero:";
        int number1;
        cin >> number1;
        cout << "Escreva o segundo numero:";
        int number2;
        cin >> number2;

        switch (escolha) {
            case 1: 
                cout << "resultado da soma: " << number1 + number2 << endl;
                break;
            
            case 2: 
                cout << "resultado da subtracao = " << number1 - number2 << endl;
                break;
            
            case 3: 
                cout << "resultado da multiplicacao = " << number1 * number2 << endl;
                break;
            
            case 4: 
                if (number2 != 0) {
                    cout << "resultado da divisao = " << static_cast<double>(number1) / number2 << endl;
                } else {
                    cout << "Divisao por zero nao e permitida. Escolha novamente" << endl;
                }
                break;

            default:
                cout << "Opcao invalida. Escolha novamente" << endl;
                break;
        }
    }
    return 0;
}
