#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int FindParents(int son, vector<int>& parents) {
	if (son == parents[son]) return son;
	return parents[son] = FindParents(parents[son], parents);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> candyCnts(N + 1);
	vector<int> parents(N + 1);
	vector<int> peopleCnts(N + 1,1);
	for (int i = 1; i <= N; ++i) {
		cin >> candyCnts[i];
		parents[i] = i;
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		int p1 = FindParents(a, parents);
		int p2 = FindParents(b, parents);
		if (p1 == p2) continue;
		if (p1 < p2) {
			parents[p2] = p1;
			peopleCnts[p1] += peopleCnts[p2];
			candyCnts[p1] += candyCnts[p2];
		}
		else {
			parents[p1] = p2;
			peopleCnts[p2] += peopleCnts[p1];
			candyCnts[p2] += candyCnts[p1];
		}
	}
	vector<bool> check(N + 1);
	vector<int> pList(1,0);
	for (int i = 1; i <= N; ++i) {
		int p = FindParents(i, parents);
		if (check[p]) continue;
		check[p] = true;
		pList.push_back(p);
	}

	vector<vector<int>> dp(K, vector<int>(pList.size()));

	for (int k = 1; k < K; ++k) {
		for (int n = 1; n < pList.size(); ++n) {
			dp[k][n] = dp[k][n - 1];
			if (k - peopleCnts[pList[n]] >= 0) dp[k][n] = max(dp[k][n], dp[k - peopleCnts[pList[n]]][n - 1] + candyCnts[pList[n]]);
		}
	}

	cout << dp[K-1][pList.size()-1];
}