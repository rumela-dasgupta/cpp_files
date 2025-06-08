//Create a class Box with private attributes length, breadth, and height. 
//Use a friend function to calculate the volume of the box
#include<iostream>
using namespace std;

class Box{
	float length,breadth,height;
	public:
		Box(float l,float b,float h);
		Box();
		~Box();
		friend float volume(Box b);
};
Box::Box(float l, float b, float h) {
        length = l;
        breadth = b;
        height = h;
    }
float volume(Box b) {
    return b.length * b.breadth * b.height;
}
inline Box::~Box(){
}
int main() {
    Box b1(3, 4, 5);
    cout << "Volume: " << volume(b1) << endl;
    return 0;
}
