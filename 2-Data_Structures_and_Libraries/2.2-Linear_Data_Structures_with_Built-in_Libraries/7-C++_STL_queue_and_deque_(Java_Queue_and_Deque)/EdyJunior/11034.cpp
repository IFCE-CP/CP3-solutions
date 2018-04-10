#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int c;
    scanf("%d", &c);
    for (int j = 0; j < c; j++) {
        int l, m, space = 0, res = 0;
        string sides[] = { "left", "right" }, s;
        map<string, queue <pair<int, int>>> mq;
        scanf("%d %d", &l, &m);
        l *= 100;
        for (int i = 0, d; i < m; i++) {
            cin >> d >> s;
            mq[s].push({ i, d });
        }
        s = sides[0];
        while (1) {
            if (mq[sides[0]].empty() && mq[sides[1]].empty())
                break;
            
            string opS = sides[s == sides[0] ? 1 : 0];

            if (!(mq[s].empty())) {
                while (!(mq[s].empty()) && space + mq[s].front().second <= l) {
                    space += mq[s].front().second;
                    mq[s].pop();
                }
                space = 0;
                s = opS;
                res++;
            } else if (!(mq[opS].empty())) {
                s = opS;
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}