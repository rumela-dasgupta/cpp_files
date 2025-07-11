#include<iostream>
using namespace std;
class Fixed_deposit{
	long int P_amount;
	int years;
	float Rate;
	float R_value;
	public:
		Fixed_deposit(){
		}
		Fixed_deposit(long int p,int y,float r=0.12);
		Fixed_deposit(long int p,int y,int r);
		void display(void);
};
Fixed_deposit::Fixed_deposit(long int p,int y,float r){
	P_amount=p;
	years=y;
	Rate=r;
	R_value=P_amount;
	for(int i=1;i<=y;i++){
		R_value=R_value*(1.0+r);
	}
}
Fixed_deposit::Fixed_deposit(long int p,int y,int r){
	P_amount=p;
	years=y;
	Rate=r;
	R_value=P_amount;
	for(int i=1;i<=y;i++){
		R_value=R_value*(1.0+float(r)/100.0);
	}
}
void Fixed_deposit::display(void){
	cout<<"principal amount="<<P_amount<<"\n"<<"Return value"<<R_value<<endl;
}
int main(){
	Fixed_deposit FD1,FD2,FD3;
	long int p;
	int y;
	float r;
	int R;
	cout<<"enter amt,period,interest rate(in percent)"<<endl;
	cin>>p>>y>>R;
	FD1=Fixed_deposit(p,y,R);
	cout<<"enter amt,period,interest rate(in decimal form)"<<endl;
	cin>>p>>y>>r;
	FD2=Fixed_deposit(p,y,r);

cout<<"enter amt,period"<<endl;
	cin>>p>>y;
	FD3=Fixed_deposit(p,y);
	FD1.display();
	FD2.display();
	FD3.display();
	return 0;
}
	
