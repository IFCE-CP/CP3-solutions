#include <bits/stdc++.h>

using namespace std;

struct Area {
    int x, y, pop;

    int dist(int index) {
        int x2 = index % 5;
        int y2 = index / 5;
        return pop * (abs(x - x2) + abs(y - y2));
    }
};

int main() {
    int t, n;
    for(scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        vector<Area> v(n);
        for(int i = 0; i < n; ++i)
            scanf("%d %d %d", &v[i].y, &v[i].x, &v[i].pop);

        vector<int> ans;
        int mnDist = INT_MAX;
        for(int a = 0  ; a < 21; ++a)
        for(int b = a+1; b < 22; ++b)
        for(int c = b+1; c < 23; ++c)
        for(int d = c+1; d < 24; ++d)
        for(int e = d+1; e < 25; ++e) {
            int dist = 0;
            for(auto area : v) {
                int da = area.dist(a);
                int db = area.dist(b);
                int dc = area.dist(c);
                int dd = area.dist(d);
                int de = area.dist(e);
                dist += min(min(da, min(db, dc)), min(dd, de));
            }
            if(dist < mnDist) {
                mnDist = dist;
                ans = {a, b, c, d, e};
            }
        }

        printf("%d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
    }
    return 0;
}
