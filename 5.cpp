#include <iostream>
#include <string>
#include <cstdio>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string expandPalidrome(string s, int L, int R){
	if(s[L] != s[R]) return "";
	while(L>=0 && R<s.size() && s[L] == s[R]){
		L--; R++;
	}
	L++,R--;
	string r(s, L, R-L+1);
	return r;
}

string longestPalindromeString(string s){
	string r = "";
	for(int i=0; i<s.size(); i++){
		string s1 = expandPalidrome(s,i,i);
		string s2 = expandPalidrome(s,i,i+1);
		if(s1.size() > r.size())
			r = s1;
		if(s2.size() > r.size())
			r = s2;
	}
	return r;
}

int main(){
	cout << longestPalindromeString("abccbabb");
	return 0;
}
