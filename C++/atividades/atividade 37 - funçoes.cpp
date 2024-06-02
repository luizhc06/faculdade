#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double circulo, quadrado, retangulo, triangulo;
    int opcao;
    int pi = 3.14;

    cout << "Qual figura geometrica voce deseja calcular? " << endl;
    cout << "1 - Circulo" << endl;
    cout << "2 - Quadrado" << endl;
    cout << "3 - Retangulo" << endl;
    cout << "4 - Triangulo" << endl;
    cin >> opcao;

    switch (opcao) {
        // POW = Calcula o valor de um numero elevado a uma potencia 

        case 1:
            cout << "Digite o raio do circulo: ";
            cin >> circulo;
            cout << "Area do circulo: " << pi * pow(circulo, 2) << endl;
            break;

        case 2:
            cout << "Digite o lado do quadrado: ";
            cin >> quadrado;
            cout << "Area do quadrado: " << pow(quadrado, 2) << endl;
            break;

        case 3:
            cout << "Digite a base e a altura do retangulo: ";
            cin >> retangulo >> quadrado;
            cout << "Area do retangulo: " << retangulo * quadrado << endl;
            break;
            
        case 4:
            cout << "Digite a base e a altura do triangulo: ";
            cin >> retangulo >> quadrado;
            cout << "Area do triangulo: " << (retangulo * quadrado) / 2 << endl;
            break;

        default:
            cout << "Opcao invalida" << endl;
            break;

    }

    return 0;
}