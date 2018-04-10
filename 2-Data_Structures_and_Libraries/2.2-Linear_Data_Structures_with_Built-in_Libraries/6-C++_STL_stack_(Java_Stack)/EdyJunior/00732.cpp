#include <bits/stdc++.h>

using namespace std;

set<string> s;

void trans(string a, string b, int posA = 0, int posB = 0, string res = "", string stk = "", string word = "") {

    if (posA == a.size()) {
        if (stk != "")
            for (int i = stk.size() - 1; i >= 0; i--) {
                word += stk[i];
                stk = stk.substr(0, stk.size() - 1);
                res += 'o';
            }
    } else {
        if (a[posA] == b[posB])
            trans(a, b, posA + 1, posB + 1, res + "io", stk, word + a[posA]);
        if (stk != "" && stk[stk.size() - 1] == b[posB])
            trans(a, b, posA, posB + 1, res + 'o', stk.substr(0, stk.size() - 1), word + stk[stk.size() - 1]);
        trans(a, b, posA + 1, posB, res + 'i', stk + a[posA], word);
    }
    
    if (word == b)
        s.insert(res);
}

int main () {
    
    string a, b, res;
    while(getline(cin, a)) {
        getline(cin, b);
        s.clear();
        trans(a, b);
        vector<string> v(s.begin(), s.end());
        sort(v.begin(), v.end());
        printf("[\n");
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (j) { printf(" "); }
                printf("%c", v[i][j]);
            }
            printf("\n");
        }
        printf("]\n");
    }
    return 0;
}