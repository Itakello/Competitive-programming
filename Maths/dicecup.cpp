// https://open.kattis.com/contests/pp9wfr/problems/dicecup
#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {
	int N, M;
	cin >> N >> M;
	int res[N + M + 1] = { 0 };
	int max = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			res[i + j]++;
			if (res[i + j] > max)
				max = res[i + j];
			}
	for (int i = 2; i <= N + M; i++) {
		if (res[i] == max)
			cout << i << endl;
		}

	return 0;
	}
