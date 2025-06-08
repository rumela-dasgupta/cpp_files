//This program overloads the + operator using a friend function.
#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r, int i) {
    	real=r;
    	imag=i;
	}

    // Friend function to overload + operator
    friend Complex operator+(Complex c1, Complex c2);

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Definition of friend function
Complex operator+(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2; // Calls overloaded + operator
    c3.display();
    return 0;
}

