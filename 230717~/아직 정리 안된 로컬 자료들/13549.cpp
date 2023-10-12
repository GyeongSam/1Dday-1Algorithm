#include <iostream>
#include <vector>
#include <queue>
#define INF 1<<30
using namespace std;





int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int s, e;
	cin >> s >> e;

	vector<int> dp(200001,INF);
	queue<int> q;
	dp[s] = 0;
	q.push(s);
	if (s != 0) {
		while (s < e) {
			s <<= 1;
			dp[s] = 0;
			q.push(s);
		}
	}
	while (!q.empty()&&dp[e]==INF) {
		int now = q.front();
		q.pop();
		if (now > 0) {
			int next = now - 1;
			if (dp[next]==INF) {
				dp[next] = dp[now] + 1;
				q.push(next);
			}
			if (next != 0) {
				while (next < e) {
					next <<= 1;
					if (dp[next]==INF) {
						dp[next] = dp[now] + 1;
						q.push(next);
					}
				}
			}
		}
		if (now < e) {
			int next = now + 1;
			if (dp[next]==INF) {
				dp[next] = dp[now] + 1;
				q.push(next);
			}
			while (next < e) {
				next <<= 1;
				if (dp[next]==INF) {
					dp[next] = dp[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << dp[e];
}