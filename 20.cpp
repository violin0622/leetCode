#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatch(char l,char r){
	return ( l=='(' && r==')' ||
			 l=='[' && r==']' ||
			 l=='{' && r=='}' );
}
bool isValid(string s){
	stack<char> stk;
	for(char c : s){
		switch(c){
			case '(':
			case '[':
			case '{':
				stk.push(c);
				break;
			case ')':
			case ']':
			case '}':
				if(stk.empty() || !isMatch(stk.top(), c)) return false;
				stk.pop();
				break;
			default:
				return false;
		}
	}
	return stk.empty();
}

int main(){
	string s = "{{([";
	cout << isValid(s);
	return 0;
}
