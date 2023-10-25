#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m;
	cin >> m;

	vector<vector<int>> nums(m+1, vector<int>(20,0));
	for (int i = 1; i <= m; ++i) cin >> nums[i][0];

	for (int depth = 0; depth < 19; ++depth) {
		for (int i = 1; i <= m; ++i) {
			nums[i][depth + 1] = nums[nums[i][depth]][depth];
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int n, x;
		cin >> n >> x;
		
		int gap = 19;
		while (n > 0) {
			while ((1 << gap) > n) {
				gap--;
			}

			x=nums[x][gap];
			n -= (1<<gap);
		}
		cout << x <<"\n";
	}

	
}