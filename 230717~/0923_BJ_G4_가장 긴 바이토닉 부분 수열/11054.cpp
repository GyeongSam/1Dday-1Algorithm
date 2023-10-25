#include<iostream>
#include <vector>

using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,answer=0;
	cin >> N;
	vector<int> nums(N);
	vector<int> leftDp(N);
	vector<int> rightDp(N);
	for (int i = 0; i < N; ++i) cin >> nums[i];
	leftDp[0] = 1;
	rightDp[N - 1] = 1;
	for (int i = 1; i < N; ++i) {
		leftDp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (nums[i] <= nums[j]) continue;
			leftDp[i] = max(leftDp[i], leftDp[j] + 1);
		}
	}
	for (int i = N-2; i >=0; --i) {
		rightDp[i] = 1;
		for (int j = N-1; j >i; --j) {
			if (nums[i] <= nums[j]) continue;
			rightDp[i] = max(rightDp[i], rightDp[j] + 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		if (answer < leftDp[i] + rightDp[i]-1) answer = leftDp[i] + rightDp[i]-1;
	}
	cout << answer;

}