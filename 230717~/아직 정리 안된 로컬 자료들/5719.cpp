#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int to, dist;
	edge(int t, int d) :to(t), dist(d) {}
	bool operator<(const edge& other) const {
		return other.dist < dist;
	}
};
void dkstra(int node, vector<int>& dp,const vector<vector<edge>>& grp) {
	
	priority_queue<edge> pq;
	pq.push(edge(node, 0));
	dp[node] = 0;
	while (!pq.empty()) {
		edge now(pq.top());
		pq.pop();
		for (const edge& next : grp[now.to]) {
			if (dp[next.to] > dp[now.to] + next.dist) {
				dp[next.to] = dp[now.to] + next.dist;
				pq.push(next);
			}
		}
	}
}
int main() {
	int N, M;
	const int INF = 1 << 28;
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		int start, end;
		cin >> start >> end;
		vector<vector<edge>> grp(N);
		vector<vector<edge>> reverse_grp(N);
		while (M--) {
			int s, e, d;
			cin >> s >> e >> d;
			grp[s].push_back(edge(e, d));
			reverse_grp[e].push_back(edge(s, d));
		}
		vector<int> startToAll(N,INF);
		vector<int> allToEnd(N,INF);
		dkstra(start, startToAll, grp);
		dkstra(end, allToEnd, reverse_grp);
		int minDist = startToAll[end];
		vector<int> almostCloseDist(N, INF);
		for (int i = 0; i < N; ++i) {
			for (edge& e : grp[i]) {
				if (startToAll[i] + e.dist + allToEnd[e.to] == minDist) e.dist = INF;
			}
		}
		dkstra(start, almostCloseDist, grp);
		if (almostCloseDist[end] == INF) printf("-1\n");
		else printf("%d\n",almostCloseDist[end]);
	}

}