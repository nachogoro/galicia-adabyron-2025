#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	// Buscamos ia en [0, n] tal que, tomando los primeros ia elementos de a
	// y los primeros n-ia de b, obtengamos la mitad izquierda (n elementos)
	// de la fusion ordenada. La mediana es entonces (max(izda)+min(dcha))/2.
	int l = 0, r = n + 1;
	int x1 = 0, x2 = 0;
	while (l < r) {
		int ia = (l + r) / 2;
		int ib = n - ia;

		int leftA  = (ia == 0) ? INT_MIN : a[ia - 1];
		int rightA = (ia == n) ? INT_MAX : a[ia];
		int leftB  = (ib == 0) ? INT_MIN : b[ib - 1];
		int rightB = (ib == n) ? INT_MAX : b[ib];

		if (leftA <= rightB && leftB <= rightA) {
			x1 = max(leftA, leftB);
			x2 = min(rightA, rightB);
			break;
		} else if (leftA > rightB) {
			r = ia;
		} else {
			l = ia + 1;
		}
	}

	cout << fixed << setprecision(1) << (x1 + x2) / 2.0 << "\n";
}
