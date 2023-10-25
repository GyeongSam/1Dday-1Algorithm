#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	priority_queue<int> pq;
	while (N--) {
		int x;
		cin >> x;
		if (x) {
			pq.push(-x);
		}
		else {
			if (pq.empty()) cout << "0\n";
			else {
				cout << -pq.top() << "\n";
				pq.pop();
			}
		}
	}
}