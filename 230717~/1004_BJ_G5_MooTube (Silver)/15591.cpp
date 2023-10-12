#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to, cost;
	Edge(){}
	Edge(int t,int c):to(t),cost(c){}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, Q;
	cin >> N >> Q;
	
	const int INF = 1 << 29;
	vector<vector<Edge>> grp(N + 1);
	
	for (int i = 1; i < N; ++i) {
		int p, q, r;
		cin >> p >> q >> r;
		grp[p].push_back(Edge(q, r));
		grp[q].push_back(Edge(p, r));
	}
	vector<bool> visit;
	while (Q--) {
		int k, v, cnt=0;
		cin >> k >> v;
		queue<int> q;
		visit.clear();
		visit.resize(N + 1, false);
		visit[v] = true;
		q.push(v);
		
		while (!q.empty()) {
			int now(q.front());
			q.pop();
			for (const Edge& next : grp[now]) {
				if (visit[next.to] || next.cost < k) continue;
				visit[next.to] = true;
				q.push(next.to);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}



}