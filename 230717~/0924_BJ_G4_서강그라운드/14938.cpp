#include<iostream>
#include<vector>
using namespace std;
int min(int a, int b) {
	return a > b? b : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, R,answer=0;
	const int INF = 1 << 29;
	cin >> N >> M >> R;
	vector<int> items(N + 1);
	for (int i = 1; i <= N; ++i) cin >> items[i];
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));
	while (R--) {
		int s, e, l;
		cin >> s >> e >> l;
		dp[s][e] = l;
		dp[e][s] = l;
	}
	for (int m = 1; m <= N; ++m) {
		for (int s = 1; s <= N; ++s) {
			for (int e = 1; e <= N; ++e) {
				if (s == e) {
					dp[s][e] = 0;
					continue;
				}
				dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		int sum = 0;
		for (int j = 1; j <= N; ++j) {
			if (dp[i][j] > M) continue;
			sum += items[j];
		}
		if (sum > answer) answer = sum;
	}
	cout << answer;
}