// 1) d.	Solve all above qsns using tail recursion

#include<iostream>
using namespace std;
class Solution {
    public:
    static long _factorial (int n, long res) {
        if (n == 1) 
            return res;
        return _factorial(n-1, n*res);
    }
    static int _fibonacci (int n, int s) {
        if (n == 1)
            return s + 0;
        else if (n == 2)
            return s + 1;
        return _fibonacci (n - 1, s);
    }

    // wrappers
    static long factorial (int n) {
        return _factorial(n, 1);
    }
    static int fibonacci (int n) {
        return _fibonacci(n, 0);
    }
};

int main () {
    int n = 5;
    cout << "Factorial of " << n << ": " << Solution::factorial(n) << endl;
    cout << n << "th fibonacci: " << Solution::fibonacci(n) << endl;
    return 0;
}