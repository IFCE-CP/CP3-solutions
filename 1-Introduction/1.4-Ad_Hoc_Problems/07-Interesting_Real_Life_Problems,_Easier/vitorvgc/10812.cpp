#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d", &a, &b);
        if((a+b) & 1 || a < b) printf("impossible\n");
        else printf("%d %d\n", (a+b)/2, (a-b)/2);
    }
    return 0;
}
