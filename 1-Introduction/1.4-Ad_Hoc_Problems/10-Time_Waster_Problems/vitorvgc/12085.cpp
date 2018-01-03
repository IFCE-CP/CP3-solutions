#include <bits/stdc++.h>

using namespace std;

void printRange(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    int p = 0;
    for(; p < int(sa.length()) && sa[p] == sb[p]; ++p);
    cout << "0" << sa << "-" << sb.substr(p) << "\n";
}

int main() {
    int n, caso = 0;
    while(scanf("%d", &n) && n) {
        int a = -1, b = -1, last, x;
        printf("Case %d:\n", ++caso);
        while(n--) {
            scanf("%d", &x);
            if(a == -1) a = x;
            else if(x - last == 1) b = x;
            else if(b == -1) {
                printf("0%d\n", a);
                a = x;
            }
            else {
                printRange(a, b);
                a = x, b = -1;
            }
            last = x;
        }
        if(b == -1) printf("0%d\n", a);
        else printRange(a, b);
        printf("\n");
    }
    return 0;
}
