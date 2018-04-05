#include <bits/stdc++.h>

using namespace std;

bool isPrime[35];
bool used[20];
int ans[20];

void solve(int i, int n) {
    
    if(i >= n) {
        for(int j = 0; j < n-1; ++j)
            printf("%d ", ans[j]);
        printf("%d\n", ans[n-1]);
        return;
    }

    for(int j = 1; j <= n; ++j) {

        if(!used[j] && isPrime[ans[i-1] + j]
            && (i < n-1 || isPrime[ans[0] + j])) {
            used[j] = true;
            ans[i] = j;
            solve(i+1, n);
            used[j] = false;
            ans[i] = -1;
        }
    }
}

int main() {
    
    bool first = true;
    int n, caso = 0;
    int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for(int x : p)
        isPrime[x] = true;

    while(scanf("%d", &n) != EOF) {
        memset(used, 0, sizeof used);
        memset(ans, -1, sizeof ans);
        used[1] = 1;
        ans[0] = 1;
        if(!first)
            printf("\n");
        first = false;
        printf("Case %d:\n", ++caso);
        solve(1, n);
    }

    return 0;
}
