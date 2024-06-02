#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    char repeat;

    do {
        
        cout << "Digite o tamanho da matriz no formato MxN (por exemplo, 3x4): ";
        char x; 
        cin >> M >> x >> N;

        vector<vector<int>> matriz(M, vector<int>(N));

        cout << "Digite os valores da matriz:" << endl;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matriz[i][j];
            }
        }

        int maior = matriz[0][0];
        int menor = matriz[0][0];
        int soma = 0;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int valor = matriz[i][j];
                if (valor > maior) maior = valor;
                if (valor < menor) menor = valor;
                soma += valor;
            }
        }

        cout << "Maior valor: " << maior << endl;
        cout << "Menor valor: " << menor << endl;
        cout << "Soma dos valores: " << soma << endl;

        cout << "Deseja repetir a operação? (s/n): ";
        cin >> repeat;

    } while (repeat == 's' || repeat == 'S');

    return 0;
}
