//https://open.kattis.com/contests/q8dwem/problems/dominoes2
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

int n, m, l;
vector<vi> adj;
vi visited;

void dfs(int u) {
	// cout << "|" << u << "|" << visited[u] << endl;
	if (visited[u])
		return;
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		dfs(v);
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m >> l;
		adj.clear();
		adj.resize(n + 1);
		// visited.resize(n);
		visited.assign(n + 1, false);
		/* cout << "VISITED" << " " << T << " \n";
		for (int j = 0; j < visited.size(); j++) {
			cout << visited[j] << " ";
			}
		cout << endl; */

		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			}
		for (int j = 0; j < l; j++) {
			int st;
			cin >> st;
			dfs(st);
			}
		cout << count(visited.begin(), visited.end(), true) << endl;
		}

	return 0;
	}