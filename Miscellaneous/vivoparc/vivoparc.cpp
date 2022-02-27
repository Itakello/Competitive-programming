// https://open.kattis.com/contests/pp9wfr/problems/vivoparc
#include <iostream>
#include <string>
#include <algorithm>
#define colors 4

using namespace std;

vector<pair<vector<int>, int>> adj;

void printGraph() {
	for (int i = 0; i < adj.size(); i++) {
		cout << i + 1 << " " << adj[i].second << endl;
		}
	}

bool isSafe(int ind, int col_curr) {
	for (int n : adj[ind].first)
		if (adj[n].second == col_curr)
			return false;
	return true;
	}

bool graphColoringUtil(int ind) {
	if (ind == adj.size()) {
		return true;
		}
	else {
		for (int c = 1; c <= colors; c++) {
			if (isSafe(ind, c)) {
				adj[ind].second = c;
				if (graphColoringUtil(ind + 1) == true)
					return true;
				adj[ind].second = 0;
				}
			}
		}
	return false;
	}

bool graphColoring() {
	if (graphColoringUtil(0) == false) {
		//cout << "Solution does not exist";
		return false;
		}
	printGraph();
	return true;
	}

int main(int argc, char const* argv[]) {
	int N;
	string s;
	cin >> N;
	adj.resize(N);
	while (cin >> s) {
		int x = stoi(s.substr(0, 1)) - 1;
		int y = stoi(s.substr(2, 3)) - 1;
		adj[x].first.push_back(y);
		adj[x].second = 0;
		adj[y].first.push_back(x);
		adj[y].second = 0;
		}
	graphColoring();

	return 0;
	}
