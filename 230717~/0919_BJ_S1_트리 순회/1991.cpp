#include <iostream>
#include <vector>
using namespace std;


void dfs(int node, const vector<vector<int>>& grp, vector<vector<char>>& answer) {
	answer[0].push_back(node);
	if (grp[node][0] != 0) dfs(grp[node][0],grp,answer);
	answer[1].push_back(node);
	if (grp[node][1] != 0) dfs(grp[node][1],grp,answer);
	answer[2].push_back(node);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<vector<int>> grp(100,vector<int>(2));
	vector<vector<char>> answer(3);
	int N;
	cin >> N;
	while (N--) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') grp[a][0] = b;
		if (c != '.') grp[a][1] = c;
	}
	dfs('A', grp, answer);
	for (vector<char>& str : answer) {
		for (char c : str) cout << c;
		cout << "\n";
	}
}