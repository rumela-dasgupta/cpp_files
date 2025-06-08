#include <iostream>
using namespace std;

class String {
    string s;

public:
    String() {}
    String(string a) { s = a; }         //This constructor takes a string as an argument (s) 
	                                    //and assigns it to the member variable str.
                                        //It initializes a String object with a given string.

    void string_con(const String& a) {  //This function takes another String object as a 
	                                     //constant reference (const String& s).
                                         //It appends (+=) the str member of s to the calling object's str.
        s += a.s;
    }

    void display() {
        cout << s << endl;
    }
};

int main() {
    String s1("Well");
    String s2(" Done");
    String s3 = s1; // Copy constructor (implicitly handled by std::string)

    s3.string_con(s2);
    s3.display(); // Output: Hello World
}

