#include <iostream>
using namespace std;

int main() {

   char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
   cout << "a primeira vogal eh: " << vogais[0] << endl;
   cout << "a ultima vogal eh: " << vogais[4] << endl;

   double temperatura[] = {90.1, 89.8, 77.5, 81.6};
   cout << "a primeira temperatura eh: " << temperatura[0] << endl;
   temperatura[0] = 100.7;
   cout << "a ultima temperatura eh: " << temperatura[3] << endl;

   int pont[5] = {100, 90, 80, 70, 60};
   for (int i = 0; i < 5; i++) {
    cout << pont[i] << endl;
   }

   return 0;
}