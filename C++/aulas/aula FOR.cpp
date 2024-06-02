#include <iostream>

using namespace std;

int main() {
    int tam = 10;
    int tab = 3;

    // CONTADOR DE 0 A 10
    cout << "contador de 0 a 10"<<endl;
    for (int i = 0; i <=tam; i++) {
        cout<< i <<endl;
    }
    //wINDOWS only 
    system("pause");
    system("cls");

    //LINUX E MACOS X
    //system("read -p ' Press enter to continue...'var");
    //system("clear");
    
    // CONTADOR DE EM 2 EM 2
    cout<<("contador de em 2 em 2");
    for (int i = 1; i <=tam; i=i+2) {
        cout<< i <<endl;
    }
    system("pause");
    system("cls");

    //CONTAGEM REGRESSIVA 
    cout<<("Contagem Regressiva");
    for (int i = 10; i >=0; i--) {
        cout << i <<endl;
    }
    system("pause");
    system("cls");

   //TABUADA
    cout <<("Tabuada do 3");
    for (int i = 0; i <=tam; i++) {
        cout << tab << " x " << i << " = " << tab*i <<endl;
    }

   //CONTADOR DE NUMEROS PARES
    cout <<("Contador de numeros pares");
    for (int i = 0; i <=tam; i=i+2) {
        cout << i <<endl;
    }
    system("pause");
    system("cls");


 return 0;
}