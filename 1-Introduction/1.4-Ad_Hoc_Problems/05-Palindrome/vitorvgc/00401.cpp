#include <bits/stdc++.h>

using namespace std;

map<char, char> mp = {
    {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'},
    {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'},
    {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
    {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
    {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'5', 'Z'},
    {'8', '8'}
};

bool isPalindrome(string s) {

    bool ok = true;
    for(int i = 0; i < s.length() / 2 && ok; ++i)
        ok &= s[i] == s[s.length() - i - 1];
    return ok;
}

bool isMirrored(string s) {
    
    bool ok = true;
    for(int i = 0; i <= s.length() / 2 && ok; ++i) {
        auto it = mp.find(s[i]);
        ok &= (it != mp.end() && s[s.length() - i - 1] == it->second);
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s) {
        bool p = isPalindrome(s);
        bool m = isMirrored(s);

        if(p && m)
            cout << s << " -- is a mirrored palindrome.\n\n";
        else if(p)
            cout << s << " -- is a regular palindrome.\n\n";
        else if(m)
            cout << s << " -- is a mirrored string.\n\n";
        else
            cout << s << " -- is not a palindrome.\n\n";
    }
    return 0;
}
