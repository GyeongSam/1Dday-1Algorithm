#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct point {
	int i, j, c;
	point(int _i,int _j, int _c) : i(_i), j(_j), c(_c) {}
	bool operator<(const point& other) const {
		return other.c < c;
	}
};
int N, M, answer=-1;
inline point FallToGround(point a, const vector<string>&map) {
	if (map[a.i][a.j] == 'D') {
		answer = a.c;
	}
	if (a.c % 2) {
		while (a.i > 0 && map[a.i-1][a.j] != '#') {
			a.i--;
			if (map[a.i][a.j] == 'D') {
				answer = a.c;
			}
		}
	}
	else {
		while (a.i < N - 1 && map[a.i + 1][a.j] != '#') {
			a.i++;
			if (map[a.i][a.j] == 'D') {
				answer = a.c;
			}
		}
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	const int INF = 1 << 29;
	vector<string> map(N);
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(M,vector<int>(2,INF)));
	priority_queue<point> q;
	for (int i = 0; i < N; ++i) cin >> map[i];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 'C') {
				q.push(FallToGround(point(i,j,0),map));
				dp[q.top().i][q.top().j][0] = 0;
			}
		}
	}
	if (q.top().i != N - 1) {
		while (!q.empty() && answer == -1) {
			point now(q.top());
			q.pop();
			if (now.j > 0 && map[now.i][now.j - 1] != '#') {
				point next(FallToGround(point(now.i, now.j - 1, now.c), map));
				if (next.i != 0 && next.i != N - 1 && dp[next.i][next.j][next.c%2] > dp[now.i][now.j][now.c%2]) {
					dp[next.i][next.j][next.c%2] = dp[now.i][now.j][now.c % 2];
					q.push(next);
				}
			}
			if (now.j < M - 1 && map[now.i][now.j + 1] != '#') {
				point next(FallToGround(point(now.i, now.j + 1, now.c), map));
				if (next.i != 0 && next.i != N - 1 && dp[next.i][next.j] > dp[now.i][now.j]) {
					dp[next.i][next.j][next.c % 2] = dp[now.i][now.j][now.c % 2];
					q.push(next);
				}
			}
			if (answer != -1)break;
			point next(FallToGround(point(now.i, now.j, now.c + 1), map));
			if (next.i != 0 && next.i != N - 1 && dp[next.i][next.j][next.c % 2] > dp[now.i][now.j][now.c%2] + 1) {
				dp[next.i][next.j][next.c%2] = dp[now.i][now.j][now.c%2] + 1;
				q.push(next);
			}
		}
	}

	cout << answer;

}