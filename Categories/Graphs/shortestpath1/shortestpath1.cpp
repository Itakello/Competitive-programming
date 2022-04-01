// https://open.kattis.com/contests/z4dra4/problems/shortestpath1
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int n, m, q, s, u, v, w;
vector<vector<pair<int, int>>> adj; // adj-weight

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m >> q >> s && n != 0 || m != 0 || q != 0 || s != 0) {
		adj.clear();
		adj.resize(n);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			adj[u].push_back(make_pair(v, w));
			}
		vector<int> dist(n, -1);
		queue<int> Q;
		Q.push(s);
		dist[s] = 0;
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i].first;
				if (dist[v] == -1 || dist[v] > dist[u] + adj[u][i].second) {
					Q.push(v);
					dist[v] = dist[u] + adj[u][i].second;
					}
				}
			}
		int obj;
		for (int i = 0; i < q; i++) {
			cin >> obj;
			if (dist[obj] != -1)
				cout << dist[obj];
			else
				cout << "Impossible";
			cout << endl;
			}
		cout << endl;
		}
	return 0;
	}