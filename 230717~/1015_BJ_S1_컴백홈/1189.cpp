#include <iostream>
#include <vector>
#include <string>
using namespace std;

int di[4] = { -1,0,1,0 }, dj[4] = { 0,1,0,-1 };
int R, C, K;
void dfs(int i, int j, int step, int& answer, vector<string>& map) {
	if (i == 0 && j == C - 1 && step == K) {
		answer++;
		return;
	}
	for (int d = 0; d < 4; ++d) {
		int ni = i + di[d], nj = j + dj[d];
		if (ni < 0 || ni >= R || nj < 0 || nj >= C || map[ni][nj]!='.') continue;
		map[ni][nj] = 'T';
		dfs(ni, nj, step + 1, answer, map);
		map[ni][nj] = '.';
	}
}
int main() {
	cin >> R >> C >> K;
	vector<string> map(R);
	for (int i = 0; i < R; ++i) cin >> map[i];
	int answer=0;
	map[R - 1][0] = 'T';
	dfs(R - 1, 0, 1, answer, map);
	cout << answer;
}