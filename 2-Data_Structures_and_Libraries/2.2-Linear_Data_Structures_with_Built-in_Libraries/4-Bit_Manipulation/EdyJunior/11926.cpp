#include <bits/stdc++.h>

using namespace std;

bitset<1000001> bs;

bool test(int s, int e) {

    int count = 0;
    for (int j = s; j <= e && j < bs.size(); j++) {
        if (bs.test(j)) {
            count++;
            if (j > s && j < e) { return false; }
        }
        bs.set(j);
    }
    if (count > e - s) { return false; }
    return true;
}

int main () {
    
    int n, m;
    while (scanf("%d %d", &n, &m) && n + m) {
        
        bs.reset();
        bool flag = true;
        for (int i = 0, s, e; i < n; i++) {
            scanf ("%d %d", &s, &e);
            flag = test(s, e);
        }
        for (int i = 0, s, e, p; i < m; i++) {
            scanf ("%d %d %d", &s, &e, &p);
            while (s < bs.size()) {
                flag = test(s, e);
                s += p;
            }
        }
        if (flag) { printf("NO CONFLICT\n"); }
        else { printf("CONFLICT\n"); }
    }
    return 0;
}