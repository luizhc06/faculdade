#include <iostream>
using namespace std;

int main() {
    double reais;
    int escolhas;

    //valor das moedas em reais
    const double taxa_dolar = 4.98; 
    const double taxa_euro = 5.39;
    const double taxa_iene = 0.033;
    const double taxa_peso = 0.0058; //(argentina)

    //opções de escolhas para moedas
    cout << "\n----- Boas Vindas ao conversor de reais! -----";
    cout << "\nEscolha a moeda para qual voce deseja converter";
    cout << "\n [0] para CANCELAR.";  
    cout << "\n [1] para DOLAR.";
    cout << "\n [2] para EURO.";
    cout << "\n [3] para IENE JAPONES."; 
    cout << "\n [4] para PESO ARGENTINO."; 
    cout << "\nO que voce deseja? ";
    cin >> escolhas;

    switch (escolhas) { 
        case 0: 
            cout << "Tudo bem, vejo voce mais tarde!";
            break;
        case 1:
            cout << "Digite a quantidade em Reais: ";
            cin >> reais;
            cout << "Valor em Dolares: " << reais / taxa_dolar << endl;
            cout << "\nObrigado por usar meu conversor!";
            break;
        case 2:
            cout << "Digite a quantidade em Reais: ";
            cin >> reais;
            cout << "Valor em Euros: " << reais / taxa_euro << endl;
            cout << "\nObrigado por usar meu conversor!";
            break;
        case 3:
            cout << "Digite a quantidade em Reais: ";
            cin >> reais;
            cout << "Valor em Ienes: " << reais / taxa_iene << endl;
            cout << "\nObrigado por usar meu conversor!";
            break;
        case 4: 
            cout << "Digite a quantidade em Reais: ";
            cin >> reais;
            cout << "Valor em Pesos argentinos: " << reais / taxa_peso << endl;
            cout << "\nObrigado por usar meu conversor!";
            break;
        default:
            cout << "Opcao invalida!";
            break;
    }

    return 0;
}
