// https://open.kattis.com/contests/z4dra4/problems/gridmst
#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define TOP 1000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

class UnionFind {
private:
	vi p, rank, num_elems;
public:
	UnionFind(int N) {
		rank.resize(N, 0);
		p.resize(N, 0);
		num_elems.resize(N, 1);
		for (int i = 0; i < N; i++) {
			p[i] = i;
			}
		}
	int get_num_elems(int i) { return num_elems[findSet(i)]; }
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) { // if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
				}
			num_elems[findSet(x)]++;
			}
		}
	void print() {
		cout << "Rank " << rank.size() << endl;
		for (int i = 0; i < rank.size(); i++) {
			cout << rank[i] << " ";
			}
		cout << endl << "P " << p.size() << endl;
		for (int i = 0; i < p.size(); i++) {
			cout << p[i] << endl;
			}
		}
	};

class multiPoint {
public:
	int x, y, val;
	int diff_sets;
	vi sets;
	multiPoint(int _x, int _y, int _val) :x(_x), y(_y), val(_val) {
		diff_sets = 1;
		}
	};

bool operator<(const multiPoint& p1, const multiPoint& p2) {
	return p1.sets.size() > p2.sets.size();
	}

ii grid[TOP][TOP]; // val - pointN
priority_queue<multiPoint> pq;
int n, maxX = 0, maxY = 0, curr = 0, mst_val = 0, match = 1, tot = 0;

void insertPq(int x, int y, UnionFind& UF) {
	multiPoint mp(x, y, curr);
	int posX[] = { x + 1, x, x - 1, x };
	int posY[] = { y, y - 1, y, y + 1 };
	for (int i = 0; i < 4; i++) {
		if (grid[posX[i]][posY[i]].second != -1) {
			mp.sets.push_back(grid[posX[i]][posY[i]].second);
			}
		}
	bool ok;
	for (int i = 0; i < mp.sets.size(); i++) {
		ok = true;
		for (int j = i + 1; j < mp.sets.size(); j++) {
			if (UF.isSameSet(mp.sets[i], mp.sets[j]))
				ok = false;
			}
		if (ok)
			mp.diff_sets++;
		}
	pq.push(mp);
	}

void setPoint(int x, int y, int currP, UnionFind& UF) {
	int posX[] = { x + 1, x, x - 1, x };
	int posY[] = { y, y - 1, y, y + 1 };
	for (int i = 0; i < 4; i++) {
		int pX = posX[i], pY = posY[i];
		if (pX >= 0 && pX <= maxX && pY >= 0 && pY <= maxY) {
			if (grid[pX][pY].first == -1) {
				grid[pX][pY].first = curr + 1;
				grid[pX][pY].second = currP;
				}
			else {
				if (!UF.isSameSet(grid[pX][pY].second, currP)) {
					insertPq(pX, pY, UF);
					}
				}
			}
		}
	}

// Usare una priority queue, inserire le coincidenze da più set diversi
// Priority queue -> n_set diversi, sets, posizione, valore corrente

// Controllo che siano ancora tutti di set diversi
// se lo sono, unisco gli insiemi, incremento mst_val e inserisco il valore nella cella

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	UnionFind UF(n);
	for (int i = 0; i < TOP; i++) {
		for (int j = 0; j < TOP; j++) {
			grid[i][j] = ii(-1, -1);
			}
		}
	// Insert points
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (grid[x][y].first != 0) {
			tot++;
			}
		grid[x][y] = ii(0, i);
		maxX = max(x, maxX);
		maxY = max(y, maxY);
		}

	//while (match < tot) {
	for (int i = 0; i <= maxX; i++) {
		for (int j = 0; j <= maxY; j++) {
			if (grid[i][j].first == curr) {
				setPoint(i, j, grid[i][j].second, UF);
				}
			}
		}
	//curr++;
	//}

	cout << endl;
	for (int i = 0; i <= maxX; i++) {
		for (int j = 0; j <= maxY; j++) {
			if (grid[i][j].first == -1)
				cout << "-" << "\t";
			else if (grid[i][j].first == -2)
				cout << "?" << "\t";
			else
				cout << grid[i][j].first << "-" << grid[i][j].second << "\t";
			}
		cout << endl;
		}

	cout << mst_val << endl;

	return 0;
	}