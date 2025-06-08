#include<iostream>
using namespace std;

class Vector {
private:
    int size;
    float elements[100]; // Fixed-size array instead of dynamic allocation

public:
    // Constructor
    Vector(int s) {
        size = s;
        for (int i = 0; i < size; i++) {
            elements[i] = 0.0; // Initialize to zero
        }
    }

    // Function to input vector elements
    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> elements[i];
        }
    }

    // Function to display vector elements
    void display() {
        cout << "Vector: ( ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << ")" << endl;
    }

    // Function to add two vectors
    void add(Vector &v, Vector &result) {
        if (size != v.size) {
            cout << "Error: Vectors must be of the same size!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] + v.elements[i];
        }
    }

    // Function for scalar multiplication
    void scalarMultiply(float scalar, Vector &result) {
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] * scalar;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    Vector v1(size), v2(size), sum(size), scaled(size);
    
    cout << "Enter elements for first vector:\n";
    v1.input();
    
    cout << "Enter elements for second vector:\n";
    v2.input();

    cout << "First ";
    v1.display();
    cout << "Second ";
    v2.display();

    v1.add(v2, sum);
    cout << "Sum ";
    sum.display();

    float scalar;
    cout << "Enter scalar value for multiplication: ";
    cin >> scalar;

    v1.scalarMultiply(scalar, scaled);
    cout << "Scalar multiplied ";
    scaled.display();

    return 0;
}

