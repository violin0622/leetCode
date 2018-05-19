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
#include <map>
using namespace std;

/* 解法1：暴力解法。（超时）
 * 列出其每一个子串，并判断其是否为无重复字符。找出其中最长的。
 * 时间复杂度： O(n^3)
 */
bool isUnique(string &s, unsigned i, unsigned j){
	set<char> charset(s.begin()+i,s.begin()+j);
	return charset.size() == j-i;
}

int bruteForce(string s){
	unsigned max = 0;
	for(unsigned i=0; i<s.size(); i++){
		for(unsigned j=i+1; j<=s.size(); j++){
			if(isUnique(s,i,j)){
				max = j-i > max ? j-i : max;
			}
		}
	}
	return max;
}


/* 解法2: 窗口法。
 * 判断窗口内字符串是否有重复:
 * 若无，则向右扩展窗口;
 * 若有，则将窗口左边界移动到重复字符的右侧。
 * 窗口法的本质即是双指针法。
 * 时间复杂度： O(2n)
 */
int slideWindow(string s){
	unsigned max = 0;
	for(unsigned l=0,r=1; r<=s.size();r++){
		if(isUnique(s, l, r)){
			max = r-l > max ? r-l : max;
		}else{
			while(s[l++] != s[r-1]);
		}
	}
	return max;
}

/* 解法3：窗口法优化。
 * 逻辑与解法2相同，但不使用Set保存窗口内的字符
 * 而是用map同时保存字符和其位置。
 * 避免了发现重复字符时的循环从而提升速度。
 * 这是一种简单的 value->index 的倒排索引应用。
 * 时间复杂度：O(n)
 */
int slideWindowOptmized(string s){
	unsigned max=0;
	map<char, unsigned> chars;
	for(unsigned l=0,r=0; r<s.size(); r++){
		if(chars.find(s[r]) == chars.end() || chars[s[r]] < l){
			chars[s[r]] = r;
			max = r-l+1 > max ? r-l+1 : max;
		}else{
			l = 1 + chars[s[r]];
			chars[s[r]] = r;
		}
	}
	return max;
}

int main(){
	int (*func)(string);

	func = slideWindowOptmized;

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

