#include <bits/stdc++.h>

using namespace std;

#define MAX (1 << 15) + 1

int main () {

    int n, weights[MAX], potencies[MAX];

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < (1 << n); i++)
        	scanf("%d", &weights[i]);
        for (int i = 0; i < (1 << n); i++) {
            int potency = 0;
            for (int j = 0; j < n; j++) {
                int b = i ^ (1 << j);
                potency += weights[b];
            }
            potencies[i] = potency;
        }
        int best = 0;
        for (int i = 0; i < (1 << n); i++) {
            int p = potencies[i];
            for (int j = 0; j < n; j++) {
                int b = i ^ (1 << j);
                best = max(best, p + potencies[b]);
            }
        }
        printf("%d\n", best);
    }
    return 0;
}