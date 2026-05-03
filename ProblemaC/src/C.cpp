#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vvpii = vector<vector<pii>>;

vector<int> dijkstra(int s, vvpii& adj, const vector<bool>& is_waypoint) {
    int n = adj.size();
    vector<int> dist(n, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0; pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        if (u != s && is_waypoint[u]) {
            // No podemos pasar por ningún waypoint
            continue;
        }

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
    int P, C;
    cin >> P >> C;

    // (vecino, peso)
    vvpii adj(P);
    while (C--) {
        int o, d, t;
        cin >> o >> d >> t;
        --o; --d;
        adj[o].push_back({d, t});
    }

    int salida, meta, nwaypoints;
    cin >> salida >> meta >> nwaypoints;
    --salida; --meta;

    vector<bool> is_waypoint(P, false);
    is_waypoint[salida] = true;
    is_waypoint[meta] = true;

    vector<int> waypoints(nwaypoints + 2);
    waypoints[0] = salida;

    for (int i = 1; i <= nwaypoints; ++i) {
        cin >> waypoints[i];
        waypoints[i]--;
        is_waypoint[waypoints[i]] = true;
    }

    waypoints[nwaypoints + 1] = meta;

    int coste = 0;
    for (int i = 0; i < waypoints.size() - 1; ++i) {
        int from = waypoints[i];
        int to = waypoints[i+1];
        coste += dijkstra(from, adj, is_waypoint)[to];
    }

    cout << coste << "\n";
}