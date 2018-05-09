#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, first = 1;
    for (scanf("%d", &n); n > 0; n--) {
        int b, sg, sb;
        scanf("%d %d %d", &b, &sg, &sb);
        priority_queue<int> pg, pb;
        for (int i = 0, a; i < sg; i++) {
            scanf("%d", &a);
            pg.push(a);
        }
        for (int i = 0, a; i < sb; i++) {
            scanf("%d", &a);
            pb.push(a);
        }
        while (!pg.empty() && !pb.empty()) {
            priority_queue<int> ag, ab;
            for (int i = 0; i < b && !pg.empty() && !pb.empty(); i++) {
                int vg = pg.top();
                pg.pop();
                int vb = pb.top();
                pb.pop();
                if (vg > vb)
                    ag.push(vg - vb);
                else if (vb > vg)
                    ab.push(vb - vg);
            }
            while (!ag.empty()) {
                pg.push(ag.top());
                ag.pop();
            }
            while (!ab.empty()) {
                pb.push(ab.top());
                ab.pop();
            }
        }
        if (!first)
            printf("\n");
        else
            first--;
        if (!pg.empty()) {
            printf("green wins\n");
            while (!pg.empty()) {
                printf("%d\n", pg.top());
                pg.pop();
            }
        } else if (!pb.empty()) {
            printf("blue wins\n");
            while (!pb.empty()) {
                printf("%d\n", pb.top());
                pb.pop();
            }
        } else
            printf("green and blue died\n");
    }
    return 0;
}