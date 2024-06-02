#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> notas(15);
    float soma = 0;

    for (int i = 0; i < 15; i++) {
        cout << "Digite a nota do aluno " << i + 1 << ": ";
        cin >> notas[i];
        soma += notas[i];
    }

    float media = soma / 15;
    cout << "Media geral: " << media << std::endl;

    return 0;
}