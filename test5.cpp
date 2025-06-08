//Overload the + and * operators for a class Complex to add and multiply two complex numbers.
#include<iostream>
using namespace std;

class Complex{
	int real, imag;
	public:
		Complex( int, int );
		//Complex();
		~Complex();
		//Complex add(Complex &);
		//Complex multiply(Complex &);
		Complex operator+(Complex &);
		Complex operator*(Complex &);
		void display();
};

inline Complex :: Complex( int real, int imag ){
	Complex::real = real;
	Complex::imag = imag;
}

inline Complex Complex::operator+(Complex &c){
	return Complex(real + c.real, imag + c.imag);
}

//inline Complex Complex::add(Complex &c){
//	Complex t;
//	t.real = real + c.real;
//	t.imag = imag + c.imag;
//	return t;
//}

//inline Complex Complex::multiply(Complex &c){
//	Complex t;
//
//	t.real = (real * c.real) - (imag * c.imag);
//
//	t.imag = (real * c.imag) + (imag * c.real) ;
//
//	return t;
//}
inline Complex Complex::operator*(Complex &c){
	return Complex(((real * c.real)-(imag * c.imag)), ((real * c.imag) + (imag * c.real)));
}



inline void Complex::display(){
	cout<<this -> real<<"+i"<<this -> imag<<endl;
	
}

//inline Complex::Complex(){
//}
inline Complex::~Complex(){
}

int main(){
	Complex c1(7,8);
	Complex c2(3,9);
	//Complex c3;
	//Complex c4;
	//c3 = c1.add(c2);
	//c4 = c1.multiply(c2);
	Complex c3 = c1 + c2;
	Complex c4=c1*c2;
	c3.display();
	c4.display();
	//c4.display();
	return 0;
}
