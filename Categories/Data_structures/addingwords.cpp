//https://open.kattis.com/contests/mv3zwo/problems/addingwords
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

unordered_map <string, int> um1;
unordered_map <int, string> um2;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	string cmd, name;
	char op;
	int val;
	while (cin >> cmd) {
		if (cmd == "def") {
			cin >> name >> val;
			if (um1.count(name) > 0) { um2.erase(um1[name]); }
			um1[name] = val;
			um2[val] = name;
			}
		if (cmd == "calc") {
			int res = 0;
			bool unk = false;
			cin >> name;
			cout << name << " ";
			if (um1.find(name) == um1.end())
				unk = true;
			else
				res += um1[name];
			do {
				cin >> op;
				cout << op << " ";
				if (op != '=') {
					cin >> name;
					cout << name << " ";
					if (um1.find(name) == um1.end()) {
						unk = true;
						}
					else
						switch (op) {
								case '+':
									res += um1[name];
									break;
								case '-':
									res -= um1[name];
									break;
							}
					}
				} while (op != '=');
				if (unk || um2.find(res) == um2.end())
					cout << "unknown" << endl;
				else
					cout << um2[res] << endl;
			}
		if (cmd == "clear") {
			um1.clear();
			um2.clear();
			}
		}
	return 0;
	}