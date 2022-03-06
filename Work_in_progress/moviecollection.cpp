//https://open.kattis.com/contests/mv3zwo/problems/moviecollection
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

int n, m, r;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> m >> r;
		unordered_set<int> s;
		for (int i = m; i > 0; i--) {
			s.insert(i);
			}
		int tmp;
		for (int i = 0; i < r; i++) {
			/* for (auto x : s) {
				cout << x << " ";
				}
			cout << endl; */
			cin >> tmp;
			auto it = s.find(tmp);
			cout << distance(s.begin(), it) << " ";
			int val = *it;
			s.erase(it);
			// cout << val << endl;
			s.insert(val);
			}
		cout << endl;
		}
	return 0;
	}