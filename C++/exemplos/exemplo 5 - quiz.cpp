#include <iostream>
using namespace std; 

int main () {

    int x = 10, y = 3, z = 6;
    cout << (x == y) << "  ";
    cout << (z <= x) << "  ";
    cout << (y != z) << "  ";
    cout << (x > y && z < x) << "  ";
    cout << (y < x && z < x) << "  ";
    cout << (x < y || z < 0) <<endl;
    return 0;
}