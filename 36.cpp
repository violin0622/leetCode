#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// check every row, every line, every matrix
// if there is duplicated char

bool check(const vector<char> & set){
	bool valid = true;
	int bitmap[10] = {0};
	for( char c : set){
		if(c == '.')
			continue;
		int num = c - '0';
		if(bitmap[num] == 1){
			valid = false;
			break;
		}
		bitmap[num] = 1;
	}
	return valid;
}

bool isValidSudoku(vector<vector<char>>& board){
	bool isValid = true;
	for(vector<char> v : board)
		if(! check(v))
			return false;

	vector<char> column = {};
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			column.push_back(board[j][i]);
		}
		if(! check(column))
			return false;
		column = {};
	}

	for(int i=0; i<9; i+=3)
		for (int j=0; j<9; j+=3){
			for(int r=i; r<i+3; r++)
				for(int c=j; c<j+3; c++){
					printf("%d %d %d %d \n", i,j,r,c);
					column.push_back(board[r][c]);
				}
			for(char c: column) cout << c;
			if(! check(column))
				return false;
			column = {};
			cout << "vector initialed\n";
		}
	return true;
}


void test(){
	vector<vector<char>> matrix = { {'.','.','.','.','5','.','.','1','.'},
									{'.','4','.','3','.','.','.','.','.'},
									{'.','.','.','.','.','3','.','.','1'},
									{'8','.','.','.','.','.','.','2','.'},
									{'.','.','2','.','7','.','.','.','.'},
									{'.','1','5','.','.','.','.','.','.'},
									{'.','.','.','.','.','2','.','.','.'},
									{'.','2','.','9','.','.','.','.','.'},
									{'.','.','4','.','.','.','.','.','.'} };
	cout << isValidSudoku(matrix);

}

int main(){
	test();
	return 0;
}
