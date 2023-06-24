#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string s){
	stack<char> st;
	string str;
	for(char ch:s){
		if(ch == ' ')
			continue;
		if(isdigit(ch)){
			str += ch;
		}
		else if(ch == '(')
			st.push(ch);
		else if(ch == ')'){
			while(!st.empty() && st.top() != '('){
				str += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			if(st.empty() || prec(ch) > prec(st.top())){
				st.push(ch);
			}
			else{
				while(!st.empty() && prec(ch) <= prec(st.top())){
					str += st.top();
					st.pop();
				}
				st.push(ch);
			}
				
		}	
	}
	while(!st.empty()){
		char c = st.top();
		if(c != '(')
			str += c;
		st.pop();
	}
	return str;
}
int evaluatePostfixExpression(string s){
	stack <int> st;
	for(char ch : s){
		if(ch == ' ')
			continue;
		if(isdigit(ch)){
			int x = ch - 48;
			st.push(x);
		}
		else{
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			if(ch == '+'){
				st.push(val2 + val1);
			}else if(ch == '-'){
				st.push(val2 - val1);
			}else if(ch == '*'){
				st.push(val2 * val1);
			}else if(ch == '/'){
				st.push(val2 / val1);
			}else if(ch == '^'){
				st.push(pow(val2,val1));
			}
		}
	}
	return st.top();
}
int main(){
	string s =  infixToPostfix("3*(4+2)*5");
	cout << s << endl;
	cout << evaluatePostfixExpression(s) << endl;
}
