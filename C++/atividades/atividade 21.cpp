#include <iostream>
#include <string>
using namespace std;

// Função para verificar credenciais
bool verificarCredenciais(const string& gmail, const string& senha, const string registros[][3], int numRegistros) {
    for (int i = 0; i < numRegistros; ++i) {
        if (registros[i][1] == gmail && registros[i][2] == senha) {
            return true; // Credenciais válidas
        }
    }
    return false; // Credenciais inválidas
}

int main() {
    const int NUM_REGISTROS = 2;
    string registros[NUM_REGISTROS][3] = {
        {"Joao", "joao@gmail.com", "senha123"},
        {"Maria", "maria@gmail.com", "senha456"}
    };

    string gmail, senha;
    bool loginValido = false;

    while (!loginValido) {
        cout << "Digite o seu Gmail: ";
        getline(cin, gmail);

        cout << "Digite sua senha: ";
        getline(cin, senha);

        loginValido = verificarCredenciais(gmail, senha, registros, NUM_REGISTROS);

        if (loginValido) {
            cout << "Login bem-sucedido!\n";
            for (int i = 0; i < NUM_REGISTROS; ++i) {
                if (registros[i][1] == gmail) {
                    cout << "Bem-vindo, " << registros[i][0] << "!\n";
                    break;
                }
            }
        }
        else {
         cout << "Credenciais inválidas. Tente novamente.\n";
        }
    }

    return 0;
}
