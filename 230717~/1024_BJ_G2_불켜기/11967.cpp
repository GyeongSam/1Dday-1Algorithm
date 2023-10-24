#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int i, j;
	node(){}
	node(int _i,int _j):i(_i),j(_j){}
};

int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,M,answer=0;
	cin >> N >> M;
	vector<vector<int>> map(N + 1, vector<int>(N + 1));
	vector<vector<vector<node>>> grp(N + 1, vector<vector<node>>(N + 1));

	while (M--) {
		node a, b;
		cin >> a.i >> a.j >> b.i >> b.j;
		grp[a.i][a.j].push_back(b);
	}
	map[1][1] = 3;
	queue<node> q;
	q.push(node(1, 1));
	while (!q.empty()) {
		node now(q.front());
		q.pop();
		for (int d = 0; d < 4; ++d) {
			node next(now.i + di[d], now.j + dj[d]);
			if (next.i <= 0 || next.i > N || next.j <= 0 || next.j > N || ((map[next.i][next.j]&1)!=0)) continue;
			if ((map[next.i][next.j] & 2) != 0) {
				q.push(next);
			}
			map[next.i][next.j] |= 1;
		}
		for (node& room : grp[now.i][now.j]) {
			if ((map[room.i][room.j] & 2) != 0) continue;
			if ((map[room.i][room.j] & 1) != 0) {
				q.push(room);
			}
			map[room.i][room.j] |= 2;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (map[i][j] > 1) answer++;
		}
	}

	cout << answer;
	
}
