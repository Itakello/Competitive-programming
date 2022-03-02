//https://open.kattis.com/contests/uawr9g/problems/8queens
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

char board[8][8];

bool valid(int i, int j) {
	for (int k = 0; k < 8; k++) {
		if (k != i && board[k][j] == '*')
			return false;
		if (k != j && board[i][k] == '*')
			return false;
		for (int u = 0; u < 8; u++) {
			if (k != i && u != j) {
				if (abs(k - i) == abs(u - j) && board[k][u] == '*')
					return false;
				}
			}
		}
	return true;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int queens = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> board[i][j];
			}
		}
	bool ok = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == '*') {
				queens++;
				if (!valid(i, j)) {
					ok = false;
					break;
					}
				}
			}
		}
	if (ok && queens == 8)
		cout << "valid" << endl;
	else
		cout << "invalid" << endl;

	return 0;
	}