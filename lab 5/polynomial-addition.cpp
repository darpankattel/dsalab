// 3.	REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM ADDITION OF TWO POLYNOMIALS.

#include <iostream>
using namespace std;

class Term {
    public:
    double coeff;
    double pow;
    Term* next;

    Term(double c, double p) : coeff(c), pow(p) {
        next = nullptr;
    }
};

class Polynomial {
    private:
    int size;
    Term* head;

    public:
    Polynomial (int s = 0): size(s) {
        head = nullptr;
    }
    void append (double c, double p) {
        Term* newTerm = new Term(c, p);
        Term* temp = head;
        if (head == nullptr) {
            head = newTerm;
            return;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
    Polynomial* operator+ (Polynomial p) {
        int s = 0;
        Polynomial* sum = new Polynomial();
        Term* temp1 = head;
        Term* temp2 = p.head;
        while (temp1->next != nullptr && temp2->next != nullptr)
        {
            s++;
            cout << s<< endl;
            if (temp1->pow == temp2->pow) {
                sum->append(temp1->coeff + temp2->coeff, temp1->pow);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->pow > temp2->pow) {
                sum->append(temp1->coeff, temp1->pow);
                temp1 = temp1->next;
            } else {
                sum->append(temp2->coeff, temp2->pow);
                temp2 = temp2->next;
            }
        }

        while (temp1->next != nullptr) {
            sum->append(temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        }
        sum->append(temp1->coeff, temp1->pow);

        while (temp2->next != nullptr) {
            sum->append(temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        }
        sum->append(temp2->coeff, temp2->pow);

        sum->size = s;
        return sum;
    }
    void print () {
        Term* temp = head;
        if (temp == nullptr)
            return;
        while (temp->next != nullptr)
        {
            cout << temp->coeff << "^" << temp->pow << " + ";
            temp = temp->next;
        }
        cout << temp->coeff << "^" << temp->pow << endl; 
    }
    void query () {
        cout << "Enter coeff. and pow.:" << endl;
        for (int i = 0; i < size; i++)
        {
            double c, p;
            cin >> c >> p;
            append(c, p);
        }
    }
};

int main () {
    int s1 = 3, s2 = 3;
    Polynomial* p1 = new Polynomial(s1);
    Polynomial* p2 = new Polynomial(s2);
    p1->query();
    p2->query();
    p1->print();
    p2->print();
    Polynomial* p3 = *p1 + *p2;
    cout << "Sum is: ";
    p3->print();
    return 0;
}