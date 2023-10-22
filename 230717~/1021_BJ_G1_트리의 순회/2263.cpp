#include <iostream>
#include <vector>

using namespace std;

int N;

void devide(int li, int ri, int lp, int rp, int idx, const vector<vector<int>>& order) {

	if (rp<0 || lp >= N || ri < 0 || li >= N) return;
	int rootNode = order[1][rp];
	for (int cnt = 0; cnt + li <= ri; ++cnt) {
		if (cnt + li < N && order[0][cnt + li] == rootNode) {
			cout << rootNode <<" ";
			if (cnt>0) devide(li, cnt + li - 1, lp, lp + cnt - 1, idx << 1, order);
			if (cnt+li+1<=ri) devide(cnt + li + 1, ri, lp + cnt, rp - 1, (idx << 1) + 1, order);
			break;
		}
	}
}
void dfs(int idx, vector<int>& tree) {
	if (idx>=tree.size()||tree[idx] == 0) {
		return;
	}
	cout << tree[idx] <<" ";
	dfs(idx << 1, tree);
	dfs((idx << 1) + 1, tree);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	vector<vector<int>> order(2,vector<int>(N));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> order[i][j];
	}
	devide(0, N - 1, 0, N - 1, 1, order);
}