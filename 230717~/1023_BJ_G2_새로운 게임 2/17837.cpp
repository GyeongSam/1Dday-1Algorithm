#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int di[5] = {0, 0,0,-1,1 }, dj[5] = {0, 1,-1,0,0 };
int transDir[5] = { 0,2,1,4,3 };
struct Pawn {
	int i, j, dir;
};
bool isCanMove(int i, int j, vector<vector<int>>& map) {
	return i > 0 && i < map.size() && j > 0 && j < map.size() && map[i][j] != 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, K, answer=0;
	bool flag = false;
	cin >> N >> K;
	vector<vector<int>> mapColor(N+1, vector<int>(N+1));
	vector<Pawn> pawnList(K+1);
	vector<vector<vector<int>>> pawnOnMap(N+1,vector<vector<int>>(N+1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> mapColor[i][j];
		}
	}
	for (int i = 1; i <= K; ++i) {
		cin >> pawnList[i].i >> pawnList[i].j >> pawnList[i].dir;
		pawnOnMap[pawnList[i].i][pawnList[i].j].push_back(i);
	}
	while (answer<=1000&&!flag) {
		answer++;
		for (int p = 1; p <= K; ++p) {
			Pawn& nowP = pawnList[p];
			int ni = nowP.i + di[nowP.dir];
			int nj = nowP.j + dj[nowP.dir];

			if (!isCanMove(ni,nj,mapColor)) {
				nowP.dir = transDir[nowP.dir];
				ni = nowP.i + di[nowP.dir];
				nj = nowP.j + dj[nowP.dir];
				if (!isCanMove(ni, nj, mapColor)) continue;
			}

			vector<int>& nowStack = pawnOnMap[nowP.i][nowP.j];
			vector<int>& nextStack = pawnOnMap[ni][nj];
			int s = 0, e = nowStack.size() - 1;
			while (s <= e && nowStack[s] != p) s++;
			if (mapColor[ni][nj] == 1) {
				for (int i = e; i >= s; i--) {
					int otherP = nowStack[i];
					nextStack.push_back(otherP);
					pawnList[otherP].i = ni;
					pawnList[otherP].j = nj;
				}
			}
			else {
				for (int i = s; i <= e; ++i) {
					int otherP = nowStack[i];
					nextStack.push_back(otherP);
					pawnList[otherP].i = ni;
					pawnList[otherP].j = nj;
				}
			}
			for (int i = s; i <= e; ++i) nowStack.pop_back();
			if (nextStack.size() >= 4) {
				flag = true;
				break;
			}

		}
	}
	if (answer > 1000) answer = -1;
	cout << answer;
}
