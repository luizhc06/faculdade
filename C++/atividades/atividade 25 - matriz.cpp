#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numNomes = 5;
    string nomes[numNomes]; 

    cout << "Digite os nomes de 5 pessoas:" << endl;
    for (int i = 0; i < numNomes; i++) {
        cout << "Nome " << i + 1 << ": ";
        cin >> nomes[i];
    }

    cout << "\nNomes digitados:" << endl;
    for (int i = 0; i < numNomes; i++) {
        cout << nomes[i] << endl;
    }

    return 0;
}
