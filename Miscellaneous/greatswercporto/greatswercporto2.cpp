#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

unordered_map<char, int> m;
vector<string> w;
int N;

/* int rec(set<char>::iterator it, vector<int>& numbs) {
	if (it != s.end()) {
		for (int i = 0; i <= 9; i++) {
			if (find(numbs.begin(), numbs.end(), i) == numbs.end()) { // numbs doesn't contain i
				numbs.push_back(i);
				rec(++it, numbs);
				numbs.pop_back();
				}
			}
		}
	else { // Sostituisco e calcolo somma + check
		vector<int> ok;
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				v[i].at(j) = (char)numbs[j];
				}
			cerr << v[i] << endl;
			ok.push_back(stoi(v[i]));
			}
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += ok[i];
		if (sum == ok[N])
			return 1;
		}
	return 0;
	} */

int findCount() {
	int count = 0;
	for (int i = 1; i <= 9; i++) {
		char c = *s.begin();
		vector<int> numbs;
		numbs.push_back(i);
		//cerr << numbs[0] << " " << c;
		count += rec(++s.begin(), numbs);
		}
	return count;
	}

int main(int argc, char const* argv[]) {
	cin >> N;
	w.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> w[i];
		for (char c : w[i]) {
			m.insert(make_pair(c, -1));
			}
		}
	cout << findCount() << endl;
	return 0;
	}
