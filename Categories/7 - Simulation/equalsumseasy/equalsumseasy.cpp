//https://open.kattis.com/contests/q8dwem/problems/equalsumseasy
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

vi nums;
unordered_map <ll, bitset<20>> um;
bitset<20> sel;

void find() {
	ll sum = 0;
	for (int i = 0; i < 20; i++) {
		if (sel.test(i))
			sum += nums[i];
		}
	// cout << sum << endl;
	if (um.count(sum) == 0)
		um.insert(MP(sum, sel));
	else {
		// cout << "OPS";
		bitset<20> sel2 = um.find(sum)->S;
		for (int i = 0; i < 20; i++) {
			if (sel2.test(i))
				cout << nums[i] << " ";
			}
		cout << endl;
		for (int i = 0; i < 20; i++) {
			if (sel.test(i))
				cout << nums[i] << " ";
			}
		cout << endl;
		return;
		}
	if (sel.all()) {
		cout << "Impossibile\n";
		return;
		}
	unsigned long diff = sel.to_ulong() + bitset<20>(1).to_ulong();
	sel = bitset<20>(diff);
	// cout << "OK";
	find();
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":" << endl;
		cin >> N;
		nums.clear();
		nums.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
			}
		// cout << nums[0] << endl;
		sel.reset();
		um.clear();
		// cout << sel << endl;
		find();
		}

	return 0;
	}