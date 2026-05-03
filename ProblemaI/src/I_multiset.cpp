#include <bits/stdc++.h>
using namespace std;

void tc() {
	int rows, cols, wrows, wcols;
	cin >> rows >> cols >> wrows >> wcols;

	vector<vector<int>> m;

	for (int i = 0; i < rows; ++i) {
		m.push_back({});
		for (int j = 0; j < cols; ++j) {
			int v;
			cin >> v;
			m[i].push_back(v);
		}
	}

	vector<vector<int>> max_horizontal;
	multiset<int> window;
	for (int i = 0; i < rows; ++i) {
		window.clear();
		max_horizontal.push_back(vector<int>(cols - wcols + 1));
		for (int j = 0; j < wcols; ++j) {
			window.insert(m[i][j]);
		}

		max_horizontal[i][0] = *window.rbegin();

		for (int j = 1; j < cols - wcols + 1; ++j) {
			window.erase(window.find(m[i][j-1]));
			window.insert(m[i][j+wcols-1]);
			max_horizontal[i][j] = *window.rbegin();
		}
	}

	vector<vector<int>> max_window(rows - wrows + 1, vector<int>(cols - wcols + 1));
	for (int j = 0; j < max_horizontal[0].size(); ++j) {
		window.clear();
		for (int i = 0; i < wrows; ++i) {
			window.insert(max_horizontal[i][j]);
		}

		max_window[0][j] = *window.rbegin();

		for (int i = 1; i < rows - wrows + 1; ++i) {
			window.erase(window.find(max_horizontal[i-1][j]));
			window.insert(max_horizontal[i+wrows-1][j]);
			max_window[i][j] = *window.rbegin();
		}
	}

	vector<vector<int>> min_horizontal;
	for (int i = 0; i < rows; ++i) {
		window.clear();
		min_horizontal.push_back(vector<int>(cols - wcols + 1));
		for (int j = 0; j < wcols; ++j) {
			window.insert(m[i][j]);
		}

		min_horizontal[i][0] = *window.begin();

		for (int j = 1; j < cols - wcols + 1; ++j) {
			window.erase(window.find(m[i][j-1]));
			window.insert(m[i][j+wcols-1]);
			min_horizontal[i][j] = *window.begin();
		}
	}

	vector<vector<int>> min_window(rows - wrows + 1, vector<int>(cols - wcols + 1));
	for (int j = 0; j < min_horizontal[0].size(); ++j) {
		window.clear();
		for (int i = 0; i < wrows; ++i) {
			window.insert(min_horizontal[i][j]);
		}

		min_window[0][j] = *window.begin();

		for (int i = 1; i < rows - wrows + 1; ++i) {
			window.erase(window.find(min_horizontal[i-1][j]));
			window.insert(min_horizontal[i+wrows-1][j]);
			min_window[i][j] = *window.begin();
		}
	}

	int result = 2e9;
	for (int i = 0; i < max_window.size(); ++i) {
		for (int j = 0; j < max_window[0].size(); ++j) {
			result = min(result, max_window[i][j] - min_window[i][j]);
		}
	}

	cout << result << "\n";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		tc();
	}
}
