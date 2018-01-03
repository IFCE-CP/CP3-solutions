#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b) {
    return b ? mdc(b, a%b) : a;
}

int main() {
    int n, caso = 0;
    while(scanf("%d", &n) && n) {
        int num = 0, den = n;
        while(n--) {
            int x;
            scanf("%d", &x);
            num += x;
        }

        bool positive = (num >= 0);
        num = abs(num);

        int m = mdc(num, den);
        num /= m;
        den /= m;

        int integer = num / den;
        num %= den;

        int intLen = to_string(integer).length();
        int denLen = to_string(den).length();

        printf("Case %d:\n", ++caso);
        if(den == 1)
            printf("%s%d\n", positive ? "" : "- ", integer);
        else {
            printf("%s%*d\n", positive ? "" : "  ", denLen + (integer ? intLen : 0), num);
            printf("%s", positive ? "" : "- ");
            if(integer) printf("%d", integer);
            for(int i = 0; i < denLen; ++i)
                printf("-");
            printf("\n%s%*d\n", positive ? "" : "  ", denLen + (integer ? intLen : 0), den);
        }
    }
    return 0;
}
