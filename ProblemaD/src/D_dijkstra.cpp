#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

vll dijkstra(int s, vector<vector<pll>>& adj) {
    int n = adj.size();
    vll dist(n, 1e14);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int asc, n;
    cin >> asc >> n;
    vector<vector<pll>> adj(n);
    for (int i = 0; i < n-1; ++i) {
        adj[i].push_back({i+1, 1});
    }

    while (asc--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, 0});
    }

    cout << dijkstra(0, adj)[n-1] << "\n";

}