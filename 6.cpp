#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

vector<vector<char> > initArray(int line, int row){
	vector<vector<char> > mtx(line);
	for(int i=0; i<line; i++)
		mtx[i].resize(row);

	for(int i=0; i<line; i++)
		for(int j=0; j<row; j++)
			mtx[i][j] = '.';
	return mtx;
}

void printMtx(const vector<vector<char> > &a){
	for(vector<char> v : a){
		for(char c : v)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
}

string convert(string s, int numRows){
	int row = s.size();
	int line = numRows;
	vector<vector<char> > mtx = initArray(line, row);
	int i=0,j=0,idx=0;
	while(idx<s.size()){
	while(i<line && idx<s.size())
		mtx[i++][j] = s[idx++];
	i--;
	while(i>1 && idx<s.size())
		mtx[--i][++j] = s[idx++];
	i--,j++;
	}

	string r;
	for(vector<char> v : mtx)
		for(char c : v)
			if(c != '.')
				r += c;
	return r;
}

int main(){

	cout << convert("PAYPALISHIRING", 3);
	return 0;
}
