// https://open.kattis.com/contests/pp9wfr/problems/frosting
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
	int N, y = 0, p = 0, w = 0;
	cin >> N;
	int A[3] = { 0 }, B[3] = { 0 };
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A[i % 3] += tmp;
		}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		B[i % 3] += tmp;
		}
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			int n = (i + j) % 3;
			int val = A[i - 1] * B[j - 1];
			if (n == 0)
				y += val;
			else if (n == 1)
				p += val;
			else
				w += val;
			}
		}
	/* y = A[1] * B[0] + A[0] * B[1] + A[2] * B[2];
	p = A[2] * B[0] + A[1] * B[1] + A[0] * B[2];
	w = A[0] * B[0] + A[2] * B[1] + A[1] * B[2]; */
	cout << y << " " << p << " " << w << endl;
	return 0;
	}
