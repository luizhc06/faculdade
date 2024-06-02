#include <iostream>
using namespace std;

//tipo_variavel nome_matriz [constante numero de elementos] {inicio da lista}

int main() {

int pontos [5] {100, 95, 99, 87, 88};

  int pontos_nivel [10] {3,5}; // inicia dois valores, restante 0.
  const int dias_ano {365}; // valores de posição do indice.
  double maior_temperatura [dias_ano] {0}; // inicia todos em 0.

  int outra_matriz [] {1, 2, 3, 4, 5}; // tam. cal. automaticamente.
  cout << "primeira pontuacao endereco 0: " << pontos [0];
  cout << "segunda pontuacao endereco 1: " << pontos [1];
  cout << "terceira pontuacao endereco 2: " << pontos [2];
  cout << "quarta pontuacao endereco 3: " << pontos [3];
  cout << "quinta pontuacao endereco 4: " << pontos [4];

  return 0;
}

