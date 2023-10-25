#include <iostream>

using namespace std;
using ll = long long;
struct Point {
	ll x, y;
	Point(){}
	Point(ll _x, ll _y):x(_x),y(_y){}
};
int CrossProduct(const Point& p1, const Point& p2, const Point& p3) {
	Point v1(p2.x - p1.x, p2.y - p1.y);
	Point v2(p3.x - p2.x, p3.y - p2.y);
	ll c = v1.x * v2.y - v2.x * v1.y;
	if (c < 0) return -1;
	else if (c > 0) return 1;
	return 0;
}
int main() {
	Point p1,p2,p3,p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
	cout << (((CrossProduct(p1, p2, p3) * CrossProduct(p1, p2, p4)) <= 0) && ((CrossProduct(p3, p4, p1) * CrossProduct(p3, p4, p2)) <= 0));

}