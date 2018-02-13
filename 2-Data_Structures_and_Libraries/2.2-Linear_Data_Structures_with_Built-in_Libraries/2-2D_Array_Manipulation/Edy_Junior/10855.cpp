#include <bits/stdc++.h>

using namespace std;

vector<string> rotate(vector<string> a, int size) {
    
    vector<string> res(size + 1);

    for (int i = 0; i < size; i++) {
        res[i] = "";
        for (int j = 0; j < size; j++)
            res[i] += a[size - 1 - j][i];
    }
    return res;
}

int search(vector<string> a, vector<string> b, int aSize, int bSize) {

    int res = 0;

    for (int i = 0; i <= aSize - bSize; i++)
        for (int j = 0; j <= aSize - bSize; j++) {
            bool flag = true;
            for (int k = 0; k < bSize && flag; k++) {
                string part = a[i + k].substr(j, bSize);
                if (part != b[k]) { flag = false; }
            }
            if (flag) { res++; }
        }
    return res;
}

int main () {
    
    int m, n, res[4];
    
    while (cin >> m >> n && m + n) {
        vector<string> a(m + 1), b(n + 1);
        for (int i = 0; i < m; i++) { cin >> a[i]; }
        for (int i = 0; i < n; i++) { cin >> b[i]; }
        
        for (int i = 0; i < 4; i++) {
            b = rotate(b, n);
            res[i] = search(a, b, m, n);
        }
        for (int i = 3; i < 7; i++) {
            if (i > 3) { printf(" "); }
            printf("%d", res[i % 4]);
        }
        printf("\n");
    }
    return 0;
}