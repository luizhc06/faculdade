#include <iostream>
#include <string>

using namespace std;

void loginCliente() {
    cout << "===== Interface de Login para Cliente =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "LoginCliente1" && password == "102024") {
            cout << "Login bem-sucedido para Cliente!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Cliente. Por favor, tente novamente mais tarde." << endl;
}


void loginEmpresa() {
    cout << "===== Interface de Login para Empresa =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "StartupFilaexpress" && password == "062024") {
            cout << "Login bem-sucedido para Empresa!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Empresa. Por favor, tente novamente mais tarde." << endl;
}


void loginOwner() {
    cout << "===== Interface de Login para Owner =====" << endl;
    string username, password;
    int tentativas = 0;
    do {
        cout << "Usuario: ";
        cin >> username;
        cout << "Senha: ";
        cin >> password;
        if (username == "OwnerFfe" && password == "FE2024") {
            cout << "Login bem-sucedido para Owner!" << endl;
            return;
        } else {
            cout << "Usuario ou senha incorretos. Tente novamente." << endl;
            tentativas++;
        }
    } while (tentativas < 3);
    cout << "Limite de tentativas excedido para Owner. Por favor, tente novamente mais tarde." << endl;
}

int main() {
    int escolha;

    do {
        cout << "\nSelecione o tipo de usuario:\n";
        cout << "[1] Cliente\n";
        cout << "[2] Empresa\n";
        cout << "[3] Owner\n";
        cout << "[0] Sair\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                loginCliente();
                break;
            case 2:
                loginEmpresa();
                break;
            case 3:
                loginOwner();
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (escolha != 0);

    return 0;
}