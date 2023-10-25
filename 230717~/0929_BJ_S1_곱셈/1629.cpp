#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
ll dnc(ll a, ll b, ll c, unordered_map<ll, ll>& dp) {
	if (dp.find(b) != dp.end()) return dp[b];
	return dp[b] = dnc(a, b / 2, c, dp) * dnc(a, b - b / 2, c, dp) % c;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;
	unordered_map<ll, ll> dp;
	dp[1] = A%C;
	dp[0] = 1;
	cout << dnc(A, B, C, dp);
}