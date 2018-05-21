#include <bits/stdc++.h>

using namespace std;

int bfs(vector<int> g[30], bool letters[26], string wakeS, int n) {

    int awaken = 3, years = 0;
    bool wake[26];
    fill(wake, wake + 26, false);
    for (auto s : wakeS)
        wake[s - 'A'] = true;
    while (1) {
        vector<int> willWake;
        for (int i = 0; i < 26; i++) {
            if (wake[i])
                continue;
            int count = 0;
            for (auto w : g[i])
                if (wake[w])
                    count++;
            if (count > 2)
                willWake.push_back(i);
        }
        if (willWake.size() == 0)
            break;
        for (auto w : willWake) {
            wake[w] = true;
            awaken++;
        }
        years++;
    }
    return awaken == n ? years : -1;
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while (cin >> n) {
        string wakeS;
        bool letters[30];
        cin >> m >> wakeS;
        fill(letters, letters + 26, false);
        for (auto s : wakeS)
            letters[s - 'A'] = true;
        int cited = 3;
        vector<int> g[30];
        for (int i = 0; i < m; i++) {
            string connect;
            cin >> connect;
            g[connect[0] - 'A'].push_back(connect[1] - 'A');
            g[connect[1] - 'A'].push_back(connect[0] - 'A');
            for (int j = 0; j < 2; j++)
                if (!letters[connect[j] - 'A']) {
                    cited++;
                    letters[connect[j] - 'A'] = true;
                }
        }
        for (int i = 0; i < 26 && cited < n; i++)
            if (!letters[i + 'A']) {
                cited++;
                letters[i + 'A'] = true;
            }
        int years = bfs(g, letters, wakeS, n);
        if (years == -1)
            cout << "THIS BRAIN NEVER WAKES UP\n";
        else
            cout << "WAKE UP IN, " << years << ", YEARS\n";
    }
    return 0;
}