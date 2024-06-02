#include <iostream>
using namespace std;

int main() {
    char op; // operação 
    int num1, num2, resultado;
    
    cout << "Escolha a operacao que voce deseja realizar:" << endl;
    cout << "[1] - Soma" << endl;
    cout << "[2] - Subtracao" << endl;
    cout << "[3] - Multiplicacao" << endl;
    cout << "[4] - Divisao" << endl;
    cout << "Opcao: ";
    cin >> op;
    
    cout << "Digite dois numeros: ";
    cin >> num1 >> num2;
    
    switch(op) {
        case '1':
            resultado = num1 + num2;
            cout << "Resultado da soma: " << resultado << endl;
            break;
        case '2':
            resultado = num1 - num2;
            cout << "Resultado da subtracao: " << resultado << endl;
            break;
        case '3':
            resultado = num1 * num2;
            cout << "Resultado da multiplicacao: " << resultado << endl;
            break;
        case '4':
            if(num2 != 0) {
                resultado = num1 / num2;
                cout << "Resultado da divisao: " << resultado << endl;
            } else {
                cout << "Erro: Divisao por zero!" << endl;
            }
            break;
        default:
            cout << "Opcao invalida! Por favor, escolha uma operacao valida." << endl;
    }
    
    return 0;
}
