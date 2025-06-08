//Create a class Employee with attributes name and salary.
// Use the this pointer to return the current object in member functions.
#include <iostream>
using namespace std;

class Employee {
    string name;
    float salary;

public:
    Employee(string name, float salary) {
        this->name = name;
        this->salary = salary;
    }

    Employee& increaseSalary(float amount) {
        this->salary += amount;
        return *this;
    }

    void display() {
        cout << "Employee Name: " << name << "\nSalary: " << salary << endl;
    }
};

int main() {
    Employee e1("John", 50000);
    e1.increaseSalary(5000).increaseSalary(2000);
    e1.display();
    return 0;
}

