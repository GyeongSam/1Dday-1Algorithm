#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	Point() :x(0), y(0) {}
	Point(int sx, int sy) :x(sx), y(sy) {}
};
struct line {
	Point s, e;
	void Swap() {
		Point temp(e.x, e.y);
		e.x = s.x;
		e.y = s.y;
		s.x = temp.x;
		s.y = temp.y;
	}
};
int CrossProduct(const line& l, const Point& p) {
	Point v1(l.e.x - l.s.x, l.e.y - l.s.y);
	Point v2(p.x - l.e.x, p.y - l.e.y);
	int c1 = v1.x * v2.y - v1.y * v2.x;
	if (c1 > 0) return 1;
	else if (c1 < 0) return -1;
	return 0;
}
int GetLen(const Point& a, const Point& b) {
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
bool IsCross(const line& l1, const line& l2) {
	int c1 = CrossProduct(l1, l2.s) ,c2 = CrossProduct(l1, l2.e);
	int c3 = CrossProduct(l2, l1.s) ,c4 = CrossProduct(l2, l1.e);
	if (c1 == 0 && c2 == 0 && c3==0 && c4==0) {
		int len1 = GetLen(l1.s, l1.e);
		int len2 = GetLen(l2.s, l2.e);
		int lenTotal = GetLen(l1.s, l2.e);
		return lenTotal <= len1 + len2;
	}
	return c1*c2 <= 0 && c3*c4 <= 0;
}

int FindParents(int son, vector<int>& parents) {
	if (son == parents[son]) return son;
	return parents[son] = FindParents(parents[son], parents);
}

int main() {
	int N;
	cin >> N;
	vector<line> lines(N);
	vector<int> parents(N);
	for (int i = 0; i < N;++i) {
		cin >> lines[i].s.x >> lines[i].s.y >> lines[i].e.x >> lines[i].e.y;
		if (lines[i].s.x > lines[i].e.x) lines[i].Swap();
		parents[i] = i;
	}
	sort(lines.begin(), lines.end(), [](const line& a, const line& b) {if (a.s.x == b.s.x)return a.s.y < b.s.y; return a.s.x < b.s.x; });

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (lines[i].e.x < lines[j].s.x) break;
			if (!IsCross(lines[i], lines[j])) continue;
			int pi = FindParents(i, parents);
			int pj = FindParents(j, parents);
			if (pi == pj) continue;
			else if (pi > pj) {
				parents[pi] = pj;
			}
			else {
				parents[pj] = pi;
			}
		}
	}
	vector<int> groupCnt(N);
	int cnt=0;
	int max=0;
	for (int i = 0; i < N; ++i) {
		groupCnt[FindParents(i, parents)]++;
	}
	for (int i = 0; i < N; ++i) {
		if (groupCnt[i] > 0) cnt++;
		if (groupCnt[i] > max) max = groupCnt[i];
	}
	cout << cnt << "\n" << max;
	
}