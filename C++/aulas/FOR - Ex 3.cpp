#include <iostream>

using namespace std;

int main() {
    cout << "Tabuada " << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= 10; j++) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    return 0;
}