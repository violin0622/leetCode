#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
	if(nums.size() <= 3)
		return nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for(int i : nums) printf("%d ", i);
	printf("\n");
	int L=0,M=L+1,R=nums.size()-1;
	int closest = nums[L] + nums[M] + nums[R];
	for(L=0;L<R;L++){
		M=L+1,R=nums.size()-1;
		int sum = nums[L] + nums[M] + nums[R];
		if(abs(sum-target) < abs(closest-target)) closest = sum;
		sum < target ? M++ : R--;
	}
	return closest;
}
int main(){
	vector<int> nums{0,2,1,-3};
	cout << threeSumClosest(nums, 100);
}
