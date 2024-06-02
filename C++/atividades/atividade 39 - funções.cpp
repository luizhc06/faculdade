#include <iostream>
#include <cmath>
using namespace std;

bool ehPrimo(int num) {
    
    if (num <= 1) {
        return false;
    }
    // sqrt = raiz quadrada
    for (int i = 2; i <= sqrt (num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;

    cout << "Digite um numero inteiro positivo: ";
    cin >> num;

    if (num <= 0) {
        cout << "insira um numero inteiro positivo." << endl;
        return 1;
    }

    if (ehPrimo(num)) {
        cout << num << " eh um numero primo." << endl;
    } else {
        cout << num << " nao eh um numero primo." << endl;
    }

    return 0;
}
