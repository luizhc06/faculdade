#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 15; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }
    cout << "A soma dos inteiros impares de 1 a 15 e: " << sum << endl;
    return 0;
}