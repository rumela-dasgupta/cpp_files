//Create a class Rectangle with two constructors:
//One that accepts length and width and calculates the area.
//Another that accepts only one parameter and assumes it's a square.
#include <iostream>
using namespace std;

class Rectangle {
    float length, width;

public:
    Rectangle(float l,float w);//parameterised constructor
    Rectangle(float s);//parameterised constructor
    Rectangle();//default constructor
    ~Rectangle();
    void display();
};
Rectangle::Rectangle(float l,float w){
	length=l;
	width=w;
}
Rectangle::Rectangle(float s){
	length=width=s;
}
Rectangle::Rectangle(){
	cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
}
void Rectangle::display(){
	cout<<"the required area is"<<length*width<<endl;
}
inline Rectangle::~Rectangle(){
}
int main(){
	Rectangle r;
	Rectangle r1(5,10);
	Rectangle r2(6);
	r.display();
	r1.display();
	r2.display();
	return 0;
}
