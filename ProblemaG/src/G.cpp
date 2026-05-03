#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> coins(N);
        for (int i = 0; i < N; ++i)
            cin >> coins[i];

        vector<bool> cursed(1001, false);
        int M;
        cin >> M;
        while(M--) {
            int v;
            cin >> v;
            cursed[v] = true;
        }

        int sum = 0;
        for (auto c : coins) {
            if (!cursed[c]) sum += c;
        }
        cout << sum << "\n";
    }
}