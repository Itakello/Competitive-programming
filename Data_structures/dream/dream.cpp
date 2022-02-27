#include <bits/stdc++.h>

using namespace std;

void scan(int& n);

void scan(string& s);

void print(int n);

void print(string s);

stack<string>events;
unordered_map<string, int> mp;

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	int N, k, r, count = 0;
	string form, event;
	scan(N);
	for (int i = 0; i < N; i++) {
		scan(form);
		if (form == "E") { // new event happened
			scan(event);
			events.push(event);
			mp[event] = count++;
			}
		if (form == "D") { // last r events were dreams
			scan(r);
			for (int j = 0; j < r; j++) {
				mp.erase(events.top());
				events.pop();
				count--;
				}
			}
		if (form == "S") { // Event in a scenario, !means not happened
			scan(k);
			int tmp = 0;
			for (int j = 0; j < k; j++) {
				scan(event);
				if (event.at(0) == '!') {
					if (mp.count(event)) {
						print("OK");
						int dim = mp.size();
						tmp = max(tmp, dim - mp[event]);
						}
					}
				else {
					if (!mp.count(event)) {
						print("Plot Error\n");
						tmp = -1;
						break;
						}
					}
				}
			if (tmp == 0)
				print("Yes\n");
			if (tmp > 0) {
				print(tmp);
				print(" Just a Dream\n");
				}
			}
		}
	return 0;
	}


void scan(int& n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
		}
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
		}
	if (neg) { n *= -1; }
	}

void scan(string& s) {
	s = "";
	char c = getchar();
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	for (; c != ' ' && c != '\n' && c != '\t'; c = getchar()) {
		s += c;
		}
	}

void print(int n) {
	if (n == 0) {
		putchar('0');
		return;
		}
	if (n < 0) {
		putchar('-');
		n *= -1;
		}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
		}
	for (int i = s.length() - 1; i >= 0; i--) {
		putchar(s[i]);
		}
	}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) {
		putchar(s[i]);
		}
	}
