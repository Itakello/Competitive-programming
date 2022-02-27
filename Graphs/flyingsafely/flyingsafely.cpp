// https://open.kattis.com/contests/z4dra4/problems/flyingsafely
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, n, m;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n >> m;
		cout << n - 1 << endl;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			}
		}
	return 0;
	}