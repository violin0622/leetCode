#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

vector<int>& nextPermutation(vector<int> &nums){
	int i = nums.size()-1;
	while(i>=0 && nums[i] <= nums[i-1]) i--;
	if(i>0){
		unsigned j=i;
		while(j<nums.size() && nums[j]>nums[i-1]) j++;
		j--;
		int tmp = nums[j];
		nums[j] = nums[i-1];
		nums[i-1] = tmp;
	}
	sort(nums.begin()+i, nums.end());
	return nums;
}

void test(){
	vector<int> a;
	cout << "{0,0,0,0}        " ;
	 a = nextPermutation(vector<int>()={0,0,0,0});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1,1,1,1}        ";
	a =  nextPermutation(vector<int>()={1,1,1,1});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1,2,3,3,2,1}    ";
	a = nextPermutation(vector<int>()={1,2,3,3,2,1});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{3,2,1,1,2,3}    ";
	a = nextPermutation(vector<int>()={3,2,1,1,2,3});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1,2,3,4,5,6}    ";
	a = nextPermutation(vector<int>()={1,2,3,4,5,6});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{6,5,4,3,2,1}    ";
	a = nextPermutation(vector<int>()={6,5,4,3,2,1});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1,2,4,5,6,2,1}  ";
	a = nextPermutation(vector<int>()={1,2,4,5,6,2,1});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1}              ";
	a = nextPermutation(vector<int>()={1});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "null             ";
	a = nextPermutation(vector<int>()={});
	for(int i : a) cout << i << " ";
	cout << endl;
	cout << "{1,2,3}          ";
	a = nextPermutation(vector<int>()={1,3,2});
	for(int i : a) cout << i << " ";
	cout << endl;
}

int main(){
	test();
	return 0;
}
