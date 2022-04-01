//https://open.kattis.com/contests/uawr9g/problems/booking
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

void split(string s, string* vals) {
	int ind = 0;
	size_t pos = 0;
	string delim = " ";
	while ((pos = s.find(delim)) != string::npos) {
		vals[ind++] = s.substr(0, pos);
		s.erase(0, pos + delim.size());
		}
	vals[ind] = s;
	}

int t, b, c;
map<ll, vector<string>> dates;
int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,31 ,30,31 };

void dateConv(string* date) {
	string id = date[0];
	int year1 = stoi(date[1].substr(0, 4));
	int month1 = stoi(date[1].substr(5, 7));
	int day1 = stoi(date[1].substr(8, 10));
	int hour1 = stoi(date[2].substr(0, 2));
	int min1 = stoi(date[2].substr(3, 5));
	ll tot1 = (year1 - 2013) * (60 * 24 * 365);
	for (int i = 0; i < month1 - 1; i++) {
		if (year1 == 2016 && i == 1)
			tot1 += 29 * 24 * 60;
		else
			tot1 += months[i] * 24 * 60;
		}
	tot1 += (day1 - 1) * 24 * 60;
	tot1 += hour1 * 60;
	tot1 += min1;

	int year2 = stoi(date[3].substr(0, 4));
	int month2 = stoi(date[3].substr(5, 7));
	int day2 = stoi(date[3].substr(8, 10));
	int hour2 = stoi(date[4].substr(0, 2));
	int min2 = stoi(date[4].substr(3, 5));
	ll tot2 = (year2 - 2013) * (60 * 24 * 365);
	for (int i = 0; i < month2 - 1; i++) {
		if (year2 == 2016 && i == 1)
			tot2 += 29 * 24 * 60;
		else
			tot2 += months[i] * 24 * 60;
		}
	tot2 += (day2 - 1) * 24 * 60;
	tot2 += hour2 * 60;
	tot2 += min2;
	dates[tot1].push_back(id + "a");
	dates[tot2 + c].push_back(id + "b");
	}

bool compString(string s1, string s2) {
	char c1 = s1[s1.size() - 1];
	char c2 = s2[s2.size() - 1];
	return c1 > c2;
	}

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> b >> c;
		string line;
		getline(cin, line);
		dates.clear();
		for (int i = 0; i < b; i++) {
			getline(cin, line);
			string tmp[5];
			split(line, tmp);
			dateConv(tmp);
			}
		int tot_room = 0, curr_room = 0;
		set<string> occ;
		for (auto x : dates) {
			sort(x.second.begin(), x.second.end(), compString);
			for (int i = 0; i < x.second.size(); i++) {
				string room = x.second[i].substr(0, x.second[i].size() - 1);
				if (occ.find(room) != occ.end()) {
					occ.erase(room);
					curr_room--;
					}
				else {
					occ.insert(room);
					curr_room++;
					tot_room = max(tot_room, curr_room);
					}
				}
			}
		cout << tot_room << endl;
		}

	return 0;
	}