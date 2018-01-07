#include <bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<1100100> l;

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) && n|m) {
        
        bool ok = true;
        l = 0;

        while(n--) {
            int a, b;
            scanf("%d %d", &a, &b);
            if(!ok) continue;

            for(int i = a; i < b; ++i) {
                if(l.test(i)) ok = false;
                else l.set(i);
            }
        }

        while(m--) {
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);
            if(!ok) continue;

            for(int k = 0; a + k*t < MAX; ++k) {
                
                for(int i = a + k*t; i < min(b + k*t, MAX); ++i) {
                    if(l.test(i)) ok = false;
                    else l.set(i);
                }

            }
        }

        printf("%sCONFLICT\n", ok ? "NO " : "");
    }
    return 0;
}
