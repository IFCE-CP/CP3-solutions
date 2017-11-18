#include <bits/stdc++.h>

using namespace std;

int main() {
    double h, u, d, f;
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f) && h) {
        f /= 100.0;
        double height = 0;
        double climb = u;
        int day = 0;
        while(height >= 0 && height <= h) {
            ++day;
            height += climb;
            climb = max(climb - f*u, 0.0);
            if(height > h) break;
            height -= d;
        } 
        printf("%s on day %d\n", height >= h ? "success" : "failure", day);
    }
    return 0;
}
