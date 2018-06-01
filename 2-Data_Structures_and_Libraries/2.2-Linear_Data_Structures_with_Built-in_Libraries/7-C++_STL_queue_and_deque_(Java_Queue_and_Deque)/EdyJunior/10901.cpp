#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int c;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
        if (j) { printf("\n"); }
        int n, t, cur = 0, m, cars = 0;
        string sides[] = { "left", "right" };
        string s;
        map<string, queue <pair<int, int>>> mq;
        scanf("%d %d %d", &n, &t, &m);
        for (int i = 0, d; i < m; i++) {
            cin >> d >> s;
            mq[s].push({ i, d });
        }
        s = sides[0];
        vector<pair<int, int>> res;
        while (1) {
            if (mq[sides[0]].empty() && mq[sides[1]].empty())
                break;
            
            string opS = sides[s == sides[0] ? 1 : 0];

            if (!(mq[s].empty()) && mq[s].front().second <= cur) {
                while (!(mq[s].empty()) && mq[s].front().second <= cur && cars < n) {
                    cars++;
                    res.push_back({ mq[s].front().first, cur + t });
                    mq[s].pop();
                }
                cars = 0;
                cur += t;
                s = opS;
            } else if (!(mq[opS].empty()) && mq[opS].front().second <= cur) {
                s = opS;
                cur += t;
            } else {
                int tmS = INT_MAX, tmOpS = INT_MAX;
                if (!(mq[s].empty()))
                    tmS = mq[s].front().second;
                if (!(mq[opS].empty()))
                    tmOpS = mq[opS].front().second;
                cur = min(tmS, tmOpS);
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
            printf("%d\n", res[i].second);
    }
    return 0;
}