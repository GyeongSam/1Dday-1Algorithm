#include <iostream>
#include <vector>
using namespace std;

struct node {
	long long value, total, cnt;
	node() : value(0), total(0), cnt(0) {}
};

void makeSGT(int s, int e, int idx, const vector<long long>& nums, vector<node>& sgTree) {
	if (s == e) {
		sgTree[idx].value = nums[s];
		return;
	}
	int m = (s + e) / 2;
	makeSGT(s, m, idx << 1, nums, sgTree);
	makeSGT(m + 1, e, (idx << 1) + 1, nums, sgTree);
	sgTree[idx].value = sgTree[idx << 1].value + sgTree[(idx << 1) + 1].value;
}
void addStar(int targetL, int targetR, int s, int e, int idx, vector<node>& sgTree) {
	if (targetR < s || e < targetL) return;
	if (targetL <= s && e <= targetR) {	
		sgTree[idx].total += ((long long)s - targetL + 1);
		sgTree[idx].cnt++;
		return;
	}
	int m = (s + e) / 2;
	addStar(targetL, targetR, s, m, idx << 1, sgTree);
	addStar(targetL, targetR, m + 1, e, (idx << 1) + 1, sgTree);
}

long long getStar(int target, int s, int e, int idx, const vector<node>& sgTree) {
	long long sum = 0;

	while (s <= e) {
		sum += sgTree[idx].total;
		sum += sgTree[idx].cnt * ((long long)target - s);
		if (s == e) {
			sum += sgTree[idx].value;
			break;
		}
		int m = (s + e) / 2;
		if (target <= m) {
			e = m;
			idx <<= 1;
		}
		else {
			s = m + 1;
			idx <<= 1;
			idx++;
		}
	}
	return sum;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<long long> nums(N+1);
	for (int i = 1; i <= N; ++i) cin >> nums[i];
	
	int sgSize = 2;
	while (sgSize < N) sgSize <<= 1;
	sgSize <<= 1;
	vector <node> sgTree(sgSize+1);

	makeSGT(1, N, 1, nums, sgTree);
	int Q;
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			int c;
			cin >> c;
			addStar(b, c, 1, N, 1, sgTree);
		}
		else {
			cout << getStar(b, 1, N, 1, sgTree) <<"\n";
		}
	}


}