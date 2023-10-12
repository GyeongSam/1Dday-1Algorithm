
#include <iostream>
#include <vector>
using namespace std;

int depth;
void dfs(int now, vector<int>& depths, vector<bool>& visit, vector<int>& wantTo, int &answer) {
	depths[now] = depth;
	depth++;
	int next = wantTo[now];
	if (visit[next]) {
		visit[now] = true;
		return;
	}
	if (depths[next] != 0) {

		answer += depths[now]- depths[next] + 1;
		visit[now] = true;
		return;
	}
	dfs(next, depths, visit, wantTo, answer);
	visit[now] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {

		int n,answer=0;
		depth = 1;
		cin >> n;
		vector<int> wantTo(n + 1);
		vector<int> depths(n + 1);
		vector<bool> visits(n + 1);
		for (int i = 1; i <= n; ++i) cin >> wantTo[i];
		for (int i = 1; i <= n; ++i) {
			if (visits[i]) continue;
			dfs(i, depths, visits, wantTo, answer);
		}
		cout << n - answer <<"\n";
	}
}
