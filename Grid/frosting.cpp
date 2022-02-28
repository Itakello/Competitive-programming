//https://open.kattis.com/contests/pp9wfr/problems/frosting
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n;
vector<ll> a(3), b(3);

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[i % 3] += x;
		}
	for (int i = 0; i < n; i++) {
		cin >> x;
		b[i % 3] += x;
		}
	ll white = a[0] * b[0] + a[1] * b[2] + a[2] * b[1];
	ll yellow = a[0] * b[1] + a[1] * b[0] + a[2] * b[2];
	ll pink = a[2] * b[0] + a[0] * b[2] + a[1] * b[1];
	cout << yellow << " " << pink << " " << white << endl;
	return 0;
	}