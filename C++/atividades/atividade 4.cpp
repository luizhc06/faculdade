#include <iostream>
using namespace std;

 int main() {
  
  int num1;
  int num2;

     cout<< boolalpha;
     cout<<"Digite dois numeros separados por um espaço";

     cin>>num1>>num2;

     cout<<num1<<" > "<<num2<<" ; "<<(num1>num2) << endl;

     const int maior = 20;
     const int menor = 10;

     cout<< num1 << " > " << maior << " ; "<< (num1>num2) ;


   return 0;
 }