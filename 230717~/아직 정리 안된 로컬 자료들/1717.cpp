#include <iostream>
#include <vector>
using namespace std;


int ufind(int node, vector<int>& parents) {
	if (node == parents[node]) return node;
	return parents[node] = ufind(parents[node], parents);
}
void umerge(int node1, int node2, vector<int>& parents) {
	int p1 = ufind(node1,parents);
	int p2 = ufind(node2,parents);
	if (p1 > p2) parents[p1] = parents[p2];
	else parents[p2] = parents[p1];
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> parents(n+1);
	for (int i = 0; i <= n; ++i) parents[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			umerge(b, c, parents);
		}
		else {
			if (ufind(b, parents) == ufind(c, parents)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}