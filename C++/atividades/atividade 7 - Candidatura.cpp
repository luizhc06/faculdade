// canditado para motorista

using namespace std;
#include <iostream>

int main() { 

  int idade;
  bool permissao = 0;
  bool cnh = 0;
  bool acidente = 0;
  bool apto = 0;

  cout << boolalpha;
  
  //perguntas

    cout << "\n----Candidatura para ser motorista-----";
    cout << "\nQual a sua idade? ";
    cout << "\nSua reposta aqui: ";
    cin >> idade;

    cout << "\nVoce tem permissao para dirigir? ";
    cout << "\nDigite [1] para SIM.";
    cout << "\nDigite [0] para NAO."; 
    cout << "\nSua reposta aqui: ";
    cin >> permissao;  

    cout << "\nPossui CNH? ";
    cout << "\nDigite [1] para SIM.";
    cout << "\nDigite [0] para NAO.";
    cout << "\nSua reposta aqui: ";
    cin >> cnh;

    cout << "\nSofreu algum acidente? ";
    cout << "\nDigite [1] para SIM.";
    cout << "\nDigite [0] para NAO.";   
    cout << "\nSua reposta aqui: ";
    cin >> acidente; 

    // Lógica para determinar se o candidato é apto
    if (idade <= 18 && cnh && !acidente) {
      apto = true;

    } else if (idade > 15 && permissao && cnh && !acidente) {
      apto = true;
    } else {
      apto = false;
    }
    
      cout << "\nO candidato esta apto para dirigir? ";
       if (apto) {
          cout << "Voce esta apto para a funcao.";
      } else {
          cout << "Voce nao esta apto para a funcao.";
    }

     cout <<"\nVoce esta em nosso banco de dados, logo entraremos em contato!";
     return 0;

}