#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> pos1, pos3;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        pos1.clear();
        pos3.clear();
        for(int i = 0; i < n; ++i) {
            getchar();
            for(int j = 0; j < n; ++j) {
                char c;
                scanf("%c", &c);
                if(c == '1') pos1.push_back(pii(j, i));
                else if(c == '3') pos3.push_back(pii(j, i));
            }
        }

        int ans = 0;
        for(auto p : pos1) {
            int dist = INT_MAX;
            for(auto q : pos3)
                dist = min(dist, abs(p.first - q.first) + abs(p.second - q.second));
            ans = max(ans, dist);
        }

        printf("%d\n", ans);
    }
    return 0;
}
