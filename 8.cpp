#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ignoreWhite(string &s){
	while(s.size() && s[0] < 33 || s[0] > 126  )
		s.erase(s.begin());
	return s;
}

int judgeOptive(string &s){
	if(s[0] == '+'){
		s.erase(s.begin());
		return 1;
	}else if(s[0] == '-'){
		s.erase(s.begin());
		return -1;
	}else if(s[0] <= '9' && s[0] >= '0')
		return 1;
	else
		return 0;
}

long long turnString(string &s){
	long long r=0;
	int i=0;
	while(s[i] <= '9' && s[i] >= '0' && i<s.size()){
		r = r*10 + s[i++] - '0';
		printf("r: %lx\n", r);
		if(r > 0x7fffffff)
			return r;
		if(r < ~0x7fffffff)
			return r;
	}
	return r;
}
int myAtoi(string s){
	ignoreWhite(s);
	if(!s.size()) return 0;

	int flag = judgeOptive(s);
	long long r = turnString(s) * flag;

	printf("r: %lx\n", r);

	if(r > 0x7fffffff)
		return 0x7fffffff;
	if(r < ~0x7fffffff)
		return ~0x7fffffff;
	return r;
}
int main(){
	cout << myAtoi("-2147483648");
	cout << myAtoi("9223372036854775809");
	cout << myAtoi("18446744073709551617");

	return 0;
}
