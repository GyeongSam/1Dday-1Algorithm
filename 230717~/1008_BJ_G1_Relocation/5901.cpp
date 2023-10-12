#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct edge {
	int to, cost;
	edge() {}
	edge(int t,int c):to(t),cost(c){}
	bool operator<(const edge& other) const {
		return cost > other.cost;
	}
};

void dkstr(const int start, vector<int>& dp, const vector<vector<edge>> grp) {
	priority_queue<edge> pq;
	dp[start] = 0;
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

void dfs(int start, int from, int visit, int cost, const vector<int>& marketList, const vector<vector<int>>& minDistToMarketList, vector<vector<int>>& dp) {
	if (visit == ((1 << marketList.size()) - 1)) {
		dp[start][from] = min(dp[start][from],cost);
		return;
	}
	for (int i = 0; i < marketList.size(); ++i) {
		if ((visit & (1 << i)) != 0) continue;
		dfs(start, i, visit | (1 << i), cost + minDistToMarketList[from][marketList[i]], marketList,minDistToMarketList, dp);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	const int INF = 1 << 29;
	int N, M, K,answer=INF;
	cin >> N>> M>> K;
	vector<vector<edge>> grp(N + 1);
	vector<vector<int>> minDistToMarketList(K,vector<int>(N+1,INF));
	vector<int> marketList(K);
	vector<bool> isMarket(N + 1);
	for (int k = 0; k < K; ++k) {
		cin >> marketList[k];
		isMarket[marketList[k]] = true;
	}
	while (M--) {
		int s, e, c;
		cin >> s >> e >> c;
		grp[s].push_back(edge(e, c));
		grp[e].push_back(edge(s, c));
	}

	for (int k = 0; k < K; ++k) {
		dkstr(marketList[k], minDistToMarketList[k], grp);
	}
	vector<vector<int>> dp(K, vector<int>(K, INF));

	for (int i = 0; i < K; ++i) {
		dfs(i, i, 1 << i, 0, marketList, minDistToMarketList, dp);
	}


	for (int n = 1; n <= N; ++n) {
		if (isMarket[n]) continue;
		for (int sm = 0; sm < K; ++sm) {
			for (int em = 0; em < K; ++em) {
				if (sm == em) continue;
				int totalCost = minDistToMarketList[sm][n] + dp[sm][em] + minDistToMarketList[em][n];
				//cout << n << "출발" << sm << "경유" << em << "도착복귀 : " << totalCost << "\n";
				if (totalCost < answer) answer = totalCost;
			}
		}
	}
	cout << answer;
}