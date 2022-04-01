//https://open.kattis.com/contests/pp9wfr/problems/greatswercporto
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

int n, res = 0, pos = 0;
vector<char> all;
vector<bool> chosen(10, false);
vector<int> permutation;
unordered_set<char> firstletter, seen;
unordered_map<char, int> cost1, cost2;

void search() {
	if (permutation.size() == all.size()) {
		int total1 = 0;
		int total2 = 0;

		for (int i = 0; i < all.size(); i++) {
			total1 += cost1[all[i]] * permutation[i];
			total2 += cost2[all[i]] * permutation[i];
			}

		if (total1 == total2) {
			res++;
			}
		}
	else {
		for (int i = 0; i < chosen.size(); i++) {
			if (chosen[i]) {
				continue;
				}
			if (i == 0 && firstletter.count(all[pos]) > 0) {
				continue;
				}
			pos++;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			permutation.pop_back();
			chosen[i] = false;
			pos--;
			}
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		firstletter.insert(s.front());
		reverse(s.begin(), s.end());
		for (int j = 0; j < s.size(); j++) {
			if (i < n - 1)
				cost1[s[j]] += pow(10, j);
			else
				cost2[s[j]] += pow(10, j);
			}
		for (auto j : s) {
			seen.insert(j);
			}
		}

	for (auto i : seen) {
		all.push_back(i);
		}
	search();

	cout << res << endl;

	return 0;
	}