#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int romanToInt(string s){
	map<char,int> value;
	value['I'] = 1;
	value['V'] = 5;
	value['X'] = 10;
	value['L'] = 50;
	value['C'] = 100;
	value['D'] = 500;
	value['M'] = 1000;
	int r=0;
	for(int i=0; i<s.size(); i++){
		r += value[s[i]];
		if(i>0 && value[s[i]] > value[s[i-1]])
			r-= 2 * value[s[i-1]];
	}
	return r;
}
int main(){
	string s;
	while(1){
		cin >> s;
		cout << romanToInt(s) << endl;
	}
	return 0;
}
