#include <iostream>
#include <vector>

using namespace std;

const int INF = -(1 << 29);
int N;
int max(int a, int b) {
	return a > b ? a : b;
}

int dfs(int n, int gap, vector<vector<int>>&dp, const vector<int>& blockList) {
	int& ret = dp[n][gap];
	if (ret != -1) return ret;
	if (n == N) {
		return ret = (gap == 0 ? 0 : INF);
	}
	ret = INF;
	if (blockList[n] > gap) {
		ret = max(ret, dfs(n + 1, blockList[n] - gap, dp, blockList) + gap);
	}
	else {
		ret = max(ret, dfs(n + 1, gap - blockList[n], dp, blockList) + blockList[n]);
	}
	ret = max(ret, dfs(n + 1, gap + blockList[n], dp, blockList));
	ret = max(ret, dfs(n + 1, gap, dp, blockList));
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	vector<int> blockList(N);
	vector<vector<int>> dp(N+1, vector<int>(500001,-1));
	for (int i = 0; i < N; ++i) cin >> blockList[i];
	int answer = dfs(0, 0, dp, blockList);
	if (answer == 0) answer = -1;
	cout << answer;
}

//https://www.acmicpc.net/problem/1126