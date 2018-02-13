#include <bits/stdc++.h>

using namespace std;

int main () {

    long long int sz, p;

    while (scanf("%lld %lld", &sz, &p) && sz + p) {
        long long int l = 1, i = 1, m = 1 + sz / 2;
        for (; l <= p; i++)
            l = i * (i + 1) + 1; 
        i -= 2;
        l = i * (i + 1) + 1;
        long long int line, top, col, factor1 = -1, factor2 = 1, step = i + 1;

        if ((i & 1) == 1) {
            factor1 *= -1;
            factor2 *= -1;            
        }
        i = i / 2 + ((i & 1) == 1 ? 1 : 0);
        top = l + step;
        line = m + (i * factor1);
        col = m + (i * factor2);

        while (l < p && l < top && l < sz * sz) {
            l++;
            line += factor2;
        }
        if (l != p)
            while (l < p) {
                l++;
                col += factor1;
            }
        printf("Line = %lld, column = %lld.\n", line, col);
    }
    return 0;
}