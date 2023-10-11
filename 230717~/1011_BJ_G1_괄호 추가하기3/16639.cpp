#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int INF = (1 << 29);
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }
int MinDfs(int, int, const string&, vector<vector<vector<int>>>&);
int MaxDfs(int l, int r, const string& exp, vector<vector<vector<int>>>& dp) {
	if (dp[l][r][1] != -INF) return dp[l][r][1];
	if (l == r) return exp[l] - '0';
	for (int m = l; m < r; ++m) {
		if (m % 2) {
			if (exp[m] == '+') {
				dp[l][r][1] = max(dp[l][r][1], MaxDfs(l, m - 1, exp, dp) + MaxDfs(m + 1, r, exp, dp));
			}
			else if (exp[m] == '-') {
				dp[l][r][1] = max(dp[l][r][1], MaxDfs(l, m - 1, exp, dp) - MinDfs(m + 1, r, exp, dp));
			}
			else {
				dp[l][r][1] = max(dp[l][r][1], MaxDfs(l, m - 1, exp, dp) * MaxDfs(m + 1, r, exp, dp));
				dp[l][r][1] = max(dp[l][r][1], MinDfs(l, m - 1, exp, dp) * MinDfs(m + 1, r, exp, dp));
				dp[l][r][1] = max(dp[l][r][1], MaxDfs(l, m - 1, exp, dp) * MinDfs(m + 1, r, exp, dp));
				dp[l][r][1] = max(dp[l][r][1], MinDfs(l, m - 1, exp, dp) * MaxDfs(m + 1, r, exp, dp));
			}
		}
	}
	return dp[l][r][1];
}
int MinDfs(int l, int r, const string& exp, vector<vector<vector<int>>>& dp) {
	if (dp[l][r][0] != INF) return dp[l][r][0];
	if (l == r) return exp[l] - '0';
	for (int m = l; m < r; ++m) {
		if (m % 2) {
			if (exp[m] == '+') {
				dp[l][r][0] = min(dp[l][r][0], MinDfs(l, m - 1, exp, dp) + MinDfs(m + 1, r, exp, dp));
			}
			else if (exp[m] == '-') {
				dp[l][r][0] = min(dp[l][r][0], MinDfs(l, m - 1, exp, dp) - MaxDfs(m + 1, r, exp, dp));
			}
			else {
				dp[l][r][0] = min(dp[l][r][0], MinDfs(l, m - 1, exp, dp) * MinDfs(m + 1, r, exp, dp));
				dp[l][r][0] = min(dp[l][r][0], MaxDfs(l, m - 1, exp, dp) * MaxDfs(m + 1, r, exp, dp));
				dp[l][r][0] = min(dp[l][r][0], MinDfs(l, m - 1, exp, dp) * MaxDfs(m + 1, r, exp, dp));
				dp[l][r][0] = min(dp[l][r][0], MaxDfs(l, m - 1, exp, dp) * MinDfs(m + 1, r, exp, dp));
			}
		}
	}
	return dp[l][r][0];
}

int main() {
	int N;
	string exp;
	cin >> N >> exp;
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, { INF, -INF }));
	cout << MaxDfs(0, exp.size() - 1, exp, dp);

}