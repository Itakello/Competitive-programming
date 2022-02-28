//https://open.kattis.com/contests/pp9wfr/problems/vivoparc
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 105

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n;
vector<vi> adj(MAXN);
vi col(MAXN, 0);
set<string> st;

bool isSafe(int u, int c) {
	for (int i = 0; i < adj[u].size(); i++) {
		if (i > u)
			break;
		if (c == col[adj[u][i]])
			return false;
		}
	return true;
	}

void colGraph(int u) {
	if (u == n) {
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " " << col[i] << endl;
			}
		exit(0);
		}
	for (int c = 1; c <= 4; c++) {
		if (isSafe(u, c)) {
			col[u] = c;
			colGraph(u + 1);
			col[u] = 0;
			}
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x, y;
	char dash;
	while (cin >> x >> dash >> y) {
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
		}
	for (int i = 0; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
		}
	colGraph(0);
	return 0;
	}