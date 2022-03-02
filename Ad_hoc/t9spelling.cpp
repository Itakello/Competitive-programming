//https://open.kattis.com/contests/uawr9g/problems/t9spelling
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;

int n;
map<char, string> mp;

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	mp.insert({ 'a', "2" });
	mp.insert({ 'b', "22" });
	mp.insert({ 'c', "222" });
	mp.insert({ 'd', "3" });
	mp.insert({ 'e', "33" });
	mp.insert({ 'f', "333" });
	mp.insert({ 'g', "4" });
	mp.insert({ 'h', "44" });
	mp.insert({ 'i', "444" });
	mp.insert({ 'j', "5" });
	mp.insert({ 'k', "55" });
	mp.insert({ 'l', "555" });
	mp.insert({ 'm', "6" });
	mp.insert({ 'n', "66" });
	mp.insert({ 'o', "666" });
	mp.insert({ 'p', "7" });
	mp.insert({ 'q', "77" });
	mp.insert({ 'r', "777" });
	mp.insert({ 's', "7777" });
	mp.insert({ 't', "8" });
	mp.insert({ 'u', "88" });
	mp.insert({ 'v', "888" });
	mp.insert({ 'w', "9" });
	mp.insert({ 'x', "99" });
	mp.insert({ 'y', "999" });
	mp.insert({ 'z', "9999" });
	mp.insert({ ' ', "0" });
	cin >> n;
	string line;
	int last = -1;
	getline(cin, line);
	for (int i = 0; i < n; i++) {
		cout << "Case #" << i + 1 << ": ";
		getline(cin, line);
		for (int i = 0; i < line.size(); i++) {
			string s = mp[line[i]];
			if (s[0] == last)
				cout << " ";
			last = s[0];
			cout << s;
			}
		cout << endl;
		}

	return 0;
	}