#include <iostream>
using namespace std;
int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int vx1 = x2 - x1, vy1 = y2 - y1, vx2 = x3 - x2, vy2 = y3 - y2;
	int c = vy2 * vx1 - vy1 * vx2;
	if (c > 0) cout << "1";
	else if (c < 0) cout << "-1";
	else cout << "0";
}