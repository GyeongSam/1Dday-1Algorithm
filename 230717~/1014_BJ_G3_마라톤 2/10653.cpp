#include <iostream>
#include <vector>

using namespace std;

struct CheckPoint {
	int x, y;
	CheckPoint(){}
	CheckPoint(int _x, int _y):x(_x),y(_y){}
};
int min(int a, int b) {
	return a > b ? b : a;
}
int GetDist(const CheckPoint& a, const CheckPoint& b) {
	return (a.x > b.x ? a.x - b.x : b.x - a.x) + (a.y > b.y ? a.y - b.y : b.y - a.y);
}

int dfs(int now, int from, int k, const vector<CheckPoint>& pointList, vector<vector<int>>& dp) {
	if (dp[now][k] != -1) return dp[now][k];
	if (now == pointList.size() - 1) return dp[now][k] = GetDist(pointList[from], pointList[now]);
	dp[now][k] = dfs(now + 1, now+1, k, pointList, dp) + GetDist(pointList[from], pointList[now]);
	if (k+1 < dp[0].size()) dp[now][k] = min(dp[now][k], dfs(now + 1, from, k + 1, pointList, dp));
	return dp[now][k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	const int INF = 1 << 29;
	int N, K;
	cin >> N >> K;
	vector<CheckPoint> pointList(N);
	for (int i = 0; i < N; ++i) {
		cin >> pointList[i].x >> pointList[i].y;
	}
	vector<vector<int>> dp(N, vector<int>(K+1, INF));

	dp[0][0] = 0;
	for (int i = 1; i < N; ++i) {
		for (int k = 0; k <= K; ++k) {
			for (int d = 0; i - 1 - d >= 0 && k - d >= 0;++d ) {
				dp[i][k] = min(dp[i][k], dp[i - 1 - d][k - d] + GetDist(pointList[i - 1-d], pointList[i]));
			}
		}
	}
	int answer = dp[N - 1][K];
	for (int k = 0; k < K; ++k) answer = min(answer, dp[N - 1][k]);
	cout << answer;
}