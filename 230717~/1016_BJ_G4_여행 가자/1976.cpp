#include <iostream>
#include <vector>

using namespace std;

int FindParent(int son, vector<int>& parents) {
	if (son == parents[son]) return son;
	return parents[son] = FindParent(parents[son], parents);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> grp(N+1, vector<int>(N+1));
	vector<int> parents(N+1);
	for (int i = 1; i <= N; ++i) parents[i] = i;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> grp[i][j];
			if (grp[i][j] == 0) continue;
			int pi = FindParent(i, parents);
			int pj = FindParent(j, parents);
			if (pi > pj) parents[pi] = pj;
			else parents[pj] = pi;
		}
	}
	vector<bool> check(N+1);
	int cnt = 0;
	while (M--) {
		int city;
		cin >> city;
		int pCity = FindParent(city, parents);
		if (!check[pCity]) {
			cnt++;
			check[pCity] = true;
			if (cnt > 1) break;
		}
	}
	if (cnt > 1) cout << "NO";
	else cout << "YES";

}