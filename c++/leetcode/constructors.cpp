#include<iostream>
using namespace std;

class Box{
	private:
		int length;
		int width;
	public:
		Box()
		{
			length = 0;
			width = 0;
			cout << "No arg constructor called"<< endl;	
		} 
		~Box(){
			cout << "Destructor called" << endl;
		}
		Box(int l, int w)
		{
			length= l;
			width = w;	
			cout << "Arg constructor called"<< endl;	
		}
		
		void print(){
			cout<< length << endl << width << endl;
		}
};

int main(){
//	Box b1(5,2);
Box *b = new Box(5,2);
	
//	b1(5,3);
	
	b->print();
	delete b;
	return 0;
}
