#include <iostream>
#include <vector>
using namespace std;
struct node{
	int to, dist;
	node(int t, int d) : to(t), dist(d) {}
};

int max(int a, int b) {
	return a > b ? a : b;
}

int dfs(int now, int& answer, const vector<vector<node>>& grp) {
	int maxDist1 = 0;
	int maxDist2 = 0;
	for (const node& next : grp[now]) {
		maxDist1 = max(maxDist1,dfs(next.to, answer, grp) + next.dist);
		if (maxDist2 < maxDist1) {
			int temp = maxDist1;
			maxDist1 = maxDist2;
			maxDist2 = temp;
		}
	}
	if (answer < maxDist1 + maxDist2) answer = maxDist1 + maxDist2;
	return maxDist2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, answer=0;
	cin >> n;
	vector<vector<node>> grp(n + 1);

	for (int i = 1; i < n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		grp[a].push_back(node(b,c));
	}
	dfs(1, answer, grp);
	cout << answer;
	

}