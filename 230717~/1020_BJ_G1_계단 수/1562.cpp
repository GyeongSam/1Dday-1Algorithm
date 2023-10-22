#include <iostream>
#include <vector>

using namespace std;

const int modC = 1e9;
const int allNumber = (1 << 10) - 1;
int N;

int dfs(int n, int now, int check, vector<vector<vector<int>>>& dp) {
	int& ref = dp[n][now][check];
	if (ref != -1) return ref;
	if (n == N) {
		return ref = ((check == allNumber) ? 1 : 0);
	}
	ref = 0;
	if (now != 0)
		ref += dfs(n + 1, now - 1, check | (1 << (now - 1)), dp);
	
	if (now != 9)
		ref += dfs(n + 1, now + 1, check | (1 << (now + 1)), dp);
	return ref%= modC;
}


int main() {
	cin >> N;
	vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
	int answer = 0;

	for (int i = 1; i < 10; ++i) {
		answer += dfs(1, i, 1 << i, dp);
		answer%= modC;
	}
	cout << answer;
}