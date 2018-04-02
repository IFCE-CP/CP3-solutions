#include <bits/stdc++.h>

using namespace std;

int s, d;
int l[12];

int solve(int i = 0, int sum = 0) {
    
    if(i >= 12)
        return sum;

    int c1 = INT_MIN, c2 = INT_MIN;

    int pastSum = 0;
    if(i >= 4)
        for(int j = i-4; j < i; j++)
            pastSum += (l[j] > 0 ? s : -d);

    if(i < 4 || pastSum - d < 0) {
        l[i] = -1;
        c1 = solve(i+1, sum - d);
    }
    if(i < 4 || pastSum + s < 0) {
        l[i] = 1;
        c2 = solve(i+1, sum + s);
    }

    return max(c1, c2);
}

int main() {

    while(scanf("%d %d", &s, &d) != EOF) {
        int ans = solve();
        if(ans < 0)
            printf("Deficit\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
