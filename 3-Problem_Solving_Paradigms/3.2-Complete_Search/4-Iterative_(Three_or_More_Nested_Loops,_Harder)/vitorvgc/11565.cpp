#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b, c;
    for(scanf("%d", &t); t--; ) {
        scanf("%d %d %d", &a, &b, &c);

        bool ok = false;
        for(int x = -22; x <= 22 && !ok; ++x) {
            for(int y = -10000; y <= 10000 && !ok; ++y) {
                int z = a - x - y;
                if(x != y && x != z && y != z && (x*y*z == b) && (x*x + y*y + z*z == c)) {
                    int x2 = min(x, min(y, z));
                    int z2 = max(x, max(y, z));
                    int y2 = x + y + z - x2 - z2;
                    printf("%d %d %d\n", x2, y2, z2);
                    ok = true;
                }
            }
        }

        if(!ok) printf("No solution.\n");
    }
    return 0;
}
