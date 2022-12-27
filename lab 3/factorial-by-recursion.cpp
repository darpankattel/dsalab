// 1) a.	FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.

#include <iostream>
using namespace std;

long factorial (int n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int main () {
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    long factorial_value = factorial(n);
    cout << n << "! = " << factorial_value << endl;
    return 0;
}