//https://open.kattis.com/contests/q8dwem/problems/engineeringenglish
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

set<string> words;

string to_low(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) >= 'A' && s.at(i) <= 'Z')
			s.at(i) += ('a' - 'A');
		}
	return s;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s) {
		string sT = to_low(s);
		// cout << words.size() << " ";
		//cout << s << sT;
		if (words.find(sT) != words.end()) {
			cout << ".";
			}
		else {
			cout << s;
			words.insert(sT);
			}
		cout << " ";
		}

	return 0;
	}