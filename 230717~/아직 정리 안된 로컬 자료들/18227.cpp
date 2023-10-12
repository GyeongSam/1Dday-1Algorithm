#include <iostream>
#include <vector>
using namespace std;


int nodeID = 0;
struct node {
	int s, e, d;
	node() :s(0), e(0), d(0) {}
};

void dfs(int now, int depth, const vector<vector<int>>& grp, vector<node>& getNodeSE) {

	nodeID++;
	getNodeSE[now].s = nodeID;
	getNodeSE[now].d = depth;
	for (int next : grp[now]) {
		if (getNodeSE[next].s != 0) continue;
		dfs(next, depth+1, grp, getNodeSE);
	}
	getNodeSE[now].e = nodeID;
}


void editSGT(int target, int s, int e, int idx, vector<int>& sgTree) {
	if (s <= target && target <= e){
		sgTree[idx] += 1;
		if (s == e) return;
		int m = (s + e) / 2;
		editSGT(target, s, m, idx << 1, sgTree);
		editSGT(target, m + 1, e, (idx << 1)+1, sgTree);
	}
}
int getSGT(int targetL, int targetR, int s, int e, int idx, const vector<int>& sgTree) {
	if (targetL <= s && e <= targetR) return sgTree[idx];
	if (targetR < s || e < targetL) return 0;
	int m = (s + e) / 2;
	return getSGT(targetL, targetR, s, m, idx << 1, sgTree) + getSGT(targetL, targetR, m + 1, e, (idx << 1) + 1, sgTree);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,C;
	cin >> N >> C;
	vector<vector<int>> grp(N + 1);
	
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}

	vector<node> getNodeSE(N + 1);

	dfs(C, 1, grp, getNodeSE);

	int sgTreeSize = 2;
	while (sgTreeSize < N) sgTreeSize <<= 1;
	sgTreeSize <<= 1;
	vector<int> sgTree(sgTreeSize + 1);
	int Q;
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;

		if (a == 1) {
			editSGT(getNodeSE[b].s, 1, N, 1, sgTree);
		}
		else {
			cout << (long long)getNodeSE[b].d * (long long)getSGT(getNodeSE[b].s, getNodeSE[b].e, 1, N, 1, sgTree) <<"\n";
		}
	}



}