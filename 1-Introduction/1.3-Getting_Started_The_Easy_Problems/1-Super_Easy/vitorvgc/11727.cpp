#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, l[3], caso = 0;
    for(scanf("%d", &t); t; --t) {
        scanf("%d %d %d", &l[0], &l[1], &l[2]);
        sort(l, l+3);
        printf("Case %d: %d\n", ++caso, l[1]);
    }
    return 0;
}
