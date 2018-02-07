#include <bits/stdc++.h>

#define MAX 2000000000.0

using namespace std;

typedef long long int ll;

int main() {

    int mxA = ceil(pow(MAX, 0.25));
    for(int a = 1; a <= mxA; ++a) {
        int mxB = ceil(pow(MAX/a, 1.0/3));
        for(int b = a; b <= mxB && a+b <= 2000; ++b) {
            int mxC = ceil(sqrt(MAX/(a*b)));
            for(int c = b; c <= mxC && a+b+c <= 2000; ++c) {
                ll s = a+b+c, p = a*b*c, p10 = 1000000;
                if((p <= p10) || ((p10*s) % (p - p10))) continue;
                ll d = (p10*(a+b+c)) / (a*b*c - p10);
                if(d >= c && a+b+c+d <= 2000)
                    printf("%d.%02d %d.%02d %d.%02d %lld.%02lld\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
            }
        }
    }
    return 0;
}
