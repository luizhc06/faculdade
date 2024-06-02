#include <iostream>
using namespace std;

int main() {

    double a = 100;
    int b = 12;
    int x = b % 3;
    double y = a / b;
    int z = static_cast<int>(a / b); // Conversão explícita para int

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    return 0;
}
