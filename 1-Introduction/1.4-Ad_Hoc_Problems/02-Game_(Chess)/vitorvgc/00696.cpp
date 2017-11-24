#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n;
    while(scanf("%d %d", &m, &n) && m|n) {
        int ans;
        if(min(m, n) == 1)
            ans = max(m, n);
        else if(min(m, n) == 2)
            ans = 4 * ((max(m, n) + 2) / 4) + (max(m, n) % 4 == 1 ? 2 : 0);
        else
            ans = (m * n + 1) / 2;

        printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }
    return 0;
}
