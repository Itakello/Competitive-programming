// https://open.kattis.com/contests/mv3zwo/problems/restaurant
#include <bits/stdc++.h>
using namespace std;

// Greedy NON funziona, cioè metterli subito in quello ordinato, se ci stanno
// 
// Take plates from the waiter and pass to the dishwasher when he requests them
// Wash in the same order of arrival
// TODO : taken m => move x + move y + taken m
// TODO : drop m => move x + move y + drop m
// x+y <= 5m

int pile[2];

// Ex : DROP 2 100   : 1 2 100
// Ex : MOVE 1->2 10 : 2 1 10
// Ex : TAKE 2 100   : 3 2 100
void print(int action, int curr, int num) {
	int from = curr - 1, to = 2 - curr;
	if (action == 1) {
		cout << "DROP " << curr;
		pile[from] += num;
		}
	if (action == 2) {
		cout << "MOVE " << curr << "->" << 3 - curr;
		pile[from] -= num;
		pile[to] += num;
		}
	if (action == 3) {
		cout << "TAKE " << curr;
		pile[from] -= num;
		}
	cout << " " << num << endl;
	}

int main(int argc, char const* argv[]) {
	int n, m;
	string action;
	cin >> n;
	do {
		memset(pile, 0, 2);
		for (int i = 0; i < n; i++) {
			cin >> action >> m;
			int limit = 6 * m;
			if (action == "DROP") { // Drop on pile 2
				if (pile[0] == 0) { // Pile 1 empty
					if (pile[1] == 0 || m * 2 + pile[1] < limit) { // Enough to D2, M2->1
						print(1, 2, m);
						print(2, 2, pile[1]);
						}
					else if (m + pile[1] < limit) { // Enough to M2->1, D2
						print(2, 2, pile[1]);
						print(1, 2, m);
						}
					else {
						print(1, 2, m); // D2
						}
					}
				else { // Pile 1 not empty
					if (pile[1] == 0 && (pile[0] * 2 + m * 2) < limit) { // Enough to M1->2, D2, M2->1
						print(2, 1, pile[0]);
						print(1, 2, m);
						print(2, 2, pile[1]);
						}
					else { // D2
						print(1, 2, m);
						}
					}

				}
			else { // Take from pile 1
				if (pile[0] == 0) { // Empty pile 1: M2->1, T1
					print(2, 2, pile[1]);
					print(3, 1, m);
					}
				else if (pile[0] < m) { // Not sufficient pile 1: T1, M2->1, T1(rim)
					int tmp = pile[0];
					print(3, 1, tmp);
					print(2, 2, pile[1]);
					print(3, 1, m - tmp);
					}
				else { // Sufficient pile 1
					print(3, 1, m);
					if (pile[1] <= limit - m && pile[1] != 0) // We can still move
						print(2, 2, pile[1]);
					}
				}
			}
		cin >> n;
		cout << endl;
		} while (n > 0);

		return 0;
	}