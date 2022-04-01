//https://open.kattis.com/contests/uawr9g/problems/toilet
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int up = 0, down = 0, like = 0;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1])
			like++;
		if (i > 1) {
			if (s[i] == 'U') {
				down += 2;
				}
			if (s[i] == 'D') {
				up += 2;
				}
			}
		}
	if (s[0] != s[1]) {
		down++; up++;
		}
	if (s[1] == 'U')
		down++;
	else
		up++;
	cout << up << endl << down << endl << like << endl;
	return 0;
	}