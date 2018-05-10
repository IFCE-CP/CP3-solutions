#include <bits/stdc++.h>

using namespace std;

int p[30], r[30], seen[30];

int Find(int f) {

    if (p[f] == f)
        return f;
    return p[f] = Find(p[f]);
}

void Union(int a, int b) {

    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) {
        if (r[pa] >= r[pb]) {
            p[pb] = pa;
            r[pa]++;
        } else {
            p[pa] = pb;
            r[pb]++;
        }
    }
}

int main() {
    
    int n;
    for (scanf("%d", &n); n > 0; n--) {
        char line[30], a, b;
        for (int i = 0; i < 26; i++) {
            p[i] = i;
            r[i] = seen[i] = 0;
        }
        while (scanf("%s", line) && line[0] != '*') {
            sscanf(line, "(%c,%c)", &a, &b);
            Union(a - 'A', b - 'A');
        }
        scanf("%s", line);
        for (int i = 0; line[i]; i++)
            if (line[i] != ',')
                seen[line[i] - 'A'] = 1;
        int tree = 0, acorn = 0;
        for (int i = 0; i < 26; i++) {
            if (!seen[i])
                continue;
            if (p[i] == i) {
                if (!r[i])
                    acorn++;
                else
                    tree++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
    return 0;
}