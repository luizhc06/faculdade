#include <iostream>
using namespace std;

int main() {

    int centavos, reais;

    cout << "\n------ Boas vindas ao caixa eletronico! ------";
    cout << "\nDigite a quantidade de reais em notas: ";
    cin >> reais;

    cout << "\nDigite a quantidade de centavos: ";
    cin >> centavos;

    // Notas

    int notas200 = reais / 200;
    reais %= 200;

    int notas100 = reais / 100;
    reais %= 100;

    int notas50 = reais / 50;
    reais %= 50;

    int notas20 = reais / 20;
    reais %= 20;

    int notas10 = reais / 10;
    reais %= 10;

    int notas5 = reais / 5;
    reais %= 5;

    int notas2 = reais / 2;
    reais %= 2;
    
    // Resultado das notas
    cout << "Notas de 200: " << notas200 << endl;
    cout << "Notas de 100: " << notas100 << endl;
    cout << "Notas de 50: " << notas50 << endl;
    cout << "Notas de 20: " << notas20 << endl;
    cout << "Notas de 10: " << notas10 << endl;
    cout << "Notas de 5: " << notas5 << endl;
    cout << "Notas de 2: " << notas2 << endl;

    // Moedas
    int moedas1 = centavos / 100;
    centavos %= 100;

    int moedas50 = centavos / 50;
    centavos %= 50;

    int moedas25 = centavos / 25;
    centavos %= 25;

    int moedas10 = centavos / 10;
    centavos %= 10;

    int moedas5 = centavos / 5;
    centavos %= 5;

    int moedas1c = centavos;

    // Resultado das moedas
    cout << "Moedas de 1 real: " << moedas1 << endl;
    cout << "Moedas de 50 centavos: " << moedas50 << endl;
    cout << "Moedas de 25 centavos: " << moedas25 << endl;
    cout << "Moedas de 10 centavos: " << moedas10 << endl;
    cout << "Moedas de 5 centavos: " << moedas5 << endl;
    cout << "Moedas de 1 centavo: " << moedas1c << endl;

    return 0;
}

