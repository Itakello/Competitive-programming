// Range Minimum Queries (Dynamic, you can change values)
// easily changed to rsq
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree { // the segment tree is stored like a heap array
	private:
	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }
	void build(int p, int L, int R) {
		if (L == R)
			st[p] = L;
		else {
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2; //t[p] = st[left(p)] + st[right(p)];
			}
		}
	int rsq(int p, int L, int R, int i, int j) { // O(log n)
		if (i > R || j < L)
			return -1; // current segment outside query range
		if (L >= i && R <= j)
			return st[p]; // inside query range
		// compute the min position in the left and right part of the interval
		int p1 = rsq(left(p), L, (L + R) / 2, i, j);
		int p2 = rsq(right(p), (L + R) / 2 + 1, R, i, j);
		if (p1 == -1)
			return p2;
		if (p2 == -1)
			return p1;
		return (A[p1] <= A[p2]) ? p1 : p2; //p1 + p2;
		}
	int update(int p, int L, int R, int i) {
		if (L == R)
			return st[p];
		int x = (L + R) / 2;
		int p1, p2;
		if (i <= x) {
			p1 = update(left(p), L, (L + R) / 2, i);
			p2 = st[right(p)];
			}
		else {
			p1 = st[left(p)];
			p2 = update(right(p), (L + R) / 2 + 1, R, i);
			}
		st[p] = (A[p1] <= A[p2]) ? p1 : p2; // st[p] = p1 + p2;
		return st[p];
		}
	public:
	SegmentTree(const vi& _A) {
		A = _A;
		n = (int)A.size();	 // copy content for local usage
		st.assign(4 * n, 0); // create large enough vector of zeroes
		build(1, 0, n - 1);	 // recursive build
		}
	int rmq(int i, int j) { return rsq(1, 0, n - 1, i, j); } // overloading
	void update(int i, int val) {
		A[i] = val;
		update(1, 0, n - 1, i); // overloading
		}
	};
int main() {
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array
	vi A(arr, arr + 7);
	SegmentTree st(A);
	printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // RMQ -> 2
	printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // RMQ -> 5
	st.update(5, 99);
	printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // RMQ -> 2
	printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // RMQ -> 4
	} // return 0;