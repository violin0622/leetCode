#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target){
	vector<vector<int> > result = {};
	if(nums.size()<4) return result;
	sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size()-3; i++){
		for(int j=i+1; j<nums.size()-2; j++){
			int k=j+1,l=nums.size()-1;
			while(k<l){
				int sum = nums[i] + nums[j] + nums[k] + nums[l];
				if(sum < target) k++;
				else if(sum > target) l--;
				else{
					result.push_back(vector<int>() = {nums[i], nums[j], nums[k], nums[l]});
					while(k<l && nums[k] == nums[k+1]) k++;
					while(k<l && nums[l] == nums[l-1]) l--;
					k++,l--;
				}
			}
			while(j<nums.size()-2 && nums[j] == nums[j+1]) j++;
		}
		while(i<nums.size()-3 && nums[i] == nums[i+1]) i++;
	}
	return result;
}
int main(){
	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;
	vector<vector<int> >result = fourSum(nums, target);
	for(vector<int> v : result){
		for(int i : v) cout << i << " ";
		cout << endl;
	}

	return 0;
}
