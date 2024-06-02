#include <iostream>
using namespace std;

int main() { 
  int num1 = 200;
  int num2 = 100;
  int result;
  result = ++num1;
  result = --num2;
  int result1 = --num2 - 10; 
  
  cout << "num1 + num2 = " << num1 + num2 << endl; 
  cout << "num1 - num2 = " << num1 - num2 << endl; 
  cout << "num1 * num2 = " << num1 * num2 << endl; 
  cout << "num1 / num2 = " << num1 / num2 << endl; 
  cout << "num1 % num2 = " << num1 % num2 << endl; 

  //incremento

  cout << "valor com incremento: " << result << endl; 

  cout << "valor com incrementos: " << result1 << endl;
  
  return 0;

}
