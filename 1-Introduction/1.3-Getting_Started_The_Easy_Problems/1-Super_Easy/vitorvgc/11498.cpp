#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, cx, cy;
    while(scanf("%d", &t) && t) {
        scanf("%d %d", &cx, &cy);
        while(t--) {
            int x, y;
            scanf("%d %d", &x, &y);
            if(x == cx || y == cy)
                printf("divisa\n");
            else
                printf("%c%c\n", y > cy ? 'N' : 'S', x > cx ? 'E' : 'O');
        }
    }
    return 0;
}
