#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	deque<int> a, b;

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		a.push_back(v);
	}

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		b.push_back(v);
	}

	n--;
	while (n--) {
		if (!a.empty()&& (b.empty() || a.front() <= b.front()))
			a.pop_front();
		else
			b.pop_front();
	}

	int x1, x2;
	if (!a.empty() && (b.empty() || a.front() <= b.front())) {
		x1 = a.front();
		a.pop_front();
	} else {
		x1 = b.front();
		b.pop_front();
	}

	if (!a.empty() && (b.empty() || a.front() <= b.front())) {
		x2 = a.front();
		a.pop_front();
	} else {
		x2 = b.front();
		b.pop_front();
	}

	cout << fixed << setprecision(1) << (x1 + x2) / 2.0 << "\n";
}
