#include <iostream>
using namespace std;

int main() {

    int matriz [2][3];

    matriz [0][0] = 1;
    matriz [0][1] = 2;
    matriz [0][2] = 3;
    matriz [1][0] = 4;
    matriz [1][1] = 5;
    matriz [1][2] = 6;

   for (int i = 0; i < 2; i++) {
    
       for(int j = 0; j < 3; j++) {
          cout << "Digite o valor: "<<endl;
          cin>>matriz[i][j];
       }}


    for (int i = 0; i < 2; i++) {
    
       for(int j = 0; j < 3; j++) {
          cout << matriz[i][j] <<" ";
       }}

    return 0;
}