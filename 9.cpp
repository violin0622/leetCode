#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(int c){
	int size=0, x=c;
	while(x){
		size++;
		x /= 10;
	}
}

int main(){
	cout << isPalindrome(-2147447412);
	cout << isPalindrome(1);
	cout << isPalindrome(12321);
	return 0;
}
