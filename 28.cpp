#include <iostream>
#include <vector>
#include <string>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
}
using namespace std;
int strStr(string haystack, string needle) {
	int m = haystack.length(), n = needle.length();
	if (!n) return 0;
	for (int i = 0; i < m - n + 1; i++) {
		int j = 0;
		for (; j < n; j++)
			if (haystack[i + j] != needle[j])
				break;
		if (j == n) return i;
	}
	return -1;
}

int main(){

	return 0;
}
