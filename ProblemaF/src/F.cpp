#include <bits/stdc++.h>
using namespace std;

struct Actividad {
    int value, weight;

    double density() const { return ((double) value) / weight; }
};

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int N;
        double T;
        cin >> N >> T;

        vector<Actividad> acts(N);
        for (int i = 0; i < N; ++i) {
            cin >> acts[i].weight;
        }

        for (int i = 0; i < N; ++i) {
            cin >> acts[i].value;
        }

        sort(acts.begin(), acts.end(),
             [](const Actividad& a, const Actividad& b) { return a.density() > b.density(); });

        double popularidad = 0.0;
        for (auto& act : acts) {
            double amount = min((double)act.weight, T);
            T -= amount;
            popularidad += act.value * (amount / act.weight);
        }

        cout << fixed << setprecision(6) << popularidad << "\n";
    }
}