#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    for(int t = 1; cin >> s && s != "end"; ++t) {
        string top = "Z";
        for(auto c : s) {
            
            bool placed = false;
            for(int i = 0; top[i] && !placed; ++i)
                if(top[i] >= c)
                    top[i] = c, placed = true;

            if(!placed) top += c;
        }
        cout << "Case " << t << ": " << top.length() << '\n';
    }
    return 0;
}
