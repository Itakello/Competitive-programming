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
	int x, y; // Coordinates
	int diff_sets; // Numero di set che si sono incontrati in questo passaggio
	int dist; // Distanza dall'albero
	int id; // Id del punto
	multiPoint() {}
	multiPoint(int _id, int _dist, int _x, int _y) :id(_id), dist(_dist), x(_x), y(_y) {
		diff_sets = 0;
		}
	void print() {
		cout << id << " x:" << x << " y:" << y << endl;
		cout << "diff_sets: " << diff_sets << " dist:" << dist << endl;
		}
	};

bool operator<(const multiPoint& p1, const multiPoint& p2) {
	if (p1.dist != p2.dist)
		return p1.dist > p2.dist;
	else
		return p1.diff_sets < p2.diff_sets;
	}

multiPoint grid[TOP][TOP]; // dist - pointN - diff_sets
priority_queue<multiPoint> pq;
int n, mst_val = 0, match = 1, tot = -1;

void setPoint(multiPoint& mp, UnionFind& UF) {
	int posX[] = { mp.x + 1, mp.x, mp.x - 1, mp.x };
	int posY[] = { mp.y, mp.y - 1, mp.y, mp.y + 1 };
	for (int i = 0; i < 4; i++) {
		int pX = posX[i], pY = posY[i];
		if (pX >= 0 && pX <= TOP && pY >= 0 && pY <= TOP) {
			if (grid[pX][pY].id == -1) {
				grid[pX][pY].diff_sets = mp.diff_sets;
				grid[pX][pY].dist = mp.dist + 1;
				grid[pX][pY].id = mp.id;
				}
			else if (!UF.isSameSet(grid[pX][pY].id, mp.id)) {
				cout << "------v" << endl;
				grid[pX][pY].print();
				mp.print();
				cout << "------^" << endl;
				UF.unionSet(grid[pX][pY].id, mp.id);
				mst_val += max(grid[pX][pY].diff_sets, mp.dist) + 1;
				grid[pX][pY].diff_sets += mp.diff_sets;
				grid[pX][pY].dist = 0;
				pq.push(grid[pX][pY]);
				match++;
				}
			}
		}
	}

int main(int argc, char** argv) {
	if (argc > 1) { (void)!freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < TOP; i++) {
		for (int j = 0; j < TOP; j++) {
			multiPoint mp(-1, -1, i, j);
			grid[i][j] = mp;
			}
		}
	// Insert start points
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (grid[x][y].dist != 0) {
			tot++;
			}
		grid[x][y].dist = 0;
		grid[x][y].id = tot;
		grid[x][y].diff_sets = 1;
		pq.push(grid[x][y]);
		}
	UnionFind UF(tot + 1);

	while (match <= tot) {// Just to be sure
		multiPoint mp = pq.top(); pq.pop();
		cout << "|";mp.print();
		setPoint(mp, UF);
		}

	cout << mst_val << endl;

	return 0;
	}