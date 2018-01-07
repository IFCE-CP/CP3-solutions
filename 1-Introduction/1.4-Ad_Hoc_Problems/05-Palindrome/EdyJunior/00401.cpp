#include <bits/stdc++.h>

using namespace std;

map<char, char> rev = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'},
	                   {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'},
                       {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
                       {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
                       {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'},
                       {'8', '8'}};

bool isPalind (string s) {

    int size = s.size();
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) { return false; }
    }
    return true;
}

bool isMirror (string s) {

    int size = s.size();
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        char si = s[i], c = si;
        if (rev.find(si) != rev.end()) { c = rev[si]; }
        else { return false; }

        if (s[j] != c) { return false; }
    }
    return true;
}

int main () {
    
    string s;

    while (getline(cin, s)) {
        bool isP = isPalind(s);
        bool isM = isMirror(s);

        if (isP && isM) { printf("%s -- is a mirrored palindrome.\n\n", s.c_str()); }
        else if (isP) { printf("%s -- is a regular palindrome.\n\n", s.c_str()); }
        else if (isM) { printf("%s -- is a mirrored string.\n\n", s.c_str()); }
        else { printf("%s -- is not a palindrome.\n\n", s.c_str()); }
    }
    return 0;
}