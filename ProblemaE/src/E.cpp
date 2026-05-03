#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int bfs_multisource(vector<vector<int>>& a, vector<vector<int>>& b, vector<pii>& sources) {
    vector<vector<bool>> visited(a.size(), vector<bool>(a[0].size(), false));

    array<pii,4> deltas = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    queue<pair<pii, int>> q;

    for (auto [x, y] : sources) {
        q.push({{x, y}, 0});
        visited[x][y] = true;
    }

    while (!q.empty()) {
        auto f = q.front(); q.pop();
        int x = f.first.first;
        int y = f.first.second;
        int d = f.second;

        if (b[x][y]) return d;

        for (auto [dx, dy] : deltas) {
            int vx = x + dx;
            int vy = y + dy;

            if (vx < 0 || vx >= a.size() || vy < 0 || vy >= a[0].size()) continue;
            if (visited[vx][vy]) continue;
            q.push({{vx, vy}, d + 1});
            visited[vx][vy] = true;
        }
    }

    return -1;
}

int main() {
    int r, c;
    cin >> r >> c;

    int size = 0;
    vector<vector<int>> a(r, vector<int>(c, 0));
    auto b = a;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j]) ++size;
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> b[i][j];
        }
    }

    int overlap = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 1 && b[i][j] == 1) {
                overlap++;
            }
        }
    }

    if (overlap > 0) {
        // Se solapan, basta con mover las no solapadas
        cout << size - overlap << "\n";
    } else {
        vector<pii> sources;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (a[i][j]) sources.push_back({i,j});
            }
        }

        cout << size + bfs_multisource(a, b, sources) - 1 << "\n";
    }
}