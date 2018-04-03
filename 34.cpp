#include <iostream>
#include <vector>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

vector<int> searchRange(vector<int> & nums, int target){
	vector<int> result = {-1,-1};
	if(nums.size()==0) return result;
	int L=0, R=nums.size()-1, M=(L+R)/2;
	while(L<=R){
		M = (L+R)/2;
		if(nums[M] < target) L = M+1;
		else if(nums[M] > target) R = M-1;
		else{
			int i=M;
			while(i>0 && nums[i-1]==nums[M]) i--;
			result[0] = i;
			i=M;
			while(i<nums.size()-1 && nums[i+1]==nums[M]) i++;
			result[1] = i;
			break;
		}
	}
	return result;
}

void vectorTest(vector<int> &nums, int tar){
	vector<int> (*foo)(vector<int>&, int) = searchRange;
	cout << "{";
	for(int i : nums) cout << i << " ";
	cout << "}";
	for(int i=0; i<40-nums.size()*2; i++) cout << " ";
	cout << "target " << tar << " ";
	vector<int> a = (*foo)(nums, tar);
	for(int i : a) cout << " " << i;
	cout << endl;
}
void test(){
	vector<int> a;
	a={0,0,0,0,0};
	vectorTest(a,0);
	vectorTest(a,4);
	vectorTest(a,-1);

	a={0,0,1,1,1,3,5,6};
	vectorTest(a,0);
	vectorTest(a,1);
	vectorTest(a,5);
	vectorTest(a,9);

	a={};
	vectorTest(a,0);

	a={1};
	vectorTest(a,1);
	vectorTest(a,0);
	vectorTest(a,2);

	a={0,1,1,1,1,1,2};
	vectorTest(a,1);
}

int main(){
	test();
	return 0;
}
