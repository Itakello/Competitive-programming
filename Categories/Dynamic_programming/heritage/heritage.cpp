//https://open.kattis.com/contests/kzhiwr/problems/heritage
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <string.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

map<string, int> mp;
int N;
string word;
vector<int> DP;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	/* ios::sync_with_stdio(false);
	cin.tie(0); */
	cin >> N >> word;

	string tWord;
	int tVal;
	int dim = word.length();
	DP.assign(dim + 1, 0);
	for (int i = 0; i < N; i++) {
		cin >> tWord >> tVal;
		mp.insert(MP(tWord, tVal));
		}

	for (int i = 0; i < dim; i++) {
		for (auto it : mp) {
			if (word.rfind(it.F, i) == i) {
				if (DP[i] > 0)
					DP[i + it.F.length()] += (DP[i] * it.S);
				else
					DP[i + it.F.length()] += it.S;
				}
			}
		}

	/* for (int i = 0; i < DP.size(); i++) {
		cerr << word[i] << DP[i] << " ";
		}
	cerr << endl; */
	cout << DP[word.length()] << endl;

	return 0;
	}