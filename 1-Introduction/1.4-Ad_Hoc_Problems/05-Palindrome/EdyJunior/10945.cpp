#include <bits/stdc++.h>

using namespace std;

bool isPalind (char s[], int size) {

    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) { return false; }
    }
    return true;
}

int main () {

    string s;

    while (getline(cin, s) && s != "DONE") {
        int size = s.size(), c = 0;
        char aux[size + 1];

        for (int i = 0; i < size; i++) {
            if (s[i] != '!' && s[i] != '?' && s[i] != ' ' && s[i] != ',' && s[i] != '.') {
                if (s[i] >= 'A' && s[i] <= 'Z') { s[i] = s[i] + ('a' - 'A'); }
                aux[c++] = s[i];
            }
        }
        aux[c] = '\0';
        printf("%s\n", isPalind(aux, c) ? "You won't be eaten!" : "Uh oh..");
    }
    return 0;
}