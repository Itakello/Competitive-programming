//https://open.kattis.com/contests/pp9wfr/problems/findinglines
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 1000000005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n, p;
vector<pair<ll, ll>> coord(MAXN);

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cout << "ok" << endl;
	cin >> n >> p;
	/* int goal = ceil((n * p) / (double)100);
	ll x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		coord[i] = { x,y };
		}
	for (int i = 0; i < 10; i++) {
		int rand1 = (rand() % n) + 1;
		int rand2 = (rand() % n) + 1;
		double m = (coord[rand1].second - coord[rand2].second) / (coord[rand1].first - coord[rand2].first);
		ll b = coord[rand1].second / (m * coord[rand1].first);
		cout << rand1 << " " << rand2 << " " << m << " " << b << endl;
		} */


	return 0;
	}