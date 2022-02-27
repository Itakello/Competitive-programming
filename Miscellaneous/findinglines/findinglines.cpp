#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[]) {
	int n, p;
	cin >> n >> p;
	int n_p = ceil((n * p) / 100);
	int coordinates[n][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> coordinates[i][j];
			}
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n && j != i; j++) {
			/* code */
			}
		}
	return 0;
	}
