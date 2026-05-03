#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		long long number, base;
		cin >> number >> base;

		vector<int> translated;
		long long multiplier = 1;
		while (number != 0) {
			translated.push_back((number / multiplier) % base);
			number -= translated.back() * multiplier;
			multiplier *= base;
		}

		if (translated.empty()) translated.push_back(0);

		for (int i = translated.size() - 1; i >= 0; --i) {
			cout << translated[i];
		}
		cout << "\n";
	}
}
