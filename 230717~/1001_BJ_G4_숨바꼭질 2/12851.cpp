#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, K, cnt=1;
	cin >> N >> K;
	const int MAX = 200001;
	vector<int> dp(MAX,MAX);
	queue<int> q;
	q.push(N);
	dp[N] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == K) break;
		if (now>0&&dp[now - 1]>dp[now]) {
			dp[now - 1] = dp[now] + 1;
			q.push(now - 1);
		}
		if (now<100000&& dp[now +1]>dp[now]) {
			dp[now + 1] = dp[now] + 1;
			q.push(now + 1);
		}
		if (now<100000&& dp[now*2]>dp[now]) {
			dp[2 * now] = dp[now] + 1;
			q.push(2 * now);
		}
	}
	
	while (!q.empty() && dp[q.front()] == dp[K]) {
		if (q.front() == K) cnt++;
		q.pop();
	}
	cout << dp[K] << "\n" << cnt;
}