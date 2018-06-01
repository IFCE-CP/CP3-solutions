#include <bits/stdc++.h>

#define MAX 1001001

using namespace std;

int p[MAX], r[MAX];

int Find(int i) {

    if (p[i] == i)
        return i;
    return p[i] = Find(p[i]);
}

void Union(int i, int j) {

    int x = Find(i);
    int y = Find(j);
    if (x != y) {
        if (r[x] >= r[y]) {
            p[y] = x;
            r[x]++;
        } else {
            p[x] = y;
            r[y]++;
        }
    }
}

int main() {

    int n, t, a, b, cs = 1;
    for (scanf("%d", &n); n > 0; n--) {
        if (cs)
            cs = 0;
        else
            printf("\n");
        scanf("%d", &t);
        for (int i = 0; i <= t; i++) {
            p[i] = i;
            r[i] = 0;
        }
        getchar();
        char line[30], cmd;
        int s = 0, u = 0;
        while(gets(line) && strcmp(line, "")) {
            sscanf(line, "%c %d %d", &cmd, &a, &b);
            if (cmd == 'c')
                Union(a, b);
            else {
                int x = Find(a);
                int y = Find(b);
                if (x == y)
                    s++;
                else
                    u++;
            }
        }
        printf("%d,%d\n", s, u);
    }
    return 0;
}