#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> dp(200001,-1);
	queue <int> q;
	dp[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int now(q.front());
		q.pop();
		if (now == K) break;
		if (now < 100000 && dp[now*2] == -1) {
			dp[now*2] = dp[now] + 1;
			q.push(now * 2);
		}
		if (now < 100000 && dp[now+1]==-1) {
			dp[now + 1] = dp[now] + 1;
			q.push(now + 1);
		}
		if (now > 0 && dp[now-1]==-1) {
			dp[now - 1] = dp[now] + 1;
			q.push(now - 1);
		}
	}
	vector<int> answer(1,K);
	while (answer.back()!=N) {
		int now = answer.back();
		if (dp[now] - 1 == dp[now + 1]) {
			answer.push_back(now + 1);
		}
		else if (dp[now] - 1 == dp[now - 1]) {
			answer.push_back(now - 1);
		}
		else {
			answer.push_back(now / 2);
		}
	}

	cout << dp[K] <<"\n";
	for (int i = answer.size() - 1; i >= 0; --i) {
		cout << answer[i] << " ";
	}

}