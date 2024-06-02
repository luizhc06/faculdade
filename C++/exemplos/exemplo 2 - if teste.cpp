#include <iostream>
using namespace std;

int main() {
    int nota;

    cout << "Digite a sua nota do exame (0 - 100): ";
    cin >> nota;
    char notaletra;

    if (nota >= 0 && nota <= 100) {
        if (nota >= 90)
            notaletra = 'A';

        else if (nota >= 80)
            notaletra = 'B';

        else if (nota >= 70)
            notaletra = 'C';

        else if (nota >= 60)
            notaletra = 'D';

        else
            notaletra = 'E';

        cout << "Nota atribuida: " << notaletra << endl;

        if (notaletra == 'E') {
            cout << "Voce nao conseguiu passar!" << endl;

        } else {
            cout << "Voce passou!" << endl;

        }
        } else {
            cout << "Numero invalido!" << endl;

    }

    return 0;
}
