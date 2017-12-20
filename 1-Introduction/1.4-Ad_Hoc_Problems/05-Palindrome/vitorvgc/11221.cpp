#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    
    bool ok = true;
    for(unsigned i = 0; i < s.length() / 2; ++i)
        ok &= (s[i] == s[s.length() - i - 1]);
    return ok;
}

int isMagicSquare(string s) {
    
    int k = sqrt(s.length());
    if(k * k != s.length()) return -1;

    string s2 = s;
    for(int i = 0, len = 0; i < k; ++i)
        for(int j = 0; j < k; ++j)
            s2[i + j*k] = s[len++];

    return (isPalindrome(s) && isPalindrome(s2) ? k : -1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int t;
    cin >> t; cin.ignore();
    for(int i = 1; i <= t; ++i) {
        getline(cin, s);
        string aux;
        for(auto c : s)
            if(isalpha(c))
                aux += c;
        cout << "Case #" << i << ":\n";
        int ans = isMagicSquare(aux);
        if(ans == -1) cout << "No magic :(\n";
        else cout << ans << '\n';
    }
    return 0;
}
