#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

set<int> scores;
set<vi> comb, perm;

int main() {
    int n;
    for(int i = 0; i <= 20; ++i) {
        scores.insert(i);
        scores.insert(2*i);
        scores.insert(3*i);
    }
    scores.insert(50);

    while(scanf("%d", &n) && n > 0) {

        comb.clear();
        perm.clear();
        for(auto a : scores)
            for(auto b : scores)
                for(auto c : scores)
                    if(a + b + c == n) {
                        vi v {a, b, c};
                        perm.insert(v);
                        sort(v.begin(), v.end());
                        comb.insert(v);
                    }
        if(perm.empty())
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %llu.\n", n, comb.size());
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %llu.\n", n, perm.size());
        }
        for(int i = 0; i < 70; ++i)
            printf("*");
        printf("\n");
    }

    printf("END OF OUTPUT\n");
    return 0;
}
