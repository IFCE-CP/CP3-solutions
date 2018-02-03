#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    while(scanf("%d", &k) != EOF) {
        vector<int> v;
        for(int y = k+1; y <= 2*k; ++y)
            if(!(y*k % (y - k)))
                v.push_back(y);

        printf("%llu\n", v.size());
        for(auto y : v)
            printf("1/%d = 1/%d + 1/%d\n", k, y*k / (y - k), y);
    }
    return 0;
}
