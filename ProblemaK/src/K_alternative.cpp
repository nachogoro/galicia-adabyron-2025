#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		long long number, base;
		cin >> number >> base;

		vector<int> translated;
		while (number != 0) {
			translated.push_back(number % base);
			number /= base;
		}

		if (translated.empty()) translated.push_back(0);

		for (int i = translated.size() - 1; i >= 0; --i) {
			cout << translated[i];
		}
		cout << "\n";
	}
}
