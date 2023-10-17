#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	const string preAnswer = "Data set ";
	int N;
	cin >> N;
	for (int n=1; n<=N;++n) {
		cout << preAnswer << n << ": ";
		string word1, word2, word3;
		cin >> word1 >> word2 >> word3;
		int s1 = word1.size(), s2 = word2.size();
		vector<vector<bool>> dp(s1+1, vector<bool>(s2+1));
		dp[0][0] = true;
		for (int i = 1; i <= s1; ++i) {
			if (word1[i - 1] == word3[i - 1] && dp[i-1][0]) dp[i][0] = true;
		}
		for (int i = 1; i <= s2; ++i) {
			if (word2[i - 1] == word3[i - 1] && dp[0][i-1]) dp[0][i] = true;
		}
		for (int i = 1; i <= s1; ++i) {
			for (int j = 1; j <= s2; ++j) {
				if (dp[i][j-1] && word2[j - 1] == word3[i + j - 1]) dp[i][j] = true;
				if (dp[i-1][j] && word1[i - 1] == word3[i + j - 1]) dp[i][j] = true;
			}
		}
		cout << (dp[s1][s2] ? "yes\n" : "no\n");
	}
	
}