#include <iostream>
using namespace std;

int calcularResto(int num1, int num2) {
    int maior = (num1 > num2) ? num1 : num2;
    int menor = (num1 > num2) ? num2 : num1;
    
    while (maior >= menor) {
        maior -= menor;
    }
    
    return maior;
}

int main() {
    int num1, num2;

    cout << "Digite dois numeros inteiros positivos: ";
    cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Digite apenas numeros inteiros positivos." << endl;
        return 1;
    }

    int resto = calcularResto(num1, num2);
    cout << "O resto da divisao inteira do maior pelo menor eh: " << resto << endl;

    return 0;
}
