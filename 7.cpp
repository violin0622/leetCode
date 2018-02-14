#include <iostream>
#include <queue>
#include <string>

using namespace std;

int reverse(int x){
	queue<int> stk;
	while(x/10){
		stk.push(x%10);
		x/=10;
	}
	stk.push(x);

	long long r=0;
	while(!stk.empty()){
		r += stk.front();
		stk.pop();
		r *= 10;
	}
	r /= 10;
	long long min = ~0 & ~0x7fffffff;
	if(r > 0xefffffff || r < min)
		return 0;
	return r;
}
int main(){

	cout << reverse(1534236469);
	cout << reverse(123);
	return 0;
}
