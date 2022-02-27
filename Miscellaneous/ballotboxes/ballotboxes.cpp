// https://open.kattis.com/contests/pp9wfr/problems/ballotboxes
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct City {
	int people;
	int ballots = 1;
	};
struct CompareCity {
	bool operator()(const City& a, const City& b) {
		return a.people / a.ballots < b.people / b.ballots;
		};
	};

int main() {
	int N, M;

	std::cin >> N >> M;
	do {
		priority_queue<City, vector<City>, CompareCity> cities;

		City c;
		for (int i = 0; i < N; i++) {
			std::cin >> c.people;
			cities.push(c);
			M--;
			}
		/* while (!cities.empty()) {
			cerr << "\t" << cities.top().people / cities.top().ballots;
			cities.pop();
			}
		cerr << endl; */

		while (M > 0) {
			c = cities.top();
			cities.pop();
			c.ballots++;
			cities.push(c);
			M--;
			}
		std::cout << cities.top().people / cities.top().ballots << endl;

		while (!cities.empty()) {
			cerr << "\t" << cities.top().people / cities.top().ballots;
			cities.pop();
			}
		cerr << endl;
		std::cin >> N >> M;
		} while (N != -1 || M != -1);
		return 0;
	}