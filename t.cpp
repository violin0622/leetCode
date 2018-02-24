#include <iostream>
#include <vector>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
using namespace std;

void vectorTest(vector<int> &nums){
	void (*foo)(vector<int>&);
	cout << "{";
	for(int i : nums) cout << i << " ";
	cout << "}";
	for(int i=0; i<40-nums.size()*2; i++) cout << " ";
	(*foo)(nums);
	cout << "{";
	for(int i : nums) cout << i << " ";
	cout << "}" << endl;

}
void test(){
}

int main(){

	return 0;
}
