#include <iostream>
#include <vector>
using namespace std;
void CountSum(vector<int>& Cnt, const vector<int>& Pizza) {
	int N = Pizza.size();
	for (int l = 0; l < N; ++l) {
		for (int r = l + 1; r < N; ++r) {
			int sum1 = Pizza[r] - Pizza[l];
			int sum2 = Pizza[N - 1] - sum1;
			if (sum1 < Cnt.size()) Cnt[sum1]++;
			if (sum2 < Cnt.size()) Cnt[sum2]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int target, n,m,answer=0;
	cin >> target >> n >> m;
	vector<int> nPizza(n);
	vector<int> mPizza(m);
	vector<int> nCnt(target + 1);
	vector<int> mCnt(target + 1);
	for (int i = 0; i < n; ++i) cin >> nPizza[i];
	for (int i = 0; i < m; ++i) cin >> mPizza[i];
	for (int i = 1; i < n; ++i) nPizza[i] += nPizza[i - 1];
	for (int i = 1; i < m; ++i) mPizza[i] += mPizza[i - 1];
	CountSum(nCnt, nPizza);
	CountSum(mCnt, mPizza);
	if (nPizza[n - 1] <= target) nCnt[nPizza[n - 1]]++;
	if (mPizza[m - 1] <= target) mCnt[mPizza[m - 1]]++;
	nCnt[0]++;
	mCnt[0]++;
	for (int i = 0; i <= target; ++i) {
		if (nCnt[i] > 0 && mCnt[target - i]>0) answer += nCnt[i] * mCnt[target - i];
	}
	cout << answer;
}