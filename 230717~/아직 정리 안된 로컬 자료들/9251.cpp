#include <iostream>
#include <string>
#include <vector>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string seq1, seq2;
	cin >> seq1 >> seq2;
	int N = seq1.length();
	int M = seq2.length();
	vector<vector<int>> dp(N+1, vector<int>(M+1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			if (seq1[i-1] == seq2[j-1]) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
			}
		}
	}
	cout << dp[N][M];

}