#include <iostream>
using namespace std;

class Books{
	string author,title,publisher;
	int price,stock;
	static int successfulTransactions;
    static int unsuccessfulTransactions;
	// Private function to update price
    void updatePrice(int newPrice) {
        price = newPrice;}
	public:
		Books(string a,string t,string p,int pr,int st){
			author=a;
			title=t;
			publisher=p;
			price=pr;
			stock=st;
			
		}
		// Function to display book details
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication: " << publisher << endl;
        cout << "Price: Rs." << price << endl;
        cout << "Stock: " << stock << endl;
    }
    bool searchBook(string t, string a) {
        return (title == t && author == a);
    }
     void handleRequest(int requiredCopies) {
        if (requiredCopies > stock) {
            cout << "Required copies not in stock." << endl;
            unsuccessfulTransactions++;
        } else {
            float totalCost = requiredCopies * price;
            cout << "Total cost for " << requiredCopies << " copies: Rs." << totalCost << endl;
            stock -= requiredCopies;  // Reduce stock
             successfulTransactions++;
             cout << "Updated stock: " << stock << " copies remaining." << endl;
        }
    }
    // Public function to modify price
    void modifyPrice(int newPrice) {
        updatePrice(newPrice);
    }
    // Static function to display transaction details
    static void displayTransactionDetails() {
        cout << "Successful Transactions: " << successfulTransactions << endl;
        cout << "Unsuccessful Transactions: " << unsuccessfulTransactions << endl;
    }
};
int Books::successfulTransactions = 0;
int Books::unsuccessfulTransactions = 0;

	int main() {
    // Creating an array of books (inventory)
    Books book1("J.K. Rowling", "Harry Potter", "Bloomsbury",29, 10);
    Books book2("J.R.R. Tolkien", "The Hobbit", "HarperCollins",15, 5);

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
        
    }
    // Display transaction details
    Books::displayTransactionDetails();

    return 0;
}

