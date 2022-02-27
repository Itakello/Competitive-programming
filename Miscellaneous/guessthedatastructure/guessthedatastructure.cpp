// https://open.kattis.com/contests/pp9wfr/problems/guessthedatastructure
#include <iostream>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, char const* argv[]) {
	int N, type, val;
	ifstream cin("guessthedatastructure_sample.in");
	while (cin >> N) {
		queue <int> q;
		priority_queue <int> pq;
		stack <int> s;
		bool qB = true, pqB = true, sB = true;

		for (int i = 0; i < N; i++) {
			cin >> type >> val;
			if (type == 1) {
				q.push(val);
				pq.push(val);
				s.push(val);
				}
			else if (type == 2) {
				if (!q.empty()) {
					if (val == q.front()) {
						q.pop();
						}
					else {
						qB = false;
						}
					if (val == pq.top()) {
						pq.pop();
						}
					else {
						pqB = false;
						}
					if (val == s.top()) {
						s.pop();
						}
					else {
						sB = false;
						}
					}
				else {
					sB = false;
					qB = false;
					pqB = false;
					}
				}
			}

		// Print
		if ((qB && pqB) || (qB && sB) || (pqB && sB)) {
			cout << "not sure" << endl;
			}
		else if (qB)
			cout << "queue" << endl;
		else if (pqB)
			cout << "priority queue" << endl;
		else if (sB)
			cout << "stack" << endl;
		else
			cout << "impossible" << endl;
		}
	return 0;
	}
