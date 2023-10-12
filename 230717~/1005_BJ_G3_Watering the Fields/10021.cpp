#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x, y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
};

int FindParents(int s, vector<int>& parents) {
	if (parents[s] == s) return s;
	return parents[s] = FindParents(parents[s], parents);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, C;
	cin >> N >> C;
	vector<Point> pointList(N);
	for (int i = 0; i < N; ++i) {
		cin >> pointList[i].x >> pointList[i].y;
	}
	vector<vector<Point>> lenths(2000001);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int len = (pointList[i].x - pointList[j].x) * (pointList[i].x - pointList[j].x) + (pointList[i].y - pointList[j].y) * (pointList[i].y - pointList[j].y);
			if (len < C) continue;
			lenths[len].push_back(Point(i, j));
		}
	}
	vector<int> parents(N+1);
	for (int i = 1; i <= N; ++i) parents[i] = i;
	int cnt = 0,answer=0;
	for (int l = C; l < 2000001; ++l) {
		if (lenths[l].empty()) continue;
		for (const Point& p : lenths[l]) {
			int p1 = FindParents(p.x, parents);
			int p2 = FindParents(p.y, parents);
			if (p1 == p2) continue;
			else if (p1 > p2) parents[p1] = p2;
			else parents[p2] = p1;
			answer += l;
			cnt++;
			if (cnt == N - 1) break;
		}
		if (cnt == N - 1) break;
	}
	if (cnt == N - 1) cout << answer;
	else cout << "-1";

}