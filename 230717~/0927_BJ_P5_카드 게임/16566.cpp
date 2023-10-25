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
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> cards(N + 2);
	while(M--) {
		int num;
		cin >> num;
		cards[num] = num;
	}
	for (int n = N; n >= 0; --n) {
		if (cards[n] == 0) cards[n] = n + 1;
	}
	while (K--) {
		int target;
		cin >> target;
		int bigCard = FindParent(target + 1, cards);
		if (bigCard<=N) cout << bigCard << "\n";
		cards[bigCard] = bigCard + 1;
	}
}