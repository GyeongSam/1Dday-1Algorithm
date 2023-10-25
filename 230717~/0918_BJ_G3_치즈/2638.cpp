#include <iostream>
#include <vector>
using namespace std;
int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
struct roc {
	int i, j;
	roc(int _i, int _j) :i(_i), j(_j) {}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, cnt = 0, answer = 0;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
			if (map[i][j]) cnt++;
		}
	}
	while (cnt > 0) {
		answer++;
		vector<vector<bool>> visit(N, vector<bool>(M));
		vector<roc> dls;
		vector<roc> stack;
		stack.push_back(roc(0, 0));
		while (!stack.empty()) {
			roc now(stack.back());
			stack.pop_back();

			for (int d = 0; d < 4; ++d) {
				roc next(now.i + di[d], now.j + dj[d]);
				if (next.i < 0 || next.i >= N || next.j < 0 || next.j >= M) continue;
				if (visit[next.i][next.j]) {
					if (map[next.i][next.j]==1) {
						dls.push_back(next);
						map[next.i][next.j] = 2;
					}
					continue;
				}
				visit[next.i][next.j] = true;
				if (map[next.i][next.j]==0) stack.push_back(next);
			}
		}
		cnt -= dls.size();
		for (roc& d : dls) {
			map[d.i][d.j] = 0;
			
		}
	}
	cout << answer;
}