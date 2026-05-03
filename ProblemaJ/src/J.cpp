#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& m, int i, int j) {
	if (i < 0 || i >= m.size()) return;
	if (j < 0 || j >= m[0].size()) return;
	if (m[i][j] != 1) return;
	m[i][j] = 2;
	dfs(m, i-1, j-1);
	dfs(m, i-1, j);
	dfs(m, i-1, j+1);
	dfs(m, i  , j-1);
	dfs(m, i  , j+1);
	dfs(m, i+1, j-1);
	dfs(m, i+1, j);
	dfs(m, i+1, j+1);
}

void tc() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> matrix(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> matrix[i][j];
		}
	}

	int cc = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (matrix[i][j] == 1) {
				dfs(matrix, i, j);
				cc++;
			}
		}
	}

	cout << cc << "\n";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		tc();
	}
}
