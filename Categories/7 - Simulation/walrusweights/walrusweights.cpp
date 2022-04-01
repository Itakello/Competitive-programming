//https://open.kattis.com/contests/q8dwem/problems/walrusweights
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

#define k 1000

int N;
vi nums;
vector<bool> w(k * 2, false);

int RetClose(int a, int b, int s) {
	if (abs(a - s) < abs(b - s))
		return a;
	else if (abs(a - s) == abs(b - s))
		return max(a, b);
	else
		return b;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	nums.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		}

	for (int i = 0; i < N; i++) {
		int x = nums[i];
		for (int j = w.size() - 1; j >= 0; j--) {
			if (w[j] == true && ((j + x) < w.size()))
				w[j + x] = true;
			}
		w[x] = true;
		}

	int nextLargest = 2001;
	for (int i = 1000; i < w.size(); i++) {
		if (w[i] == true) {
			nextLargest = i;
			break;
			}
		}
	int nextSmallest = -1;
	for (int i = 1000; i >= 0; i--) {
		if (w[i] == true) {
			nextSmallest = i;
			break;
			}
		}
	if (abs(nextLargest - k) <= abs(nextSmallest - k)) {
		cout << nextLargest;
		}
	else
		cout << nextSmallest;


	return 0;
	}