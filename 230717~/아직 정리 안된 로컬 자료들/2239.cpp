#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool flag=false;
void dfs(int i, int j, vector<string>& board, vector<int>&checkRaw, vector<int>& checkCol, vector<vector<int>>& checkBox) {
	if (flag) return;
	if (j > 8) {
		i++; j = 0;
	}
	if (i > 8) {
		flag = true;
		for (string& w : board) cout << w << "\n";
		return;
	}
	if (board[i][j] != '0') {
		dfs(i, j+1, board, checkRaw, checkCol, checkBox);
	}
	else {
		for (int n = 1; n <= 9; n++) {
			int num = 1 << n;
			if (((checkRaw[i] & num)!=0) || ((checkCol[j] & num)!=0) || ((checkBox[i / 3][j / 3] & num)!=0)) continue;
			board[i][j] = '0' + n;
			checkRaw[i] |= num;
			checkCol[j] |= num;
			checkBox[i / 3][j / 3] |= num;
			dfs(i, j+1, board, checkRaw, checkCol, checkBox);
			board[i][j] = '0';
			checkRaw[i] &= (~num);
			checkCol[j] &= (~num);
			checkBox[i / 3][j / 3] &= (~num);
		}
	}
}

int main() {
	vector<string> board(9);
	for (int i = 0; i < 9; ++i) cin >> board[i];

	vector <int> checkRaw(9);
	vector <int> checkCol(9);
	vector <vector<int>> checkBox(3, vector<int>(3));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] == '0') continue;
			int x = (1 << (board[i][j] - '0'));
			checkRaw[i] |= x;
			checkCol[j] |= x;
			checkBox[i / 3][j / 3] |= x;
		}
	}
	dfs(0, 0, board, checkRaw, checkCol, checkBox);
}