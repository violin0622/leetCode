#include <iostream>
#include <vector>
#include <string>
using namespace std;

string intToRoman(int num){
	string r="";
	int p = num / 1000;
	r.append(p, 'M');

	p = num / 100 - p * 10;
	if (p==9)
		r.append("CM");
	else if (p==4)
		r.append("CD");
	else if (p==5)
		r.append("D");
	else if (p<4)
		r.append(p, 'C');
	else{
		r.append("D");
		r.append(p-5, 'C');
	}

	p = num / 10 - num / 100 * 10;
	if(p==9)
		r.append("XC");
	else if (p==4)
		r.append("XL");
	else if (p==5)
		r.append("L");
	else if (p<4)
		r.append(p, 'X');
	else{
		r.append("L");
		r.append(p-5, 'X');
	}

	p = num % 10;
	if(p==9)
		r.append("IX");
	else if (p==4)
		r.append("IV");
	else if (p==5)
		r.append("V");
	else if (p<4)
		r.append(p, 'I');
	else{
		r.append("V");
		r.append(p-5, 'I');
	}
	return r;
}
int main(){
	int i;
	while(1){
		cin >> i;
		cout << intToRoman(i);
	}
	return 0;
}

