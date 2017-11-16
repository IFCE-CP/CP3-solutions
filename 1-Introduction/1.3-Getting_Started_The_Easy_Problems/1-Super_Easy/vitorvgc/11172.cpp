#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, x, y;
    for(scanf("%d", &t); t; --t) {
        scanf("%d %d", &x, &y);
        printf("%c\n", x == y ? '=' : x > y ? '>' : '<');
    }
    return 0;
}
