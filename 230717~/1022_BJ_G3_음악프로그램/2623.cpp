#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> cnt(N + 1);
	vector<vector<bool>> grp1(N + 1, vector<bool>(N + 1));
	vector<vector<int>> grp2(N + 1);
	while (M--) {
		int q, s, e;
		cin >> q;
		q--;
		cin >> s;
		while (q--) {
			cin >> e;
			grp1[s][e] = true;
			s = e;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (grp1[i][j]) {
				grp2[i].push_back(j);
				cnt[j]++;
			}
		}
	}

	vector<int> answer;
	for (int i = 1; i <= N; ++i) {
		if (cnt[i] == 0) {
			answer.push_back(i);
			cnt[i] = -1;
		}
	}

	int idx = 0;
	while (idx < answer.size()) {
		int now = answer[idx];
		idx++;

		for (int next : grp2[now]) {
			if (cnt[next] <= 0) continue;
			cnt[next]--;
			if (cnt[next] == 0) {
				answer.push_back(next);
				cnt[next] = -1;
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= N; ++i) {
		if (cnt[i] != -1) flag = false;
	}
	if (!flag) {
		answer.clear();
		answer.push_back(0);
	}
	for (int i : answer) cout << i << "\n";
}