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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	
	vector<vector<edge>> grp(N+1);
	while (M--) {
		int s, e, d;
		cin >> s >> e >> d;
		grp[s].push_back(edge(e, d));
		grp[e].push_back(edge(s, d));
	}
	long long total = 0;
	int maxD = 0;

	vector<bool> visit(N + 1);
	priority_queue<edge> pq;
	pq.push(edge(1, 0));
	
	while (!pq.empty()) {
		edge now(pq.top());
		pq.pop();
		if (visit[now.to]) continue;
		total += now.dist;
		if (maxD < now.dist) maxD = now.dist;
		visit[now.to] = true;
		for (edge& e : grp[now.to]) {
			if (visit[e.to]) continue;
			pq.push(e);
		}
	}
	cout << total - maxD;
}