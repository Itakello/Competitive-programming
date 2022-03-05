#include <bits/stdc++.h>
using namespace std;

void split(string s, string* vals) {
	int ind = 0;
	size_t pos = 0;
	while ((pos = s.find(' ')) != string::npos) {
		vals[ind++] = s.substr(0, pos);
		s.erase(0, pos + 1);
		}
	vals[ind] = s;
	}