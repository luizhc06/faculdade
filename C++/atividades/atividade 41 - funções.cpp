#include <iostream>
using namespace std;

int inverterNumero(int num) {
    int inverso = 0;
    
    while (num > 0) {
        int digito = num % 10;   // consegue o ultimo numero
        inverso = inverso * 10 + digito;  // controi o numero invertido
        num /= 10;  // remove o ultimo digito do numero anterior 
    }
    
    return inverso;
}

int main() {
    int num;

    cout << "Digite um numero inteiro positivo: ";
    cin >> num;

    if (num <= 0) {
        cout << "Digite um numero inteiro positivo" << endl;
        return 1;
    }

    int inverso = inverterNumero(num);
    cout << "O inverso de " << num << " eh: " << inverso << endl;

    return 0;
}