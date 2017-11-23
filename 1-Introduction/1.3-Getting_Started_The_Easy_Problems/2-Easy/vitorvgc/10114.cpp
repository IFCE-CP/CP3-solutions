#include <bits/stdc++.h>

using namespace std;

pair<int, double> l[110];

int main() {
    int months, n;
    double downPayment, loan;
    while(scanf("%d %lf %lf %d", &months, &downPayment, &loan, &n) && months >= 0) {
        for(int i = 0; i < n; ++i)
            scanf("%d %lf", &l[i].first, &l[i].second);
        l[n].first = 1010;
        int m = 0;
        int dep = 0;
        double monthlyPayment = loan / months;
        double value = loan + downPayment;
        value -= value * l[0].second;
        while(loan >= value) {
            ++m;
            if(m == l[dep+1].first)
                ++dep;
            loan -= monthlyPayment;
            value -= value * l[dep].second;
        }
        printf("%d month%s\n", m, m == 1 ? "" : "s");
    }
    return 0;
}
