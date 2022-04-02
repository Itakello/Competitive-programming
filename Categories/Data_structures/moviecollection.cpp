//https://open.kattis.com/problems/moviecollection
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

// Last Significant Bit on
int LSOne(int x) {
	return (x & (-x));
	}

class FenwickTree {
private:
	vi ft;
public:
	FenwickTree(int n) { // Initialize to zeros
		ft.assign(n + 1, 0);
		}
	void printFt() {
		for (size_t i = 0; i < ft.size(); i++) {
			cout << ft[i] << ' ';
			}
		cout << endl;
		}
	// Point/range update - Range query
	int rsq(int b) { // returns RSQ(1, b)
		int sum = 0;
		for (; b; b -= LSOne(b)) // Ex: b=6 -> 6,4,0,0
			sum += ft[b];
		return sum;
		}

	void add(int k, int val) { // add single index
		for (; k < (int)ft.size(); k += LSOne(k))
			ft[k] += val;
		}
	};

int n, m, r, x;
vi in(MAXN);

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> m >> r;
		FenwickTree ft(MAXN * 2);
		for (size_t i = 1; i <= m; i++) {
			ft.add(100000 + i, 1);
			in[i] = 100000 + i;
			}
		for (size_t i = 0; i < r; i++) {
			cin >> x;
			cout << ft.rsq(in[x] - 1) << " ";
			ft.add(in[x], -1); // sub from head to curr, 1,2,3,etc...
			in[x] = 100000 - i; // move curr to the head
			ft.add(in[x], 1); // update the stack
			}
		cout << endl;
		}
	return 0;
	}