#include <vector>
#include <iostream>

using namespace std;

int main() {

    vector<char> vogais {'a', 'e', 'i', 'o', 'u'};

    cout << vogais[0] << endl;

    vector<int> pontuacao {100, 98, 99};
    cout << pontuacao[0] << endl;
    cout << pontuacao[1] << endl;
    cout << pontuacao[2] << endl;
    cout << pontuacao.size() << endl;
    cout << pontuacao.capacity() << endl;

    cout << "pontuacao utilizando sintax vetorial" << endl;
    cout << pontuacao.at(0) << endl;
    cout << pontuacao.at(1) << endl;
    cout << pontuacao.at(2) << endl;
    cout << "Existem " << pontuacao.size() << " elementos" << endl;

    cout<<"Digite uma nova pontuacao para adicionar dentro do vetor"<<endl;
    int pontuacao_add;
    cin>>pontuacao_add;

    pontuacao.push_back(pontuacao_add);

    cout<<"Existem "<<pontuacao.size()<<" pontuacoes no vetor"<<endl;

    //criaçao de um vetor com tamanho defeinido pelo usuario for

    cout<<"==========================="<<endl;
    vector<int>numeros;
    int tamanho;

    cout<<"Digite o tamanho do vetor"<<endl;
    cin>>tamanho;

    cout<<"Digite os elementos do vetor: "<<endl;
    for (int i = 0; i < tamanho; i++)
    {
        int elemento;
        cin>>elemento;
        numeros.push_back(elemento);
    }

    for (int i = 0; i < tamanho; i++) {
        cout<<numeros[i]<<endl;
    } 
    
    return 0;
}