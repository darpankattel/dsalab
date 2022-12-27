// 1) a.	SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.

#include <iostream>
using namespace std;

class TOH {
    public:
    static void get_steps (int n, char source, char destination, char auxillary) {
        if (n == 1)
            cout << "Move from " << source << " to " << destination << endl;
        else {
            get_steps(n-1, source, auxillary, destination);
            get_steps(1, source, destination, auxillary);
            get_steps(n-1, auxillary, destination, source);
        }
    }
};

int main () {
    int n = 4;
    TOH::get_steps(4, 'A', 'B', 'C');
    return 0;
}