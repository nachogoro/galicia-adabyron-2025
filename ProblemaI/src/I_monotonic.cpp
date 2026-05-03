#include <bits/stdc++.h>
using namespace std;

// Maximo de toda ventana deslizante de tamano k sobre el vector a.
// res[i] = max(a[i], a[i+1], ..., a[i+k-1]), para i = 0..a.size()-k.
void sliding_max(const vector<int>& a, int k, vector<int>& res) {
	deque<int> dq;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1) res[i - k + 1] = a[dq.front()];
	}
}

void sliding_min(const vector<int>& a, int k, vector<int>& res) {
	deque<int> dq;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
		while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
		dq.push_back(i);
		if (i >= k - 1) res[i - k + 1] = a[dq.front()];
	}
}

void tc() {
	int H, W, M, N;
	cin >> H >> W >> M >> N;

	vector<vector<int>> g(H, vector<int>(W));
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cin >> g[i][j];

	int CW = W - N + 1;
	int CH = H - M + 1;

	// Pasada 1: por cada fila, ventana de tamano N sobre las columnas.
	vector<vector<int>> rowMax(H, vector<int>(CW)), rowMin(H, vector<int>(CW));
	for (int i = 0; i < H; ++i) {
		sliding_max(g[i], N, rowMax[i]);
		sliding_min(g[i], N, rowMin[i]);
	}

	// Pasada 2: por cada columna de los resultados anteriores, ventana de
	// tamano M sobre las filas. Combinando ambas pasadas obtenemos el max/min
	// de cada submatriz MxN.
	int best = INT_MAX;
	vector<int> col(H), out(CH);
	for (int j = 0; j < CW; ++j) {
		for (int i = 0; i < H; ++i) col[i] = rowMax[i][j];
		sliding_max(col, M, out);
		vector<int> winMax = out;

		for (int i = 0; i < H; ++i) col[i] = rowMin[i][j];
		sliding_min(col, M, out);

		for (int i = 0; i < CH; ++i) {
			best = min(best, winMax[i] - out[i]);
		}
	}

	cout << best << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) tc();
}
