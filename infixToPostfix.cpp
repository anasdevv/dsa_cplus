#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int precedence(char C){
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	return 0;
}
bool isOperator(char ch){
	if(ch == '+' || ch == '-' || ch =='*' || ch == '/')
		return 1;
	return 0;
}

string infixToPostfix(string exp){
	string s;
	stack<char> st;
	for(char ch : exp){
		if(!isOperator(ch)){
			s += ch;
			continue;
		}
		if(isOperator(ch) && st.empty() || (precedence(ch) > precedence(st.top()) )){
			st.push(ch);
		}
		else{
			if(ch == ')'){			
				while(!st.empty() && st.top() != '('){
					s += st.top();
					st.pop();
				}
				st.pop();
			}
			while(!st.empty() && (precedence(st.top()) > precedence(ch))){
				s += st.top();
				st.pop();
			}
			 st.push(ch);
		}			
	}
	while(!st.empty()){
		s  += st.top();
		st.pop();
	}
	return s;
}
int main(){
	string ss = "A+B*C/(E-F)";
	string s = infixToPostfix(ss);
	cout << s << endl;
}
