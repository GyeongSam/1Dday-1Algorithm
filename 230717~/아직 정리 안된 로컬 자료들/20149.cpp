#include <iostream>
#include <vector>

using namespace std;


struct point {
	int x, y;
	point() { x = 0; y = 0; };
	point(int _x, int _y) { x = _x; y = _y; }
};
struct line {
	long double t, c;
	line(point& a, point& b) {
		t = ((long double)b.y - a.y) / ((long double)b.x - a.x);
		c = (-((long double)b.y * a.x - (long double)a.y * b.x)) / ((long double)b.x - a.x);
	}
	long double GetY(long double x) {
		return t * x + c;
	}
};
long double GetX(line& a, line& b) {
	return -(a.c - b.c) / (a.t - b.t);
}

int CrossProduct(point& a, point& b, point& c) {
	point v1(a.x - c.x, a.y - c.y);
	point v2(b.x - c.x, b.y - c.y);
	int j = v1.x * v2.y - v1.y * v2.x;
	if (j > 0) return 1;
	else if (j < 0) return -1;
	return 0;
}
int isIn(point& a, point& b, point& c) {
	int q;
	if (a.x == b.x) q = (a.y - c.y) * (b.y - c.y);
	else q = (a.x - c.x) * (b.x - c.x);
	if (q < 0) return 1;
	if (q == 0) return 0;
	else return -1;
}

int main() {
	point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	int ab_c = CrossProduct(a, b, c);
	int ab_d = CrossProduct(a, b, d);
	int cd_a = CrossProduct(c, d, a);
	int cd_b = CrossProduct(c, d, b);
	int can = 0;
	long double x = 10000000, y = 0;
	if (ab_c * ab_d < 0 && cd_a * cd_b < 0) {
		
		can = 1;
		if (a.x == b.x) {
			line cd(c, d);
			x = (long double)a.x;
			y = cd.GetY(x);
		}
		else if (c.x == d.x) {
			line ab(a, b);
			x = (long double)c.x;
			y = ab.GetY(x);
		}
		else {
			line ab(a, b);
			line cd(c, d);
			x = GetX(ab, cd);
			y = ab.GetY(x);
		}
	}
	else if (ab_c == 0 && ab_d == 0) {
		int l1, r1, l2, r2;
		if (a.x == b.x) {
			l1 = a.y > b.y ? b.y : a.y;
			r1 = a.y > b.y ? a.y : b.y;
			l2 = c.y > d.y ? d.y : c.y;
			r2 = c.y > d.y ? c.y : d.y;
		}
		else {
			l1 = a.x > b.x ? b.x : a.x;
			r1 = a.x > b.x ? a.x : b.x;
			l2 = c.x > d.x ? d.x : c.x;
			r2 = c.x > d.x ? c.x : d.x;
		}
		if (l1 < l2) {

			if (l2 <= r1) can = 1;
			if (r1 == l2) {
				if (a.x==b.x) {
					if (a.y > b.y) {
						x = a.x;
						y = a.y;
					}
					else {
						x = b.x;
						y = b.y;
					}
				}
				else {
					if (a.x > b.x) {
						x = a.x;
						y = a.y;
					}
					else {
						x = b.x;
						y = b.y;
					}
				}
			}
		}
		else {
			if (l1 <= r2) can = 1;
			if (r2 == l1) {
				if (a.x == b.x) {
					if (c.y > d.y) {
						x = c.x;
						y = c.y;
					}
					else {
						x = d.x;
						y = d.y;
					}
				}
				else {
					if (c.x > d.x) {
						x = c.x;
						y = c.y;
					}
					else {
						x = d.x;
						y = d.y;
					}
				}
			}
		}
	}
	else if (ab_c == 0 && isIn(a,b,c)>=0) {
		can = 1;
		x = (long double)c.x;
		y = (long double)c.y;
	}
	else if (ab_d == 0 && isIn(a, b, d)>=0) {
		can = 1;
		x = (long double)d.x;
		y = (long double)d.y;
	}
	else if (cd_a == 0 && isIn(c,d,a)>=0) {
		can = 1;
		x = (long double)a.x;
		y = (long double)a.y;
	}
	else if (cd_b == 0 && isIn(c,d,b)>=0) {
		can = 1;
		x = (long double)b.x;
		y = (long double)b.y;
	}
	cout << can <<"\n";
	if (x != 10000000) {
		cout << fixed;
		cout.precision(16);
		cout << x << " " << y;
	}
}