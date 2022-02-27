// https://open.kattis.com/contests/y3torr/problems/fruitbaskets
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> fruit;
long long tot;

int main(int argc, char** argv) {
	long long bis, tris;
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	cin >> N;
	fruit.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> fruit.at(i);
		tot += fruit.at(i) * (pow(2, N - 1));
		}

	sort(fruit.rbegin(), fruit.rend());

	for (int i = 0; i < N; i++) {
		if (fruit.at(i) < 200) {
			tot -= fruit.at(i);
			for (int j = i + 1; j < N; j++) {
				bis = fruit.at(i) + fruit.at(j);
				if (bis < 200) {
					tot -= bis;
					for (int k = j + 1; k < N; k++) {
						tris = bis + fruit.at(k);
						if (tris < 200)
							tot -= tris;
						}
					}
				}
			}
		}

	cout << tot << endl;
	return 0;
	}