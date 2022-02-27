//https://open.kattis.com/contests/pp9wfr/problems/guessthedatastructure
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

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int in, v;
	while (cin >> n) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool bs = true, bq = true, bpq = true;
		for (int i = 0; i < n; i++) {
			cin >> in >> v;
			// cout << in << " - " << v << endl;
			if (in == 1) {
				s.push(v);
				q.push(v);
				pq.push(v);
				}
			else if (!s.empty()) {
				if (s.top() != v)
					bs = false;
				if (q.front() != v)
					bq = false;
				if (pq.top() != v)
					bpq = false;
				s.pop(); q.pop(); pq.pop();
				}
			else {
				bs = false; bq = false; bpq = false;
				}
			}
		if (!bs && !bq && !bpq)
			cout << "impossible" << endl;
		else {
			if (bs && bq || bs && bpq || bq && bpq)
				cout << "not sure" << endl;
			else {
				if (bs)
					cout << "stack" << endl;
				if (bq)
					cout << "queue" << endl;
				if (bpq)
					cout << "priority queue" << endl;
				}
			}
		}
	return 0;
	}