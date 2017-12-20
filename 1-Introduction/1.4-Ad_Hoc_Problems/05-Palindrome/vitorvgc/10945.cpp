#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    
    bool ok = true;
    for(unsigned i = 0; i < s.length() / 2; ++i)
        ok &= (s[i] == s[s.length() -i - 1]);
    return ok;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(getline(cin, s) && s != "DONE") {
        string s2 = "";
        for(auto c : s)
            if(isalpha(c))
                s2 += tolower(c);
        cout << (isPalindrome(s2) ? "You won't be eaten!" : "Uh oh..") << '\n';
    }
    return 0;
}
