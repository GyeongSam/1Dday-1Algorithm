#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>& makeST(int s, int e, int idx, const vector<int>& nums, vector<vector<int>>& sgTree) {
	if (s == e) {
		sgTree[idx].push_back(nums[s]);
		return sgTree[idx];
	}
	int m = (s + e) / 2;
	vector<int>& vl = makeST(s, m, idx << 1, nums, sgTree);
	vector<int>& vr = makeST(m + 1, e, (idx << 1) + 1, nums, sgTree);
	sgTree[idx].resize(vl.size() + vr.size());
	merge(vl.begin(), vl.end(), vr.begin(), vr.end(),sgTree[idx].begin());
	return sgTree[idx];
}

int getST(int targetL, int targetR, int targetV, int s, int e, int idx, const vector<vector<int>>& sgTree) {
	if (e < targetL || targetR < s) return 0;
	if (targetL <= s && e <= targetR) {

		int l = 0;
		int r = sgTree[idx].size()-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (targetV < sgTree[idx][m]) {
				r = m - 1;
			}
			else l = m + 1;
		}
		return sgTree[idx].size() - l;
	}
	int m = (s + e) / 2;
	return getST(targetL, targetR, targetV, s, m, idx << 1, sgTree) + getST(targetL, targetR, targetV, m + 1, e, (idx << 1) + 1, sgTree);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> nums(N+1);
	for (int i = 1; i <= N; ++i) cin >> nums[i];
	
	int stSize = 2;
	while (stSize < N) stSize <<=1;
	stSize <<= 1;
	vector<vector<int>> sgTree(stSize+1);
	makeST(1, N, 1, nums, sgTree);

	int k;
	cin >> k;
	while (k--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << getST(a, b, c, 1, N, 1, sgTree) << "\n";
	}

}