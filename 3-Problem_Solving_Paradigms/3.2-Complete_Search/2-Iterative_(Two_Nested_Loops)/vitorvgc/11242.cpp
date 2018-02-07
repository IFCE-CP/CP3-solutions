#include <bits/stdc++.h>

using namespace std;

int front[15];

int main() {
    int f, r;
    while(scanf("%d", &f) && f) {
        vector<double> drive;
        scanf("%d", &r);
        for(int i = 0; i < f; ++i)
            scanf("%d", &front[i]);
        for(int i = 0; i < r; ++i) {
            double rear;
            scanf("%lf", &rear);
            for(int j = 0; j < f; ++j)
                drive.push_back(rear / front[j]);
        }

        sort(drive.begin(), drive.end());

        double ans = 0;
        for(unsigned i = 1; i < drive.size(); ++i)
            ans = max(ans, drive[i] / drive[i-1]);

        printf("%.2lf\n", ans);
    }
    return 0;
}
