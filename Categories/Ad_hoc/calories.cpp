//https://open.kattis.com/contests/uawr9g/problems/calories
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
	while ((pos = s.find(' ')) != string::npos) {
		vals[ind++] = s.substr(0, pos);
		s.erase(0, pos + 1);
		}
	vals[ind] = s;
	}

int g_to_C[] = { 9,4,4,4,7 };

int main(int argc, char** argv) {
	if (argc > 1) (void)!freopen(argv[1], "r", stdin); ios::sync_with_stdio(false); cin.tie(0);
	string line;
	getline(cin, line);
	while (line != "-") {
		double tot_C = 0, fats_C = 0;
		while (line != "-") {
			double food_C[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
			double food_perc[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
			string vals[5];
			split(line, vals);
			for (int i = 0; i < 5; i++) {
				string s = vals[i].substr(0, vals[i].size() - 1);
				int val = stoi(s);
				char typ = vals[i][vals[i].size() - 1];
				if (typ == 'g')
					food_C[i] += val * g_to_C[i];
				else if (typ == '%')
					food_perc[i] += val / (double)100;
				else
					food_C[i] += val;
				}
			double line_C = accumulate(food_C, food_C + 5, 0.0);
			double line_perc = accumulate(food_perc, food_perc + 5, 0.0);
			double tot_line_C = line_C / (1 - line_perc);
			// cout << line_C << " " << line_perc << " " << tot_line_C << endl;
			tot_C += tot_line_C;
			fats_C += food_C[0] + (food_perc[0] * tot_line_C);
			getline(cin, line);
			}
		printf("%d%%\n", lround(fats_C * 100 / tot_C));
		getline(cin, line);
		}

	return 0;
	}