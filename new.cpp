#include<iostream>
using namespace std;
class Bank{
	string name,type;
	int acc;
    float amt;
	public:
		void init_val(void);
		void deposit_amt(void);
		void withdraw(void);
		void display(void);
};
void Bank::init_val(void){
	cout<<"enter name:"<<endl;
	cin.ignore();
	getline(cin,name);
	cout<<"enter account type:"<<endl;;
	getline(cin,type);
	cout<<"enter account number:"<<endl;;
	cin>>acc;
	
}
void Bank::deposit_amt(void){
	float a;
	cout<<"enter amount to deposit:"<<endl;
	cin>>a;
	if (a>0){
		amt+=a;
		cout << "Rs." << a << " deposited successfully." << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
	}
void Bank:: withdraw(void){
	float with_draw;
	cout<<"enter amount to withdraw:"<<endl;
	cin>>with_draw;
	if (with_draw > 0 && with_draw <= amt) {
            amt -= with_draw;
            cout << "Rs." << with_draw << " withdrawn successfully." << endl;
}
else if (with_draw>amt){
	cout<<"Insufficient balance cannot withdraw"<<endl;

}
else{
	cout << "Withdrawal amount must be positive." << endl;
}
}
void Bank::display(void){
	    cout << "Account Holder: " << name << endl;
        cout << "Balance: Rs." << amt << endl;
	
}

int main() {
	const int size=3;
    Bank account[size];
    for(int i=0;i<size;i++){
    	cout<<"details"<<endl;
    	account[i].init_val();
    	cout<<"depositing"<<endl;
    	account[i].deposit_amt();
	}
	cout<<"\n";
    for(int i=0;i<size;i++){
    	
        account[i].withdraw();
        account[i].display();
		}
    	
    
    return 0;
}
