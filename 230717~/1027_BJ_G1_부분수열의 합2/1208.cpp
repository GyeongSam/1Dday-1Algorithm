#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct comb {
	int l, r;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, target;
	long long answer = 0;
	cin >> n >> target;
	int n1 = n / 2, n2 = n - n1;
	vector<int> numList1(n1), numList2(n2);
	unordered_map<int, int> sumMap1, sumMap2;
	for (int i = 0; i < n1; ++i) cin >> numList1[i];
	for (int i = 0; i < n2; ++i) cin >> numList2[i];
	for (int i = 0; i < (1 << n1); ++i) {
		int sum = 0;
		for (int j = 0; j < n1; ++j) {
			if ((i & (1 << j)) != 0) sum += numList1[j];
		}
		if (sumMap1.find(sum) != sumMap1.end()) {
			sumMap1[sum]++;
		}
		else sumMap1[sum] = 1;

	}
	for (int i = 0; i < (1 << n2); ++i) {
		int sum = 0;
		for (int j = 0; j < n2; ++j) {
			if ((i & (1 << j)) != 0) sum += numList2[j];
		}
		if (sumMap2.find(sum) != sumMap2.end()) {
			sumMap2[sum]++;
		}
		else sumMap2[sum] = 1;
	}
	for (auto s : sumMap1) {
		int t = target - s.first;
		if (sumMap2.find(t) != sumMap2.end()) {
			answer += (long long)s.second * sumMap2[t];
		}
	}
	if (target == 0) answer--;
	cout << answer;	
}
//https://www.acmicpc.net/problem/1208