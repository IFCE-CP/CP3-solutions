#include <bits/stdc++.h>

using namespace std;

int main () {

    int n, m;

    while (cin >> m >> n && m + n) {
        int res = (m * n + 1) / 2;

        if (n == 1 || m == 1) { res = max(n, m); }
        else if (n == 2 || m == 2) {
            res = max(m, n);
            int r = res % 4;
            
            if (r == 1 || r == 3) { res += 1; }
            else if (r == 2) { res += 2; }
        }
        printf("%d knights may be placed on a %d row %d column board.\n", 
               res, m, n);
    }
    return 0;
}