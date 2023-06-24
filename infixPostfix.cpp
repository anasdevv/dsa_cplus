#include <iostream>
#include "stack.h"
using namespace std;
bool hasPriority(char input,char top){
	if(top == '(')
		return true;
	if(input == '^' && top!='^')
		return true;
	if((input == '*' || input=='/' || input == '%') && (top == '+' || top == '-'))
		return true;
//		cout <<input <<" "<<top<<endl;
	return false;
}
bool isParanthesis(char op){
	if(op == '(' || op == ')')
		return true;
	return false;
}
bool isOperator(char op){
	if(op == '^' || op =='*' || op == '/' || op == '+' || op == '-' || op == '%' )
		return true;
	return false;
}
string infixToPostfix(string exp){
	stack<char> s;
	string postFix = "";
	for(int i=0;i<exp.length();i++){
		if(exp[i] == ' ')
			continue;
		if(isOperator(exp[i])){
			if(s.isEmpty()){
				s.push(exp[i]);
			}
			else{
				if(hasPriority(exp[i],s.top())){
					s.push(exp[i]);
//					cout <<"+++++";
				}
				else{
					while(!s.isEmpty() && !hasPriority(exp[i],s.top())){
						postFix += s.top();
						s.pop();
					}
					s.push(exp[i]);
				}
			}
		}
		else if(isParanthesis(exp[i])){
			if(exp[i] == '(')
				s.push(exp[i]);
			else{
				while(!s.isEmpty() && s.top()!='('){
					postFix += s.top();
					s.pop();
				}
				s.pop();
			}
		}
		else{
			postFix += exp[i];
		}
	}
	while(!s.isEmpty()){
		postFix += s.top();
		s.pop();
	}
	return postFix;
}
int main(){
	string expression ;
	cout << "Enter the expression : ";
	getline(cin,expression);
	cout << infixToPostfix(expression);
}

