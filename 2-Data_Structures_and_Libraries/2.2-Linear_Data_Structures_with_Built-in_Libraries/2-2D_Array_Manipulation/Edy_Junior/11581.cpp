#include <bits/stdc++.h>

using namespace std;

#define isAllowed(x, y) x >= 0 && x < 3 && y >= 0 && y < 3

typedef vector<string> vs;

int dx[] = { -1,  0, 1, 0 };
int dy[] = {  0, -1, 0, 1 };

string getString(vs a) {
    
    string res = "";
    for (auto line : a) { res += line; }
    return res;
}

vs f(vs g) {

    vs res = { "", "", "" };
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int k = 0; k < 4; k++) {
                int newX = j + dx[k];
                int newY = i + dy[k];
                if (isAllowed(newX, newY))
                    sum += (g[newY][newX] - '0');
            }
            res[i] += ((sum % 2) + '0');
        }
    return res;
}

int main () {
    
    int n;
    string flag = "000000000";

    for (scanf("%d", &n); n > 0; n--) {
        
        vs g(3);
        for (int i = 0; i < 3; i++) { cin >> g[i]; }

        string gs = getString(g);
        int res = -1;
        if (gs != flag) { res++; }

        while (true) {
            g = f(g);
            string line = getString(g);
            if (line == flag) { break; }
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}