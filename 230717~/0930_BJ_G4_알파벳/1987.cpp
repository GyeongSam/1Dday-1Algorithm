#include <iostream>
#include <vector>
#include <string>
using namespace std;

int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
struct Node {
	int i, j, v, c;
	Node() {};
	Node(int _i, int _j, int _v, int _c) :i(_i), j(_j), v(_v), c(_c) {}
};
int main() {
	int R, C, answer=0;
	cin >> R >> C;
	vector<string> map(R);
	for (int i = 0; i < R; ++i) cin >> map[i];
	
	vector<Node> stack(1, Node(0, 0, 1<<(map[0][0]-'A'),1));

	while (!stack.empty()) {
		Node now(stack.back());
		stack.pop_back();
		if (now.c > answer) answer = now.c;
		for (int d = 0; d < 4; ++d) {
			Node next(now.i + di[d], now.j + dj[d], now.v, now.c + 1);
			if (next.i < 0 || next.i >= R || next.j < 0 || next.j >= C) continue;
			if ((next.v & (1 << (map[next.i][next.j] - 'A'))) != 0) continue;
			next.v |= (1 << (map[next.i][next.j] - 'A'));
			stack.push_back(next);
		}
	}
	cout << answer;
}