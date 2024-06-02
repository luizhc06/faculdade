//ex 5: SOMA DE VETOR
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vetor; // Vetor para armazenar os valores
  int valor;
  char continuar;

  // Leitura dos valores até o usuário não querer mais inserir
  do {
    cout << "Digite um valor inteiro (ou 'n' para sair): ";
    cin >> valor;

    // Verifica se o usuário digitou 'n' para sair
    if (cin.fail() || tolower(valor) == 'n') {
      break; // Sai do loop
    }

    // Adiciona o valor ao vetor
    vetor.push_back(valor); 

    // Pergunta se o usuário quer continuar inserindo
    cout << "Deseja inserir outro valor? (s/n): ";
    cin >> continuar;
    cin.ignore(); // Limpa o buffer do teclado
  } while (tolower(continuar) == 's');

  // Mostra a quantidade de itens inseridos
  cout << "\nQuantidade de itens inseridos no vetor: " << vetor.size() << endl;

  return 0;
}