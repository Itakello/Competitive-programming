// https://open.kattis.com/contests/y3torr/problems/nineknights
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

bool boardKn[6][6] = { false };
bool boardBan[6][6] = { false };

void setBan(int x, int y) {
	if ((x >= 1 && x <= 5) && (y >= 1 && y <= 5))
		boardBan[x][y] = true;
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	char c;
	int count = 0;
	for (int x = 1; x <= 5; x++) {
		for (int y = 1; y <= 5; y++) {
			cin >> c;
			if (c == 'k') {
				count++;
				boardKn[x][y] = true;
				setBan(x - 1, y - 2);
				setBan(x + 1, y - 2);
				setBan(x - 2, y - 1);
				setBan(x + 2, y - 1);
				setBan(x - 2, y + 1);
				setBan(x - 1, y + 2);
				setBan(x + 1, y + 2);
				setBan(x + 2, y + 1);
				}
			}
		}
	bool inv = false;
	for (int x = 1; x <= 5; x++) {
		for (int y = 1; y <= 5; y++) {
			if (boardKn[x][y] && boardBan[x][y])
				inv = true;
			}
		}
	/* cout << "kn" << endl;
	for (int x = 1; x <= 5; x++) {
		for (int y = 1; y <= 5; y++) {
			cout << boardKn[x][y] << " ";
			}
		cout << endl;
		}
	cout << "ban" << endl;
	for (int x = 1; x <= 5; x++) {
		for (int y = 1; y <= 5; y++) {
			cout << boardBan[x][y] << " ";
			}
		cout << endl;
		} */
	if (inv || count != 9)
		cout << "invalid" << endl;
	else
		cout << "valid" << endl;
	return 0;
	}