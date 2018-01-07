#include <bits/stdc++.h>

#define MAX 3010

using namespace std;

int l[MAX];
bool contains[MAX];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(contains, 0, sizeof contains);
        for(int i = 0; i < n; ++i)
            scanf("%d", &l[i]);
        for(int i = 0; i < n-1; ++i)
            contains[abs(l[i] - l[i+1])] = true;

        bool jolly = true;
        for(int i = 1; i < n && jolly; ++i)
            jolly &= contains[i];

        printf("%s\n", jolly ? "Jolly" : "Not jolly");
    }
    return 0;
}
