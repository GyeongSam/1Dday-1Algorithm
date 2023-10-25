#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark {
	int s, v, i;
	bool operator<(const shark& other) const {
		return s<=other.s&&v<=other.v&&i<=other.i;
	}
	bool operator==(const shark& other) const {
		return (s == other.s && v == other.v && i == other.i);
	}
};

bool dfs(int now, vector<vector<int>>& grp, vector<bool>& visit, vector<int>& whoIsEat) {
	for (int next : grp[now]) {
		if (visit[next]) continue;
		visit[next] = true;
		if (whoIsEat[next]==0|| dfs(whoIsEat[next], grp, visit, whoIsEat)) {
			whoIsEat[next] = now;
			return true;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<shark> sharkList(N+1);
	for (int i = 1; i <= N;++i) {
		cin >> sharkList[i].s >> sharkList[i].v >> sharkList[i].i;
	}
	vector<vector<int>> canEatGrp(N+1);
	for (int i = 1; i < N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			if (sharkList[i] == sharkList[j]) canEatGrp[i].push_back(j);
			else {
				if (sharkList[i] < sharkList[j]) canEatGrp[j].push_back(i);
				if (sharkList[j] < sharkList[i]) canEatGrp[i].push_back(j);
			}
		}
	}

	vector<int> whoIsEat(N+1);
	vector<bool> visit;
	int count=0;
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= N; ++i) {
			visit.clear();
			visit.resize(N+1, false);
			if (dfs(i, canEatGrp, visit, whoIsEat)) count++;
		}
	}
	cout << N - count;
	
}