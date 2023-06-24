#include<iostream>
using namespace std;
class A{
	public:
		int x;
		int friend  operator ++(A z){
		z.x++;
		}
};
int main(){
	A a;
	++a;
}
