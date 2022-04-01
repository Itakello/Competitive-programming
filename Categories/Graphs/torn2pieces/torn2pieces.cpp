// https://open.kattis.com/contests/z4dra4/problems/torn2pieces
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

unordered_map<string, set<string>> adj;
unordered_map<string, bool> visited;
unordered_map<string, string> parent;
string start, dest;
bool found = false;

void printPath() {
	found = true;
	cout << start << " ";
	string curr = start;
	while (parent[curr] != dest) {
		curr = parent[curr];
		cout << curr << " ";
		}
	cout << dest << endl;
	}

void dfs(string u) {
	//cout << u << "-";
	if (u == dest) {
		printPath();
		return;
		}
	if (visited[u])
		return;
	visited[u] = true;
	for (auto& it : adj[u]) {
		parent[u] = it;
		dfs(it);
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	string line, word1, word2;
	int n;
	cin >> n;
	getline(cin, line);
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		istringstream iss(line);
		iss >> word1;
		while (iss >> word2) {
			adj[word1].insert(word2);
			adj[word2].insert(word1);
			}
		}
	for (auto& it : adj) {
		visited[it.first] = false;
		parent[it.first] = "-";
		}

	cin >> start >> dest;
	dfs(start);
	if (!found)
		cout << "no route found" << endl;

	return 0;
	}