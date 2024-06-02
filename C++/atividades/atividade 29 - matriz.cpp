#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    string cpf;
};

int main() {

    Pessoa pessoas[5];

    for (int i = 0; i < 5; i++) {
        cout << "Digite os dados da pessoa " << i + 1 << ":" << endl;
        cout << "Nome: ";
        getline(cin >> ws, pessoas[i].nome);
        cout << "CPF: ";
        getline(cin >> ws, pessoas[i].cpf); 
    }


    cout << "\nDados das pessoas inseridas:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nome: " << pessoas[i].nome << ", CPF: " << pessoas[i].cpf << endl;
    }

    return 0;
}
