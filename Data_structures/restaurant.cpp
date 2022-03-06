//https://open.kattis.com/contests/mv3zwo/problems/restaurant
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

int pile1, pile2;

void print(int action, int curr, int num) {
	int from = curr - 1, to = 2 - curr;
	if (action == 1) {
		cout << "DROP " << curr;
		pile1 += num;
		}
	if (action == 2) {
		cout << "MOVE " << curr << "->" << 3 - curr;
		pile1 -= num;
		pile2 += num;
		}
	if (action == 3) {
		cout << "TAKE " << curr;
		pile2 -= num;
		}
	cout << " " << num << endl;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	string action;
	cin >> n;
	do {
		pile1 = 0;
		pile2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> action >> m;
			if (action == "DROP")
				print(1, 1, m);
			if (action == "TAKE") {
				if (pile2 >= m)
					print(3, 2, m);
				else {
					int tmp = pile2;
					if (pile2 > 0)
						print(3, 2, pile2);
					print(2, 1, pile1);
					print(3, 2, m - tmp);
					}
				}
			}
		cin >> n;
		cout << endl;
		} while (n > 0);
		return 0;
	}