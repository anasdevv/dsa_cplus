#include<iostream>
using namespace std;
class twoStacks{
	int *arr;
	int top1;
	int top2;
	int size;
	public:
		twoStacks(int n){
			arr = new int[n];
			top1 = -1;
			top2 = n;
		}
		void push1(int);
		void push2(int);
		int pop1();
		int pop2();
};
//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top2-top1 >= 0){
        top1 += 1;
        arr[top1] = x;
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
        if(top2-top1 >= 0){
        top2 -= 1;
        arr[top2] = x;
    }

}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1 == -1)
        return -1;
    int x = arr[top1];
        top1 -= 1;
    return x;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 == size)
        return -1;
    int x = arr[top2];
    top2 += 1;
    return x;
}

int main(){
	
}
