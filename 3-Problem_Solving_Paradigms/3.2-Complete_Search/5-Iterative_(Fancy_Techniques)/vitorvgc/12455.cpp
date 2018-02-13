#include <bits/stdc++.h>

using namespace std;

int l[25];

int main() {
    int t, k, n;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d", &k, &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &l[i]);

        bool found = false;
        for(int x = 0; x < (1 << n) && !found; ++x) {
            int s = 0;
            for(int i = 0; i < n && s < k; ++i)
                if(x & (1 << i))
                    s += l[i];

            found |= (s == k);
        }

        printf("%s\n", found ? "YES" : "NO");
    }
    return 0;
}
