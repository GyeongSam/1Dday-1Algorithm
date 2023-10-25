#include <iostream>
#include <vector>

using namespace std;

int id = 1;
const int INF = 1 << 29;
int min(int a, int b) {
	return a > b ? b : a;
}
int dfs(int now, vector<int>& nodeId, vector<bool>& answer, vector<int>& childCnt, const vector<vector<int>>& grp) {
	nodeId[now] = id;
	id++;
	int neerLowId = INF;
	for (int next : grp[now]) {
		if (nodeId[next] != 0) {
			neerLowId = min(neerLowId, nodeId[next]);
			continue;
		}
		int neerId = dfs(next, nodeId, answer, childCnt, grp);
		childCnt[now]++;
		if (neerId >= nodeId[now]) {
			answer[now] = true;
		}
		neerLowId = min(neerLowId, neerId);
	}
	return neerLowId;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int V, E;
	cin >> V >> E;
	vector<vector<int>> grp(V + 1);
	vector<int> nodeId(V + 1);
	vector<int> childCnt(V + 1);
	vector<bool> answer(V+1);
	while (E--) {
		int s, e;
		cin >> s >> e;
		grp[s].push_back(e);
		grp[e].push_back(s);
	}
	for (int i = 1; i <= V; ++i) {
		if (nodeId[i] != 0) continue;
		dfs(i, nodeId, answer, childCnt, grp);
		if (childCnt[i] >= 2) answer[i] = true;
		else answer[i] = false;
	}
	vector<int> ans;

	for (int i = 1; i <= V; ++i) {
		if (answer[i]) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
}