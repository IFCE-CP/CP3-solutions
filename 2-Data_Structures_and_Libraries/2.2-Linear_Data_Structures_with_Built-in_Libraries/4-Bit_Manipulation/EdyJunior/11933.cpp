#include <bits/stdc++.h>

using namespace std;

int main () {
    
    int n;
    while (scanf("%d", &n) && n) {
        int a = 0, b = 0, c = 1;
        for (int i = 0; i < 31; i++) {
            int v = 1 << i;
            if (v & n) {
                if (c & 1) { a |= v; }
                else { b |= v; }
                c++;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}