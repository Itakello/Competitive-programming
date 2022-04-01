//https://open.kattis.com/contests/pp9wfr/problems/ballotboxes
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

struct City {
	int people, boxes = 1;
	};

struct CompareCity {
	bool operator()(const City& a, const City& b) const {
		return ceil(a.people / double(a.boxes)) < ceil(b.people / double(b.boxes));
		};
	};

int n, b;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> b;
	while (n != -1) {
		// cout << "ok";
		priority_queue<City, vector<City>, CompareCity> pq;
		City c;
		for (int i = 0; i < n; i++) {
			cin >> c.people;
			pq.push(c);
			}
		b -= n;
		while (b > 0) {
			c = pq.top(); pq.pop();
			c.boxes++;
			b--;
			pq.push(c);
			}
		cout << ceil(pq.top().people / double(pq.top().boxes)) << endl;
		cin >> n >> b;
		}
	return 0;
	}