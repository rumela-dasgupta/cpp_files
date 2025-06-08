#include<iostream>
using namespace std;

class A{
	int salary;
	public:
		void setSalary(int s){
			salary=s;
		}
			
		
		int displaySalary(){
			return salary;
		}
		
	
};
int main(){
	A obj;
	int userSalary;
  
  // Taking input from the user
    cout << "Enter the salary: ";
    cin >> userSalary;
  
    obj.setSalary(userSalary);
	
	cout<<"the required salary:"<<obj.displaySalary();
	return 0;
}
