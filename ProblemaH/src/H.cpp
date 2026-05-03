#include <bits/stdc++.h>
using namespace std;

vector<long long> simulate(vector<long long>& levels, long long start, long long fiona) {
    vector<long long> orden;
    orden.push_back(start);
    fiona++;
    long long left = start - 1, right = start + 1;

    while (left >= 0 || right < (long long)levels.size()) {
        bool canLeft  = (left  >= 0)                       && fiona >= levels[left];
        bool canRight = (right < (long long)levels.size()) && fiona >= levels[right];

        if (!canLeft && !canRight) return {};

        if (canLeft) {
            orden.push_back(left);
            left--;
        }
        else {
            orden.push_back(right);
            right++;
        }

        fiona++;
    }

    return orden;
}

int main() {
    long long N, V;
    cin >> N >> V;

    vector<long long> levels(N);
    for (long long i = 0; i < N; ++i) {
        cin >> levels[i];
    }

    for (long long start = 0; start < N; ++start) {
        if (levels[start] <= V) {
            auto orden = simulate(levels, start, V);

            if (orden.size() == N) {
                // Exito
                for (long long pi = 0; pi < N; ++pi) {
                    cout << orden[pi] + 1;
                    if (pi == N - 1) cout << "\n";
                    else cout << " ";
                }
                return 0;
            }
        }
    }

    cout << "FALLIDA\n";
}