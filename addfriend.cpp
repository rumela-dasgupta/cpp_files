#include<iostream>
using namespace std;
class complex{
	int real,imag;
	public:
		void input(int real,int imag){
		this->	real=real;
		this->	imag=imag;
		}
		friend complex add(complex,complex);
		void show();
};
complex add(complex c1,complex c2){
	complex c3;
	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}
void complex::show(){
	cout<<real<<"+"<<imag<<"j"<<endl;
	
}
int main(){
	complex a,b,c;
	a.input(10,2);
	b.input(20,3);
	c=add(a,b);
	cout<<"A=";a.show();
	cout<<"B=";b.show();
	cout<<"C=";c.show();
	return 0;
}
