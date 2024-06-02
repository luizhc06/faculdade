#include <iostream>
using namespace std;
bool saida = true;

void turmaA () {
   cout << "Horario Turma A: \n segunda - Prog. I \n Terca - Matematica " << endl;
   saida = false;
}

void turmaB () {
   cout << "Horario Turma B: \n segunda - Criatividade e Ino. \n Terca - Prog. I " << endl;
   saida = false;
}

int main() {

while (saida == true) {

     cout << "Digite qual turma voce eh: " << endl;
     char turma;
     cin >> turma;

   switch (turma) {
  
   case 'a':
   case 'A':
   turmaA();
   break;
  
   case 'b':
   case 'B':
   turmaB();
   break;

   default :
     cout << "turma digitada incorretamente, so existe turma A e B. " <<endl;

  }}

  cout << "\nFIM" <<endl;
  system("pause");
  return 0;
}
