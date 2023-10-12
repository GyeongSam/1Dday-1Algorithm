#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		multiset<int> ms;
		while (N--) {
			char c;
			int d;
			cin >> c >> d;
			if (c == 'I') {
				ms.insert(d);
			}
			else {
				if (ms.empty()) continue;
				if (d > 0) {
					int max = *ms.rbegin();
					ms.erase(ms.lower_bound(max));
				}
				else {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *ms.rbegin() << " " << *ms.begin() << "\n";
	}
}