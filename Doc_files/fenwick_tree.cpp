#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int LSOne(int x) {
	return (x & (-x));
	}

// 🗒️NOTE: Easy to implement for multidimensional (just apply for another layer)
// Point/Range update,
class FenwickTree {
private:
	vi ft;
public:
	FenwickTree(int n) { // Initialize to zeros
		ft.assign(n + 1, 0);
		}
	FenwickTree(vi a) : FenwickTree(a.size()) { // this is O(a.size() log n)
		for (size_t i = 0; i < a.size(); i++)
			adjust(i + 1, a[i]);
		}
	// Point/range update - Range query
	int rsq(int b) { // returns RSQ(1, b)
		int sum = 0;
		for (; b; b -= LSOne(b)) // Ex: b=6 -> 6,4,0,0
			sum += ft[b];
		return sum;
		}
	int rsq(int a, int b) { // returns RSQ(a, b)
		return rsq(b) - (a <= 1 ? 0 : rsq(a - 1));
		}
	void adjust(int k, int val) { // adjust single index
		for (; k < (int)ft.size(); k += LSOne(k))
			ft[k] += val;
		}
	// Da controllare
	void range_adjust(int l, int r, int val) { // adjust [l, r] indexes
		adjust(l, val);
		adjust(r, -val);
		}
	};
int main() {
	vi a{ 2,4,5,5,6,6,6,7,7,8,9 };
	FenwickTree ft(10);
	for (int i = 0; i < 11; i++)
		ft.adjust(a[i], 1);
	printf("%d\n", ft.rsq(1)); // 0 => ft[1] = 0
	printf("%d\n", ft.rsq(2)); // 1 => ft[2] = 1
	printf("%d\n", ft.rsq(1, 6)); // 7 => ft[6] + ft[4] = 5 + 2 = 7
	printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
	printf("%d\n", ft.rsq(3, 6)); // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1
	ft.adjust(5, 2); // update demo
	printf("%d\n", ft.rsq(1, 10)); // now 13
	}