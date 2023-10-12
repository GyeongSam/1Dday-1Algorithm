#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
	int to, cost;
	edge(){}
	edge(int t,int c):to(t),cost(c){}
	bool operator<(const edge& other) const {
		return other.cost < cost;
	}
};

void dkstra(int start, vector<int>& dp, const vector<vector<edge>>& grp) {
	dp[start] = 0;
	priority_queue<edge> pq;
	pq.push(edge(start, 0));
	while (!pq.empty()) {
		edge now(pq.top());
		pq.pop();
		for (const edge& next : grp[now.to]) {
			if (dp[next.to] > dp[now.to] + next.cost) {
				dp[next.to] = dp[now.to] + next.cost;
				pq.push(next);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	const int INF = 1 << 29;
	while (T--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		vector<vector<edge>> grp(n+1);
		vector<int> candiGoal(t);
		while (m--) {
			int s, e, c;
			cin >> s >> e >> c;
			grp[s].emplace_back(e, c);
			grp[e].emplace_back(s, c);
		}
		for (int i = 0; i < t; ++i) cin >> candiGoal[i];

		vector<int> baseToAll(n + 1,INF);
		vector<int> gToAll(n + 1,INF);
		vector<int> hToAll(n + 1, INF);
		dkstra(s, baseToAll, grp);
		dkstra(g, gToAll, grp);
		dkstra(h, hToAll, grp);

		vector<int> answer;
		for (int goal : candiGoal) {
			if (baseToAll[goal] == baseToAll[g] + gToAll[h] + hToAll[goal] || baseToAll[goal] == baseToAll[h] + hToAll[g] + gToAll[goal]) {
				answer.push_back(goal);
			}
		}
		sort(answer.begin(), answer.end());
		for (int goal : answer) cout << goal << " ";
		cout << "\n";

	}
	
}