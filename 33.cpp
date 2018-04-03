#include <iostream>
#include <vector>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

int search(vector<int> &nums, int target){
	if(nums.size() == 0) return -1;
	int L = 0, R = nums.size()-1, M = (L+R)/2;
	int tail = nums[nums.size()-1];
	while(L<=R){
		M = (L+R)/2;
		if(target < tail){
			if(nums[M] > tail){
				L = M+1;
			}else{
				if(nums[M] < target) L = M+1;
				else if(nums[M] > target) R = M-1;
				else return M;
			}
		}else if(target > tail){
			if(nums[M] < tail){
				R = M-1;
			}else{
				if(nums[M] > target) R = M-1;
				else if(nums[M] < target) L = M+1;
				else return M;
			}
		}else{
			return nums.size()-1;
		}
	}
	return -1;
}

void vectorTest(vector<int> &nums, int tar){
	int (*foo)(vector<int>&, int) = search;
	cout << "{";
	for(int i : nums) cout << i << " ";
	cout << "}";
	for(unsigned i=0; i<20-nums.size()*2; i++) cout << " ";
	cout << "target:" << tar << " " << (*foo)(nums, tar) << endl;
}
void test(){
	vector<int> a;
	a={1,2,3,4,5,6,7,8};
	vectorTest(a, 1);
	vectorTest(a, 3);
	vectorTest(a, 8);
	vectorTest(a, 9);

	a={4,5,6,7,8,1,2,3};
	vectorTest(a, 1);
	vectorTest(a, 3);
	vectorTest(a, 8);
	vectorTest(a, 9);

	a={};
	vectorTest(a,3);

	a={1,5};
	vectorTest(a,3);
	vectorTest(a,1);
	vectorTest(a,5);
	vectorTest(a,6);

	a={5,1};
	vectorTest(a,3);
	vectorTest(a,1);
	vectorTest(a,5);
	vectorTest(a,6);

	a={4};
	vectorTest(a,3);
	vectorTest(a,4);
	vectorTest(a,6);
}

int main(){
	test();
	return 0;
}
