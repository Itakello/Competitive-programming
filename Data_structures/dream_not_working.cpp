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
unordered_map<string, int> events;
stack<string> st;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	char c;
	string event;
	for (int i = 0; i < n; i++) {
		cin >> c;
		switch (c) {
				case 'E':
					cin >> event;
					events[event] = st.size();
					st.push(event);
					break;
				case 'D':
					int r;
					cin >> r;
					while (r--) {
						event = st.top(); st.pop();
						events.erase(event);
						}
					break;
				case 'S':
					int k;
					cin >> k;
					bool ok = true;
					int must = -1, mustnt = st.size();
					for (int i = 0; ok && i < k; i++) {
						cin >> event;
						// cout << must << " " << mustnt << endl;
						if (event[0] == '!') {
							event = event.substr(1, event.size());
							auto it = events.find(event);
							if (it != events.end()) {
								if (it->second > must)
									mustnt = min(mustnt, it->second);
								else
									ok = false;
								}
							}
						else {
							auto it = events.find(event);
							if (it != events.end())
								if (it->second < mustnt)
									must = max(must, it->second);
								else
									ok = false;
							else
								ok = false;
							}
						}

					if (!ok)
						cout << "Plot Error" << endl;
					else if (mustnt == st.size())
						cout << "Yes" << endl;
					else
						cout << events.size() - mustnt << " Just A Dream" << endl;
					break;
			}
		/* cout << "---" << endl;
		for (auto x : events)
			cout << x.first << " " << x.second << endl;
		cout << "---" << endl; */
		}

	return 0;
	}