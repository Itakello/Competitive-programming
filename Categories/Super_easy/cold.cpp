// https://open.kattis.com/contests/pp9wfr/problems/cold
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int val[N];
	int res;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
		if (val[i] < 0)
			res++;
		}
	cout << res;
	return 0;
	}
