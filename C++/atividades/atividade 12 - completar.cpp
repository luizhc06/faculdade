#include <iostream>
using namespace std;

int main() {
    int numero{10};    
    //----ESCREVA SEU CÓDIGO ABAIXO DESTA LINHA----

    //-- Multiplica o número por 2 e atribui o resultado de volta ao número
    numero *= 2;

    //-- Adiciona 9 ao número e atribui o resultado de volta ao número
    numero += 9;

    //-- Subtrair 3 do número e atribuir o resultado de volta ao número
    numero -= 3;

    //-- Divide o número por 2 e atribui o resultado de volta ao número
    numero /= 2;

    //-- Subtrair original_number de number e atribuir o resultado de volta a number
    numero -= numero;

    //-- Pegue o módulo 3 (%) do número e atribua-o de volta ao número
    numero %= 3;
    
    cout << "Resultado: " << numero << endl;
    return 0;

    //----ESCREVA SEU CÓDIGO ACIMA DESTA LINHA----
    
}
