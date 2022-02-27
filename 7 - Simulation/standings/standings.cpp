//https://open.kattis.com/contests/q8dwem/problems/standings
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

int T, N;
vi nums;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		nums.clear();
		nums.resize(N);
		for (int j = 0; j < N; j++) {
			string name;
			cin >> name >> nums[j];
			}
		ll ris = 0;
		sort(nums.begin(), nums.end());

		for (int j = 0; j < nums.size(); j++) {
			ris += abs((j + 1) - nums[j]);
			}
		cout << ris << endl;
		}
	return 0;
	}