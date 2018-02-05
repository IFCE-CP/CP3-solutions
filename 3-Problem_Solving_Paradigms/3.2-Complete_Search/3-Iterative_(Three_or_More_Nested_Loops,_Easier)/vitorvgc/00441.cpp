#include <bits/stdc++.h>

using namespace std;

int l[15];

int main() {
    int k;
    bool first = true;
    while(scanf("%d", &k) && k) {
        for(int i = 0; i < k; ++i)
            scanf("%d", &l[i]);
        
        if(!first) printf("\n");

        for(int a = 0; a < k-5; ++a)
            for(int b = a+1; b < k-4; ++b)
                for(int c = b+1; c < k-3; ++c)
                    for(int d = c+1; d < k-2; ++d)
                        for(int e = d+1; e < k-1; ++e)
                            for(int f = e+1; f < k; ++f)
                                printf("%d %d %d %d %d %d\n", l[a], l[b], l[c], l[d], l[e], l[f]);

        first = false;
    }
    return 0;
}
