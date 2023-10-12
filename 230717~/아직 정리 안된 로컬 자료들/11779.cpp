#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int to;
	long long dist;
	edge(){}
	edge(int t,long long d): to(t),dist(d){}
	bool operator< (const edge& other) const {
		return other.dist < dist;
	}
};


void dst(int now, int end, vector<long long>& dp, const vector<vector<edge>>& grp) {
	priority_queue<edge> pq;
	pq.push(edge(now, 0));
	dp[now] = 0;
	while (!pq.empty()) {
		edge now(pq.top());
		if (now.to == end) break;
		pq.pop();
		for (const edge& next : grp[now.to]) {
			if (dp[next.to] > dp[now.to] + next.dist) {
				dp[next.to] = dp[now.to] + next.dist;
				pq.push(edge(next.to,dp[next.to]));
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	const long long INF = (long long)1 << 62;
	vector<vector<edge>> grp(n + 1), rvsGrp(n + 1);
	while (m--) {
		int s, e, d;
		cin >> s >> e >> d;
		grp[s].push_back(edge(e, d));
		rvsGrp[e].push_back(edge(s, d));
	}
	int start, end;
	cin >> start >> end;
	vector<long long> startToAll(n + 1, INF);
	dst(start, end, startToAll, grp);
	
	long long minDist = startToAll[end];
	cout << minDist << "\n";
	vector<int> answer(1,end);
	while (start != end) {

		for (const edge& next : rvsGrp[end]) {
			if (next.dist + startToAll[next.to] == minDist) {
				end = next.to;
				minDist -= next.dist;
				answer.push_back(end);
			}
		}
	}

	cout << answer.size() <<"\n";
	for (int i = answer.size() - 1; i >= 0; --i) cout << answer[i] << " ";
}