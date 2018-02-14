#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> combine(string subDigit, const vector<vector<char> > &dict){
	vector<string> result;
	int num = stoi(string(subDigit, 0, 1));
	if(subDigit.size() == 1){
		for(char i : dict[num])
			result.push_back(string(1,i));
	}else{
		vector<string> tmp = combine(string(subDigit.begin()+1, subDigit.end()), dict);
		for(string s : tmp)
			for(char i : dict[num])
				result.push_back(string(s).insert(0,1,i));
	}
	return result;
}
vector<string> letterCombinations(string digits){
	vector<string> result;
	if(digits.size() == 0){
		result = {};
		return result;
	}

	for(int i=0; i<digits.size(); i++){
		if(digits[i] == '1'){
			digits.erase(i,1);
			i--;
		}
	}
	vector<vector<char> > dict(10);
    dict = { {' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, 
			 {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
			 {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'} };
	return combine(digits, dict);
}

int main(){
	vector<string> result = letterCombinations("1211131");
	for(string s : result)
		cout << s << endl;
	return 0;
}
