#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, h;
	cin >> n >> h;

	// elev[a] = lista de pisos a los que se puede llegar desde a en ascensor
	vector<vector<int>> elev(h);
	while (n--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		elev[a].push_back(b);
	}

	// dp[i] = numero minimo de escaleras para llegar al piso i
	const int INF = INT_MAX;
	vector<int> dp(h, INF);
	dp[0] = 0;

	// Procesamos los pisos en orden creciente. Cuando llegamos al piso i,
	// dp[i] ya es definitivo: como las escaleras y los ascensores solo suben,
	// cualquier mejora futura tendria que provenir de un piso > i, imposible.
	for (int i = 0; i < h; ++i) {
		if (dp[i] == INF) continue;
		if (i + 1 < h) {
			dp[i+1] = min(dp[i+1], dp[i] + 1);
		}
		for (int b : elev[i]) {
			dp[b] = min(dp[b], dp[i]);
		}
	}

	cout << dp[h-1] << "\n";
}
