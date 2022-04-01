//https://open.kattis.com/contests/mv3zwo/problems/deduplicatingfiles
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 10005
#define l 50

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int XorAscii(string str, int len) {
	int ans = int(str[0]);
	for (int i = 1; i < len; i++) {
		ans = (ans ^ int(str[i]));
		}
	return ans;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	do {
		cin.ignore(256, '\n');
		unordered_map<int, vector<string>> hashes; // hash -> [elems, collis]

		int diff_f = 0, diff_h = 0;

		for (int i = 0; i < n; i++) {
			string str;
			getline(cin, str);
			int h = XorAscii(str, str.length());
			//cout << "hash-val:" << h << endl;
			auto it = hashes.find(h);

			if (it == hashes.end()) { // Never seen hash
				diff_f++;
				vector<string> tmp;
				tmp.push_back(str);
				hashes[h] = tmp; // hash -> [elems, collis]
				}
			else { // Already seen hash
				it->second.push_back(str);
				bool newEl = true;
				int curr = it->second.size() - 1;
				for (int i = 0; i < curr; i++)
					if (it->second[i] == str) {
						newEl = false;
						break;
						}
				if (newEl)
					diff_f++;
				}
			}
		for (auto it = hashes.begin(); it != hashes.end(); it++) {
			for (int i = 0; i < it->second.size(); i++) {
				for (int j = 0; j < it->second.size() && j != i; j++) {
					if (it->second[i].compare(it->second[j]))
						diff_h++;
					}
				}
			}
		cout << diff_f << " " << diff_h << endl;
		cin >> n;
		} while (n > 0);
		return 0;
	}