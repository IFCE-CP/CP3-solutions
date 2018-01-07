#include <bits/stdc++.h>

using namespace std;

bool isPalind (char s[], int size) {

    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) { return false; }
    }
    return true;
}

int main () {

    int t;
    cin >> t;
    getchar();

    for (int i = 1; i <= t; i++) {
        string s;
        getline(cin, s);

        int size = s.size(), newSize = 0;
        char aux[size + 1];

        for (int i = 0; i < size; i++) {
            if (s[i] != '!' && s[i] != '?' && s[i] != ' ' && s[i] != ',' &&
                s[i] != '.' && s[i] != '(' && s[i] != ')') {
                aux[newSize++] = s[i];
            }
        }
        aux[newSize] = '\0';

        printf("Case #%d:\n", i);

        int root = (int) sqrt(double(newSize));
        if (newSize != root * root || !isPalind(aux, newSize)) {
            printf("No magic :(\n");
        } else {
            int c = 0;
            char table[root + 1][root + 1];

            for (int j = 0; j < root; j++) {
                for (int k = 0; k < root; k++) {
                    table[j][k] = aux[c++];
                }
            }
            bool flag = true;
            for (int j = 0; j < root && flag; j++) {
                for (int k = 0; k < root && flag; k++) {
                    if(table[j][k] != table[k][j]) {
                        flag = false;
                    }
                }
            }
            if (flag) { printf("%d\n", root); }
            else { printf("No magic :(\n" ); }
        }
    }
    return 0;
}