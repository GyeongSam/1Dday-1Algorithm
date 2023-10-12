#include <iostream>
#include <vector>
using namespace std;




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	
	vector<int> nums(N);
	for (int i = 0; i < N; ++i) cin >> nums[i];
	
	vector<vector<bool>> isP(N+1,vector<bool>(N+1));

	for (int m = 0; m < N; ++m) {
		int l = m;
		int r = m;
		while (0 <= l && r < N && nums[l] == nums[r]) {
			isP[l+1][r+1] = true;
			l--;
			r++;
		}
		l = m;
		r = m+1;
		while (0 <= l && r < N && nums[l] == nums[r]) {
			isP[l+1][r+1] = true;
			l--;
			r++;
		}
	}
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << isP[a][b] << "\n";
	}


}