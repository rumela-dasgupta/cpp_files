#include <iostream>
using namespace std;

class sample{
	int a,b;
	public:
		void setvalue(){
			a=10;
			b=18;
		}
		friend int mean(sample obj);
};
int mean(sample obj){
	return float(obj.a+obj.b)/2.0;
}
int main(){
	sample x;
	x.setvalue();
	cout<<"mean:"<<mean(x)<<endl;
	return 0;
}
