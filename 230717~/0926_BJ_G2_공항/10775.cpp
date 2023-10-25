#include <iostream>
#include <vector>

using namespace std;


int FindParent(int son, vector<int>& parents) {
	if (son == parents[son]) return son;
	return parents[son] = FindParent(parents[son], parents);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int G, P, answer = 0;
	cin >> G >> P;
	vector<int> parents(G + 1);
	for (int i = 1; i <= G; ++i) parents[i] = i;
	for (; answer < P; ++answer) {
		int g;
		cin >> g;
		int p = FindParent(g, parents);
		if (p == 0) break;
		parents[p] = p - 1;
	}
	cout << answer;
}