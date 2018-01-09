#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && n|m) {
        unordered_set<int> st;
        int ans = 0;
        for(int i = 0, x; i < n; ++i) {
            scanf("%d", &x);
            st.insert(x);
        }
        for(int i = 0, x; i < m; ++i) {
            scanf("%d", &x);
            if(st.find(x) != st.end()) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
