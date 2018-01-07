#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s) {
        list<char> l;
        auto it = l.begin();
        bool atEnd = true;
        for(auto c : s) {
            if(c == ']') atEnd = true;
            else if(c == '[') atEnd = false, it = l.begin();
            else if(atEnd) l.push_back(c);
            else l.insert(it, c);
        }

        for(auto it = l.begin(); it != l.end(); ++it)
            cout << *it;
        cout << '\n';
    }
    return 0;
}
