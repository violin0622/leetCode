/*
 * leetCode 3 : Longest Substring Without Repeating Characters
 * 
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * "abcabcbb" --> "abc" 3
 * "bbbbb"    --> "b" 1
 * "pwwkew"   --> "wke" 3
 */


#include <iostream>
#include <set>
#include <vector>
using namespace std;

/* 解法1：暴力解法。（超时）
 * 列出其每一个子串，并判断其是否为无重复字符。找出其中最长的。
 */

bool isUnique(string &s, int i, int j){
	set<char> charset(s.begin()+i,s.begin()+j);
	return charset.size() == j-i;
}

int bruteForce(string s){
	if(s.size()==0) return 0;
	int max = 0;
	for(int i=0; i<s.size(); i++){
		for(int j=i+1; j<=s.size(); j++){
			if(isUnique(s,i,j)){
				max = j-i > max ? j-i : max;
			}
		}
	}
	return max;
}

int main(){
	int (*func)(string);

	func = bruteForce;

	vector<string> testcase = {
		"", 
		"c",
		"abcabcbb",
	   	"bbbbb",
	   	"pwwkew"
	};
	for(string tc : testcase){
		cout << func(tc) << endl;
	}
}

