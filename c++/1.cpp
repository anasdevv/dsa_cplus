#include<iostream>
using namespace std;
class A{
	int x;
	public:
		A operator + (A z){
		 	A t;
		 	z.display();
			t.x = x + z.x;
			return t;
		}
		A(int x){
			this->x= x;
		}
		void display(){
			cout << x << endl;
		}
		bool operator == (A z){
			return (x == z.x);
		}
		void operator ++() {
		x++;
		}
		void operator++(int){
		x++;
		} 
		A(){
		x = 0;
		};
		bool operator < ( A &b){
			return x < b.x;
			}
};
int main(){
	A a(5);
	A b(5);
	A c;
//    a = a + b;
	c = a + b;
	++c;
	c++;
	c.display();
	cout << (a == b) << endl;
	cout << (a < b) << endl;
//	a.display();
}
