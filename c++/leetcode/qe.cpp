#include<iostream>
using namespace std;
class A{
	public:
	A(){
		cout << "A" << endl;
	}
	~A(){
		cout << "Des A" << endl;
	}
};
class B {
	public:
	B(){
		cout << "B" << endl;
	}
	~B(){
		cout << "Des B" << endl;
	}
	
};
class C : public B{
	public:
		C(){
		cout << "C" << endl;
	}
	~C(){
		cout << "Des C" << endl;
	}
};
int main(){
	C c;
}
