#include <iostream>
using namespace std;

int main() {
    const int linhas = 3;
    const int colunas = 3;
    int matriz[linhas][colunas];

    cout << "Digite os valores para preencher a matriz " << linhas << "x" << colunas << ":" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz " << linhas << "x" << colunas << " criada:" << endl;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    int pares = 0;
    int impares = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
        }
    }

    cout << "\nQuantidade de numeros pares na matriz: " << pares << endl;
    cout << "Quantidade de numeros impares na matriz: " << impares << endl;

    return 0;
}
