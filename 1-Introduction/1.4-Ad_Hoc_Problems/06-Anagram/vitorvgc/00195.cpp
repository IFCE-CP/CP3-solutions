#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

bool cmp(string a, string b) {
    
    for(unsigned i = 0; i < a.length(); ++i) {
        char ca = tolower(a[i]);
        char cb = tolower(b[i]);
        if(ca != cb)
            return ca < cb;
        else if((islower(a[i]) && isupper(b[i])) ||
                (isupper(a[i]) && islower(b[i])))
            return isupper(a[i]);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    string s;
    for(cin >> t; t--; ) {
        cin >> s;
        sort(all(s));
        vector<string> ans;
        do {
            ans.push_back(s);
        } while(next_permutation(all(s)));
        unique(all(ans));
        sort(all(ans), cmp);
        for(auto s : ans) cout << s << '\n';
    }
    return 0;
}
