#include<iostream>
using namespace std;

class Bank {
    string name, type;
    int acc;
    float amt;

public:
    Bank();  // Constructor
    void deposit_amt();
    void withdraw();
    void display();
};

Bank::Bank() {
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter account type: ";
    getline(cin, type);
    cout << "Enter account number: ";
    cin >> acc;
    amt = 0.0; // Initializing balance to 0.0
}

void Bank::deposit_amt() {
    float a;
    cout << "Enter amount to deposit: ";
    cin >> a;
    if (a > 0) {
        amt += a;
        cout << "Rs." << a << " deposited successfully." << endl;
    } else {
        cout << "Deposit amount must be positive." << endl;
    }
}

void Bank::withdraw() {
    float with_draw;
    cout << "Enter amount to withdraw: ";
    cin >> with_draw;
    if (with_draw > 0 && with_draw <= amt) {
        amt -= with_draw;
        cout << "Rs." << with_draw << " withdrawn successfully." << endl;
    } else if (with_draw > amt) {
        cout << "Insufficient balance, cannot withdraw." << endl;
    } else {
        cout << "Withdrawal amount must be positive." << endl;
    }
}

void Bank::display() {
    cout << "Account Holder: " << name << endl;
    cout << "Balance: Rs." << amt << endl;
}

int main() {
    const int size = 3;
    Bank account[size];
    
    for (int i = 0; i < size; i++) {
        cout << "\nTransactions for account " << i + 1 << ":" << endl;
        account[i].deposit_amt();
        account[i].withdraw();
        account[i].display();
    }
    
    return 0;
}

