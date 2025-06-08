#include <iostream>
using namespace std;

class Sample {
private:
    int num;
public:
    Sample(int n) : num(n) {}//   Sample(int n) {
                            //num = n;}  // Assigning value to num inside the constructor body


    // Friend function declaration
    friend void display(Sample s);
};

// Friend function definition
void display(Sample s) {
    cout << "The value of num is: " << s.num << endl;
}

int main() {
    Sample obj(10);
    display(obj); // Calling friend function
    return 0;
}

