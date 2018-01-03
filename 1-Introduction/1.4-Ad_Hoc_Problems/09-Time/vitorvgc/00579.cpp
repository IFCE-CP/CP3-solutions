#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, m;
    char s[10];
    while(gets(s)) {
        sscanf(s, "%d:%d", &h, &m);
        if(h + m == 0) break;
        double a = 30 * (h % 12) + m / 2.0;
        double b = 6 * m;
        double ans = abs(a - b);
        if(ans > 180) ans = 360 - ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}
