#include <iostream>
using namespace std;
  
  int main() { 
  int num;
  const int min = 10;
  const int max = 100;

  cout<<"Informe um numero: "<<min " e "<<max;" ."
  cin>>min;

   if (num >= min) {
   cout<<"=================== if 1 =================="<<endl;
   cout<< num <<"e maior ou igual"<<min <<endl;

   int dif =(num < min);
   cout<< num <<" e "<<dif<< "maior que "<<min<<endl;
   }

   if (num <= max) {
   cout<<"=================== if 2 =================="<<endl;
   cout<< num <<"e maior ou igual"<<max <<endl;

   int dif =(num < max);
   cout<< num <<" e "<<dif<< "maior que "<<min<<endl;
   }

   if (num || max) {
   cout<<"=================== if 3 =================="<<endl;
   cout<< num <<"e maior ou igual"<<max <<endl;

   int dif =(num < max);
   cout<< num <<" e "<<dif<< "maior que "<<min<<endl;
   }

   



   return 0;
  }