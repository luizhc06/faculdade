#include <iostream>
using namespace std;

int main() {
    int num = 0;

    while(num <= 10 || num >= 20) {
        cout << "Digite um numero inteiro entre 10 e 20: ";
        cin >> num;
    }

    bool fim = true;
    while(fim) {
        cout << "Insira um valor entre 1 e 5: ";
        cin >> num;
        if (num <= 1 || num >= 5)
            cout << "Fora do alcance, tente novamente" << endl;
        else {
            fim = false;
            cout << "Numero valido" << endl;
        }
    }

    cout << "Digite um numero para contar regressivamente: ";
    cin >> num;
    while (num > 0) {
        cout << num << endl;
        --num;
    }
    cout << "Fim da contagem." << endl;

    int ra_correto = 123;
    int RA;
    bool verificacao = false;
    do {
        cout << "Digite o seu RA para realizar o login: ";
        cin >> RA;
        if (RA == ra_correto) {
            verificacao = true;
            cout << "Login realizado com sucesso." << endl;
        } else {
            cout << "RA incorreto. Tente novamente." << endl;
        }
    } while (!verificacao);

    char selecao = 's';
    do {
        double altura, comprimento;
        cout << "Digite a altura e a largura separados por espaco: ";
        cin >> altura >> comprimento;
        double area = altura * comprimento;
        cout << "A area e: " << area << endl;
        cout << "Deseja continuar? (s/n): ";
        cin >> selecao;
    } while (selecao == 's');

    return 0;
}