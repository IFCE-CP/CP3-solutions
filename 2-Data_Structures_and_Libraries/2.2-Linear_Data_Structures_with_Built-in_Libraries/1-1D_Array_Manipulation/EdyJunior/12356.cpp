#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;

int main () {
	
    int s, b;

    while (scanf("%d %d", &s, &b) && s + b) {
        pii v[s + 1];
        for (int i = 0; i <= s; i++) {
            v[i] = make_pair(i - 1, i + 1);
        }
        for (int i = 0, left, right; i < b; i++) {
            scanf("%d %d", &left, &right);
            v[v[left].F].S = v[right].S;
            v[v[right].S].F = v[left].F;
            if (v[left].F < 1) { printf("* "); }
            else { printf("%d ", v[left].F); }
            if (v[right].S > s) { printf("*\n"); }
            else { printf("%d\n", v[right].S); }
        }
        printf("-\n");
    }
    return 0;
}