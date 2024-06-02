#include <iostream>
using namespace std;

int calcularQuociente(int num1, int num2) {

    if (num1 <= 0 || num2 <= 0) {
        cout << "Os numeros devem ser inteiros positivos" << endl;
        return -1;
    }

    int quociente = 0;

    while (num1 >= num2) {
        num1 -= num2;
        quociente++;
    }

    return quociente;
}

int main() {
    int num1, num2;

    cout << "Digite dois numeros inteiros positivos: ";
    cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        cout << "Digite apenas numeros inteiros positivos" << endl;
        return 1;
    }

    int quociente = calcularQuociente(num1, num2);
    if (quociente != -1) {
        cout << "O quociente da divisao inteira de " << num1 << " por " << num2 << " eh: " << quociente << endl;
    }

    return 0;
}
