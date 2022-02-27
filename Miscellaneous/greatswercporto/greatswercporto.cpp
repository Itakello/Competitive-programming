// https://open.kattis.com/problems/greatswercporto
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <windows.h>

using namespace std;


int getIndex(set<char> S, char c) {
	int index = 0;
	for (auto u : S) {
		if (u == c) {
			return index;
			}
		index++;
		}
	return -1;
	}

int main(int argc, char const* argv[]) {
	set <char> s;
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		for (char c : v[i]) {
			s.insert(c);
			}
		}
	int count = 0;
	int numbs[] = { 0,1,2,3,4,5,6,7,8,9 };
	do {
		// Test prints
		/* for (char c : s)
			cerr << c << " ";
		cerr << endl;
		for (int i : numbs)
			cerr << i << " ";
		cerr << endl; */

		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			int curr = 0;
			for (int j = 0; j < v[i].length(); j++) {
				char letter = v[i].at(j);
				int pos = getIndex(s, letter);
				int digit = numbs[pos];
				//cerr << "l:" << letter << " p:" << pos << " d:" << digit << endl;
				if (digit == 0 && j == 0) {
					goto exit;
					}
				else {
					curr += digit * pow(10, v[i].size() - (j + 1));
					}
				}
			if (i != v.size() - 1) {
				sum += curr;
				}
			else if (sum == curr)
				count++;
			//cerr << "Curr:" << curr << " Sum:" << sum << " Count:" << count << endl;
			}

	exit:
		count = count;
		//Sleep(10);
		} while (next_permutation(numbs, numbs + 10));
		cout << count << endl;
		return 0;
	}
