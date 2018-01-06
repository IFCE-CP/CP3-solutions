#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int a = 0, b = 0;
        for(int k = 0; n; k = !k) {
            int lsb = n & -n;
            if(!k) a += lsb;
            else b += lsb;
            n -= lsb;
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}
