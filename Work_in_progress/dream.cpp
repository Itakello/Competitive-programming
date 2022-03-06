//https://open.kattis.com/contests/mv3zwo/problems/dream
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

int n;
unordered_set<string> events;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		string s;
		switch (c) {
				case 'E':
					cin >> s;
					events.insert(s);
					break;
				case 'D':
					int r;
					cin >> r;
					for (int i = 0; i < r; i++) {
						events.erase(events.begin());
						}
					break;
				case 'S':
					int k;
					cin >> k;
					vector<string> tmp;
					for (int i = 0; i < k; i++) {
						cin >> s;
						if (s[0] != '!')
							tmp.push_back(s);
						}
					bool ok = true;
					int min_pos = events.size() - 1;
					for (int i = 0; i < tmp.size(); i++) {
						auto it = events.find(tmp[i]);
						if (it == events.end()) {
							ok = false;
							break;
							}
						else {
							min_pos = min(min_pos, (int)distance(events.begin(), it));
							}
						}
					/* for (int i = 0; i < tmp.size(); i++) {
						cout << tmp[i] << " ";
						}
					cout << min_pos << endl;
					for (auto x : events) {
						cout << x << " ";
						}
					cout << endl; */
					if (!ok)
						cout << "Plot Error" << endl;
					else if (events.size() == min_pos || tmp.size() == 0 || min_pos == 0)
						cout << "Yes" << endl;
					else
						cout << min_pos << " Just A Dream" << endl;
					break;
			}
		}

	return 0;
	}