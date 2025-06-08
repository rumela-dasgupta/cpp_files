//friend function as a member of another class
#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
private:
    int numA;
public:
    A(int a) {
    	numA=a;
	}
    friend class B; // Declaring entire class B as friend
};

class B {
public:
    void display(A obj) {
        cout << "Value from class A: " << obj.numA << endl;
    }
};

int main() {
    A objA(20);
    B objB;
    objB.display(objA); // Accessing private member of A
    return 0;
}

