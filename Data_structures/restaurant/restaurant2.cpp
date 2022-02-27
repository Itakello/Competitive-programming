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

int pile1, pile2;

// Ex : DROP 2 100   : 1 2 100
// Ex : MOVE 1->2 10 : 2 1 10
// Ex : TAKE 2 100   : 3 2 100
void print(int action, int curr, int num) {
	int from = curr - 1, to = 2 - curr;
	if (action == 1) {
		cout << "DROP " << curr;
		pile1 += num;
		}
	if (action == 2) {
		cout << "MOVE " << curr << "->" << 3 - curr;
		pile1 -= num;
		pile2 += num;
		}
	if (action == 3) {
		cout << "TAKE " << curr;
		pile2 -= num;
		}
	cout << " " << num << endl;
	}

int main(int argc, char const* argv[]) {
	//ifstream cin("sample.in");
	//ofstream cout("output.txt");
	int n, m;
	string action;
	cin >> n;
	do {
		pile1 = 0;
		pile2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> action >> m;
			if (action == "DROP")
				print(1, 1, m);
			if (action == "TAKE") {
				if (pile2 >= m)
					print(3, 2, m);
				else {
					int tmp = pile2;
					if (pile2 > 0)
						print(3, 2, pile2);
					print(2, 1, pile1);
					print(3, 2, m - tmp);
					}
				}
			}
		cin >> n;
		cout << endl;
		} while (n > 0);

		return 0;
	}