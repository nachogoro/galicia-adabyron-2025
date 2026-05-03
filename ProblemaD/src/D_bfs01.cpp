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

	const int INF = INT_MAX;
	vector<int> dist(h, INF);
	vector<bool> visited(h, false);
	deque<int> dq;
	dist[0] = 0;
	dq.push_front(0);

	while (!dq.empty()) {
		int u = dq.front(); dq.pop_front();
		if (visited[u]) continue;
		visited[u] = true;

		// Arista de escalera: peso 1, va al final del deque.
		if (u + 1 < h && dist[u] + 1 < dist[u+1]) {
			dist[u+1] = dist[u] + 1;
			dq.push_back(u+1);
		}

		// Aristas de ascensor: peso 0, van al principio del deque.
		for (int v : elev[u]) {
			if (dist[u] < dist[v]) {
				dist[v] = dist[u];
				dq.push_front(v);
			}
		}
	}

	cout << dist[h-1] << "\n";
}
