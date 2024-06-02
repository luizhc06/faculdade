#include <iostream>
using namespace std;

int main() {
   cout << ("Pares de 1 a 50")<<endl;
   for (int i = 1; i <= 50; i++) {
     if (i % 2 == 0) {
       cout << i << endl;
     }
   }

  return 0;
}