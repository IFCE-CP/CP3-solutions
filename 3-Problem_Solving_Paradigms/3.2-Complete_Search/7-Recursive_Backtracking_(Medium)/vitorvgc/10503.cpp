#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

pii l[20];
bool used[20];

bool solve(int i, int n, int m, int left, int right) {
    
    if(i == n-1) {
        
        for(int j = 0; j < m; ++j)
            if(!used[j] && ((l[j].first == left && l[j].second == right) ||
                            (l[j].first == right && l[j].second == left)))
                return true;
        return false;
    }
    
    bool possible = false;
    for(int j = 0; j < m && !possible; ++j) {
        
        if(used[j]) continue;

        if(l[j].first == left) {
            used[j] = true;
            possible |= solve(i+1, n, m, l[j].second, right);
            used[j] = false;
        }
        else if(l[j].second == left) {
            used[j] = true;
            possible |= solve(i+1, n, m, l[j].first, right);
            used[j] = false;
        }
    }

    return possible;
}

int main() {
    
    int n, m;
    pii left, right;
    while(scanf("%d", &n) && n) {
        scanf("%d", &m);
        scanf("%d %d %d %d", &left.first, &left.second, &right.first, &right.second);
        for(int i = 0; i < m; ++i)
            scanf("%d %d", &l[i].first, &l[i].second);

        memset(used, 0, sizeof used);
        printf("%s\n", solve(0, n, m, left.second, right.first) ? "YES" : "NO");
    }

    return 0;
}
