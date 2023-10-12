#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
	int to, cost;
	Edge(){}
	Edge(int t, int c):to(t),cost(c){}
	bool operator<(const Edge& other) const {
		return cost > other.cost;
	}
};

int main() {
	int T;
	cin >> T;
	const int INF = 1 << 29;
	while (T--) {
		int V, E, target;
		cin >> V >> E >> target;
		vector<vector<Edge>> grp(V + 1);
		while (E--) {
			int e, s, c;
			cin >> e >> s >> c;
			grp[s].push_back(Edge(e, c));
		}
		vector<int> dp(V + 1, INF);
		dp[target] = 0;
		priority_queue<Edge> pq;
		pq.push(Edge(target, 0));

		while (!pq.empty()) {
			Edge now(pq.top());
			pq.pop();
			for (const Edge& next : grp[now.to]) {
				if (dp[next.to] > dp[now.to] + next.cost) {
					dp[next.to] = dp[now.to] + next.cost;
					pq.push(Edge(next.to, dp[next.to]));
				}
			}
		}
		int cnt=0, max=0;
		for (int cost : dp) {
			if (cost != INF) {
				cnt++;
				if (cost > max) max = cost;
			}
			
		}
		cout << cnt << " " << max << "\n";
	}
}