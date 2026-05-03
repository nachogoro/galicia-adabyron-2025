#include <bits/stdc++.h>
using namespace std;

struct Curso {
    int start, end;

    bool operator<(const Curso& o) const {
        if (end != o.end) return end < o.end;
        return start < o.start;
    }
};

int main() {
    int m;
    cin >> m;
    // Skip new line
    cin.ignore();

    vector<Curso> cursos(m);
    string name;
    for (int i = 0; i < m; ++i) {
        cin >> name;
        cin >> cursos[i].start >> cursos[i].end;
        cin.ignore();
    }

    sort(cursos.begin(), cursos.end());

    int busy_until = 0;
    int res = 0;
    for (auto& [start, end] : cursos) {
        if (start < busy_until) continue;
        res++;
        busy_until = end;
    }

    cout << res << "\n";
}