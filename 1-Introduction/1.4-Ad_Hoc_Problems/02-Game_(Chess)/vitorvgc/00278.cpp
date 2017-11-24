#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m, ans;
    char c;
    for(scanf("%d", &t); t; --t) {
        scanf(" %c %d %d", &c, &m, &n);

        if(c == 'Q' || c == 'r')
            ans = min(m, n);
        else if(c == 'K')
            ans = ((m+1) >> 1) * ((n+1) >> 1);
        else if(c == 'k')
            ans = (m * n + 1) / 2;

        printf("%d\n", ans);
    }
    return 0;
}

