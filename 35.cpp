#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

int searchInsert(vector<int>& nums, int target){
	if(nums.size() == 0) return 0;
	int L = 0, R = nums.size()-1, M = (L+R)/2;
	while(L<=R){
		M = (L+R)/2;
		if(nums[M] > target) R = M-1;
		else if(nums[M] < target) L = M+1;
		else return M;
	}
	return L;
}

void vectorTest(vector<int> &nums,int tar){
	cout << "{";
	for(int i : nums) cout << i << " ";
	cout << "}";
	for(int i=0; i<30-nums.size()*2; i++) cout << " ";
	cout << "target: " << tar << " " << searchInsert(nums, tar) << endl;
}
void test(){
	vector<int> a;
	a={0,1,1,1,1,4,4,5,6};
	vectorTest(a,0);
	vectorTest(a,6);
	vectorTest(a,4);
	vectorTest(a,-1);
	vectorTest(a,2);
	vectorTest(a,9);

	a={0,0,0,0,0};
	vectorTest(a,0);
	vectorTest(a,-1);
	vectorTest(a,1);

	a={2};
	vectorTest(a,2);
	vectorTest(a,1);
	vectorTest(a,3);

	a={};
	vectorTest(a,1);
}

int main(){
	test();
	return 0;
}
