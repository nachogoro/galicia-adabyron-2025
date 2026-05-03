#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> h(n+2, 0);
        for (int i = 1; i <= n; ++i)
            cin >> h[i];

        vector<int> left(n+2, 0), right(n+2, n+2);
        stack<int> s;

        // First index is lowest, skip it
        s.push(0);
        for (int i = 1; i <= n; ++i) {
            while (h[s.top()] >= h[i]) {
                s.pop();
            }

            left[i] = s.top();
            s.push(i);
        }

        // Last index is lowest, skip it
        s = stack<int>();
        s.push(n+1);
        for (int i = n; i >= 1; --i) {
            while (h[s.top()] >= h[i]) {
                s.pop();
            }

            right[i] = s.top();
            s.push(i);
        }

        // For each bar, find first bar lower than it to its left and right
        long long max_area = 0;
        for (int i = 1; i <= n; ++i) {
            max_area = max(max_area, (long long) h[i] * (right[i] - left[i] - 1));
        }

        cout << max_area << "\n";
    }
}