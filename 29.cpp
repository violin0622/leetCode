#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

int divide(int dividend, int divisor){
	if(divisor == 0) return 0;
	long a = dividend, b = divisor;
	int flag = ((a>0 && b<0) || (a<0 && b>0)) ? -1 : 1;
	a = abs(a), b = abs(b);

	long times=0, tmp=b, result=0;
	while(tmp <= a){
		times = 1;
		while(tmp < a){
			times <<= 1;
			tmp <<= 1;
		}
		if(a!=tmp){
			times >>= 1;
			tmp >>= 1;
		}
		a -= tmp;
		result += times;
		tmp = b;
	}
	result *= flag;
	if(result > INT_MAX || result < INT_MIN) return INT_MAX;
	else return result;
}

void test(){
	cout <<"0 " << divide(0,3) << endl;
	cout <<"0 " << divide(2,3) << endl;
	cout <<"1 " << divide(4,4) << endl;
	cout <<"1 " << divide(4,3) << endl;
	cout <<"2 " << divide(7,3) << endl;
	cout <<"3 " << divide(9,3) << endl;
	cout <<"0 " << divide(3,0) << endl;
	cout <<INT_MAX/INT_MIN << " " << divide(INT_MAX,INT_MIN) << endl;
	cout <<INT_MIN/INT_MAX << " " << divide(INT_MIN,INT_MAX) << endl;
	cout <<INT_MAX/-1 << " " << divide(INT_MAX,-1) << endl;
	cout <<INT_MIN/-1 << " " << divide(INT_MIN,-1) << endl;
	cout <<INT_MIN/1 << " " << divide(INT_MIN,1) << endl;
}
int main(){
	//cout << INT_MAX/-1 << endl;
	//cout <<"INT_MAX " << divide(1,-1) << endl;
	test();
	return 0;
}
