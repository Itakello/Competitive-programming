//https://open.kattis.com/contests/uawr9g/problems/rockpaperscissors
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

int n, k;

int match(string s1, string s2) {
	if (s1 == s2)
		return 0;
	if (s1 == "rock") {
		if (s2 == "paper")
			return -1;
		else
			return 1;
		}
	if (s1 == "paper") {
		if (s2 == "rock")
			return 1;
		else
			return -1;
		}
	if (s1 == "scissors") {
		if (s2 == "paper")
			return 1;
		else
			return -1;
		}
	return 42;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(3);
	while (cin >> n >> k) {
		int games = k * n * (n - 1) / 2;
		vector<float> wins(n + 1, 0.0), losses(n + 1, 0.0);
		int a, b;
		string sa, sb;
		for (int i = 0; i < games; i++) {
			cin >> a >> sa >> b >> sb;
			int m = match(sa, sb);
			if (m > 0) {
				wins[a]++;
				losses[b]++;
				}
			if (m < 0) {
				wins[b]++;
				losses[a]++;
				}
			}
		for (int i = 1; i <= n; i++) {
			if (wins[i] == 0 && losses[i] == 0)
				cout << "-" << endl;
			else
				cout << wins[i] / (wins[i] + losses[i]) << endl;
			}
		cout << endl;
		}
	return 0;
	}