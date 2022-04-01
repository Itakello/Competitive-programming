//https://open.kattis.com/contests/uawr9g/problems/chess
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

int n;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	char sc, ec;
	int sy, ey;
	for (int i = 0; i < n; i++) {
		cin >> sc >> sy >> ec >> ey;
		sy--; ey--;
		int sx = sc - 'A';
		int ex = ec - 'A';
		if ((sx + sy) % 2 != (ex + ey) % 2) {
			cout << "Impossible" << endl;
			continue;
			}
		if (sx == ex && sy == ey) {
			cout << "0 " << sc << " " << sy + 1 << endl;
			continue;
			}
		if (abs(sx - ex) == abs(sy - ey)) {
			cout << "1 " << sc << " " << sy + 1 << " " << ec << " " << ey + 1 << endl;
			continue;
			}
		int x, y;
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				if (abs(j - sx) == abs(k - sy) && abs(j - ex) == abs(k - ey)) {
					x = j;
					y = k;
					// cout << j << " " << k << " " << sx << " " << sy << " " << ex << " " << ey << endl;
					}
				}
			}
		cout << "2 " << sc << " " << sy + 1 << " " << (char)('A' + x) << " " << y + 1 << " " << ec << " " << ey + 1 << endl;
		}

	return 0;
	}