#include <bits/stdc++.h>

#define MAX 100100

using namespace std;

int esq[MAX], dir[MAX];

int main() {
    int n, b;
    while(scanf("%d %d", &n, &b) && n|b) {
        
        esq[1] = dir[n] = -1;
        for(int i = 2; i <= n; ++i)
            esq[i] = i-1;
        for(int i = 1; i < n; ++i)
            dir[i] = i+1;

        while(b--) {
            int l, r;
            scanf("%d %d", &l, &r);
            if(esq[l] != -1) dir[esq[l]] = dir[r];
            if(dir[r] != -1) esq[dir[r]] = esq[l];
            
            esq[l] != -1 ? printf("%d ", esq[l])  : printf("* ");
            dir[r] != -1 ? printf("%d\n", dir[r]) : printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
