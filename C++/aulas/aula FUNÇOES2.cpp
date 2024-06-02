#include <iostream>
using namespace std;

int somar (int x, int y){
    return x + y;
}

int main() {

    cout << "Digite dois valores" << endl;
     int n1, n2;
     cin >> n1 >> n2;

    int s;
     s = somar(n1, n2);
     cout << "\nO resultado eh: "<< s << endl;
    

    return 0;
}