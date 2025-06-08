//using pointers
#include <iostream>
#include <string>
using namespace std;

class Books {
private:
    string *author;
    string *title;
    float *price;
    string *publication;
    int *stock;
    static int successfulTransactions;
    static int unsuccessfulTransactions;

    // Private function to update price
    void updatePrice(float newPrice) {
        *price = newPrice;
    }

public:
    // Default constructor
    Books() {
        author = new string("");
        title = new string("");
        publication = new string("");
        price = new float(0.0);
        stock = new int(0);
    }

    // Parameterized constructor
    Books(string a, string t, float p, string pub, int s) {
        author = new string(a);
        title = new string(t);
        publication = new string(pub);
        price = new float(p);
        stock = new int(s);
    }

    // Destructor
    ~Books() {
        delete author;
        delete title;
        delete publication;
        delete price;
        delete stock;
    }

    // Function to display book details
    void displayBookDetails() {
        cout << "Title: " << *title << endl;
        cout << "Author: " << *author << endl;
        cout << "Publication: " << *publication << endl;
        cout << "Price: $" << *price << endl;
        cout << "Stock: " << *stock << endl;
    }

    // Function to search for a book
    bool searchBook(string t, string a) {
        return (*title == t && *author == a);
    }

    // Function to handle book request
    void handleRequest(int requiredCopies) {
        if (requiredCopies > *stock) {
            cout << "Required copies not in stock." << endl;
            Books::unsuccessfulTransactions++;
        } else {
            float totalCost = requiredCopies * (*price);
            cout << "Total cost for " << requiredCopies << " copies: $" << totalCost << endl;
            *stock -= requiredCopies;  // Reduce stock
            Books::successfulTransactions++;
            cout << "Updated stock: " << *stock << " copies remaining." << endl;
        }
    }

    // Public function to modify price
    void modifyPrice(float newPrice) {
        updatePrice(newPrice);
    }

    // Static function to display transaction details
    static void displayTransactionDetails() {
        cout << "Successful Transactions: " << successfulTransactions << endl;
        cout << "Unsuccessful Transactions: " << unsuccessfulTransactions << endl;
    }

    // Static function to increment unsuccessful transactions
    static void incrementUnsuccessfulTransaction() {
        Books::unsuccessfulTransactions++;
    }
};

// Initialize static members
int Books::successfulTransactions = 0;
int Books::unsuccessfulTransactions = 0;

int main() {
    // Creating an array of books (inventory)
    Books book1("J.K. Rowling", "Harry Potter", 29.99, "Bloomsbury", 10);
    Books book2("J.R.R. Tolkien", "The Hobbit", 15.99, "HarperCollins", 5);

    // User inputs title and author
    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    // Check if the book exists
    if (book1.searchBook(title, author)) {
        cout << "Book found: " << endl;
        book1.displayBookDetails();
        int copies;
        cout << "Enter number of copies required: ";
        cin >> copies;
        book1.handleRequest(copies);
    } else if (book2.searchBook(title, author)) {
        cout << "Book found: " << endl;
        book2.displayBookDetails();
        int copies;
        cout << "Enter number of copies required: ";
        cin >> copies;
        book2.handleRequest(copies);
    } else {
        cout << "Book not found in inventory." << endl;
        Books::incrementUnsuccessfulTransaction();
    }

    // Display transaction details
    Books::displayTransactionDetails();

    return 0;
}

