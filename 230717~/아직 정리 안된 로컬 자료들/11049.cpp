#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 30;

int min(int a, int b) {
	return a > b ? b : a;
}

int dfs(int s,int e, vector <vector<int>>&matrixts, vector<vector<int>> &dp) {
	if (dp[s][e] != INF) return dp[s][e];
	if (s == e) return 0;
	for (int m = s; m < e; ++m) {
		dp[s][e] = min(dp[s][e], dfs(s, m, matrixts, dp) + dfs(m + 1, e, matrixts, dp)+ matrixts[s][0] * matrixts[m][1] * matrixts[e][1]);
	}
	return dp[s][e];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector <vector<int>> matrixs(N,vector<int>(2));
	vector <vector<int>> dp(N,vector<int>(N,INF));
	for (int i = 0; i < N; ++i) {
		cin >> matrixs[i][0] >> matrixs[i][1];
	}
	cout << dfs(0, N - 1, matrixs, dp);
}