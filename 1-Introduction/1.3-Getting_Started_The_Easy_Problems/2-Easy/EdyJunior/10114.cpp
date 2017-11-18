#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    
    int mon, dep;
    double down, loan;
    
    while (scanf("%d %lf %lf %d", &mon, &down, &loan, &dep) && mon >= 0) {        
        int pos = 0, m = -1;
        double perc, car = loan + down, vec[mon + 1];

        for (int i = 0; i < dep; i++) {
            scanf("%d %lf", &m, &perc);
            vec[m] = perc;
            double last = vec[pos];
            for (int j = pos; j < m; j++) { vec[j] = last; }
            pos = m;
        }
        perc = vec[m];
        for (int i = m + 1; i <= mon; i++) { vec[i] = perc; }

        int res = 0;
        car -= (vec[0] * car);

        down = loan / mon;

        for (; res <= mon && loan >= car;) {
            car -= (vec[++res] * car);
            if (loan > down) { loan -= down; }
            else { loan = 0; }
        }
        printf("%d month%s", res, res != 1 ? "s\n" : "\n");
    }
    return 0;
}

/*

30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1

*/