#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs){
	string r="";
	bool flag=true;
	if(!strs.size()) return "";
	if(1==strs.size()) return strs[0];
	int m=strs.size(), n=strs[0].size();
	for(int i=0; i<m; i++)
		n = min(n, (int)strs[i].size());

	printf("%d %d\n", m, n);
	for(int i=0; i<n; i++,flag=true){
		for(int j=0; j<m; j++)
			if(strs[j][i] != strs[0][i]){printf("s"); flag = false;}
		if(flag) r += strs[0][i];
		else break;
	}
	return r;
}

int main(){
	vector<string> strs = {"aca","cba"};
	cout << longestCommonPrefix(strs);
	return 0;
}
