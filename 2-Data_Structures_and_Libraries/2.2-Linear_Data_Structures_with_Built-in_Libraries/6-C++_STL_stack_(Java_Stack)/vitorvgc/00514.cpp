#include <bits/stdc++.h>

using namespace std;

int l[1010];

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        while(scanf("%d", &l[0]) && l[0]) {
            
            for(int i = 1; i < n; ++i)
                scanf("%d", &l[i]);

            stack<int> stk;
            int p = 0;
            for(int i = 1; i <= n && p < n; ++i) {
                stk.push(i);
                while(!stk.empty() && stk.top() == l[p])
                    stk.pop(), ++p;
            }

            printf("%s\n", p >= n ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
