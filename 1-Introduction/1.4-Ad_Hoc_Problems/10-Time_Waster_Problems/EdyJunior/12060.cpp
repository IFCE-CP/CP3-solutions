#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) {

	a %= b;
	if (!a) { return b; }
	return mdc (max(a, b), min(a, b));
}

int main () {

    int n, count = 1;
    while (cin >> n && n) {
        int tot = 0;
        for (int i = 0, k; i < n; i++) {
            cin >> k;
            tot += k;
        }
        printf("Case %d:\n", count++);
        if (tot % n == 0) { 
            if (tot < 0) { printf("- "); }
            printf("%d\n", abs((int) (tot / n))); 
		}
        else {
            int a, b, c, nA, nB, nC, distB = 0, distC = 0;
            a = abs((int) (tot / n));
            c = n;
			 
            if (a < 1) { 
                nA = 0; 
                b = abs(tot);
            }
            else {
                b = abs(tot) % n;   
                nA = 1 + log10(a);
            }
            int m = mdc(max(b, c), min(b, c));
            b /= m;
            c /= m;
            nB = 1 + log10(b);
            nC = 1 + log10(c);
            if (tot < 0) { 
                distB += 2;
                distC += 2;
            }
            distB += nA;
            distC += nA;
            if(nC > nB) { distB += (nC - nB); }

            for (int i = 0; i < distB; i++) { printf(" "); }
            printf("%d\n", b);
            if (tot < 0) { printf("- "); }
            if (a) { printf("%d", a); }
            for (int i = 0; i < nC; i++) { printf("-"); }
            printf("\n");
            for (int i = 0; i < distC; i++) { printf(" "); }
            printf("%d\n", c);
        }
    }
    return 0;
}