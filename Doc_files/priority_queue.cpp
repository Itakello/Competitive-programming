#include <bits/stdc++.h>
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

int main(int argc, char const* argv[]) {
	priority_queue<City, vector<City>, CompareCity> cities;
	return 0;
	}
