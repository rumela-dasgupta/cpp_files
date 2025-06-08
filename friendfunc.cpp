#include<iostream>
using namespace std;
class ABC;//forward declaration
class XYZ{
	int a;
	public:
		void setvalue(int i){a=i;
		}
		friend void max(XYZ,ABC);
};
class ABC{
	int b;
	public:
		void setvalue(int j){b=j;
		}
		friend void max(XYZ,ABC);
};
void max(XYZ m,ABC n){
	if (m.a>n.b){
		cout<<m.a;
	}
	else{
		cout<<n.b;
	}
}
int main(){
	ABC abc;
	abc.setvalue(10);
	XYZ xyz;
	xyz.setvalue(20);
	max(xyz,abc);
	return 0;
	
}
