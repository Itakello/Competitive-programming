//https://open.kattis.com/contests/q8dwem/problems/gold
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int W, H;
int f = 0;
char grid[50][50];
bool vis[50][50];

bool checkTrap(int x, int y) {
	int posX[] = { -1, 0, 1, 0 };
	int posY[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int xT = x + posX[i];
		int yT = y + posY[i];
		if (xT >= 0 && yT >= 0 && xT < 50 && yT < 50) {
			if (grid[xT][yT] == 'T')
				return true;
			}
		}
	return false;
	}

void find(ii pos) {
	int posX[] = { -1, 0, 1, 0 };
	int posY[] = { 0, -1, 0, 1 };
	for (int i = 0; i < 4; i++) {
		int x = pos.F + posX[i];
		int y = pos.S + posY[i];
		if (grid[x][y] != '#' && !vis[x][y]) {
			vis[x][y] = true;
			if (grid[x][y] == 'G')
				f++;
			if (!checkTrap(x, y))
				find(MP(x, y));
			}
		}

	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis, false, sizeof(vis));
	ii start;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'P') {
				vis[i][j] = true;
				start = MP(i, j);
				}
			}
		}
	if (!checkTrap(start.F, start.S))
		find(start);
	cout << f << endl;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cerr << grid[i][j] << " ";
			}
		cerr << endl;
		}

	return 0;
	}