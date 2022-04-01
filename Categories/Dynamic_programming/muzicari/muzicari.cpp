// https://open.kattis.com/contests/kzhiwr/problems/muzicari
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int T, N;
vii breaks;
vector<vi> DP;

int knapSack(int i, int c) {
	if (c < 0)
		return INT_MIN;
	if (i == 0 || c == 0)
		return 0;
	if (DP[i][c] < 0) {
		int nottaken = knapSack(i - 1, c);
		int taken = knapSack(i - 1, c - breaks[i].first) + breaks[i].first;
		DP[i][c] = max(nottaken, taken);
		}
	return DP[i][c];
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T >> N;
	breaks.resize(N + 1);
	DP.resize(N + 1);

	for (int i = 0; i <= N; i++) {
		if (i != N) {
			cin >> breaks[i + 1].first;
			breaks[i + 1].second = -1;
			}
		DP[i].assign(T + 1, -1);
		}

	knapSack(N, T);

	/* for (int i = 0; i < DP.size(); i++) {
		for (int j = 0; j < DP[0].size(); j++) {
			cout << DP[i][j] << "\t";
			}
		cout << endl;
		} */

		// Rebuilt first set
	int res = DP[N][T];
	int w = T;
	for (int i = N; i > 0 && res > 0; i--) {
		if (res == DP[i - 1][w])
			continue;
		res -= breaks[i].first;
		w -= breaks[i].first;
		breaks[i].second = res;
		}

	// Rebuild second set
	int start = 0;
	for (int i = 1; i <= N; i++) {
		if (breaks[i].second == -1) {
			breaks[i].second = start;
			start += breaks[i].first;
			}
		}

	// Print solution
	for (int i = 1; i <= N; i++) {
		cout << breaks[i].second << " ";
		}
	return 0;
	}