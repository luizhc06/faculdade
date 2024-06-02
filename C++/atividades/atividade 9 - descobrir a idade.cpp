#include <iostream>
using namespace std;

int main () {

    int nascimento , ano_atual;

    cout << "-----\nVamos descobrir sua idade?-----";

    cout << "\nDigite a sua data de nascimento: ";
    cin >> nascimento;

    cout << "\nDigite o ano atual: ";
    cin >> ano_atual;

    int idade = ano_atual - nascimento;

    cout << "Voce tem: " << idade << " anos!" << endl;

    return 0;
}