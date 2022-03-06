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
		unordered_map<int, int> mp;
		stack<int> st;
		for (int i = 0; i < m; i++) {
			mp[i] = st.size();
			st.push(i);
			}
		int tmp;
		for (int i = 0; i < r; i++) {
			cin >> tmp;
			auto it = mp.find(tmp);
			cout << it->second << " ";
			int val = *it;
			s.erase(it);
			// cout << val << endl;
			s.insert(val);
			}
		cout << endl;
		}
	return 0;
	}