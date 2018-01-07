#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin >> s && s != "#")
        cout << (next_permutation(s.begin(), s.end()) ? s : "No Successor") << '\n';
    return 0;
}
