// 1) b.	FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
// 0 1 1 2 3 5 8 13 21 34
#include<iostream>
using namespace std;

int fibonacci (int n) {
    if (n==1)
        return 0;
    else if (n==2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int n;
    cout << "Enter n (number): " << endl;
    cin >> n;
    int fibonacci_value = fibonacci(n);
    cout << n << "th fibonacci is: " << fibonacci_value << endl;
    return 0;
}