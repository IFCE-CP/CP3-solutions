#include <bits/stdc++.h>

using namespace std;

int l[15];
bool used[15];

set< vector<int> > ans;

void solve(int i, int s, int n) {

    if(s == 0) {
        vector<int> v;
        for(int i = 0; i < n; ++i)
            if(used[i])
                v.push_back(l[i]);
        ans.insert(v);
    }

    if(i >= n || s < 0)
        return;

    used[i] = true;
    solve(i+1, s-l[i], n);
    used[i] = false;
    solve(i+1, s, n);
}

int main() {
    int s, n;
    while(scanf("%d %d", &s, &n) && s | n) {
        
        for(int i = 0; i < n; ++i)
            scanf("%d", &l[i]);

        ans.clear();
        solve(0, s, n);

        vector< vector<int> > sol = vector< vector<int> >(ans.rbegin(), ans.rend());

        printf("Sums of %d:\n", s);
        if(ans.empty())
            printf("NONE\n");
        else
            for(auto &v : sol) {
                for(int i = 0; i < v.size()-1; ++i)
                    printf("%d+", v[i]);
                printf("%d\n", v.back());
            }
    }
    return 0;
}
