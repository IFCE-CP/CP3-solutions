#include <bits/stdc++.h>

using namespace std;

string a, b;
stack<char> stk;
string ans;

void solve(int n = a.length(), int ni = 0, int no = 0) {
    
    if(no == n) {
        cout << ans[0];
        for(int i = 1; ans[i]; ++i)
            cout << ' ' << ans[i];
        cout << '\n';
        return;
    }

    if(ni < n) {
        stk.push(a[ni]);
        ans += 'i';
        solve(n, ni+1, no);
        stk.pop();
        ans.pop_back();
    }

    if(no < ni && stk.top() == b[no]) {
        char c = stk.top();
        stk.pop();
        ans += 'o';
        solve(n, ni, no+1);
        stk.push(c);
        ans.pop_back();
    }
}

bool isPermutation(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(getline(cin, a)) {
        getline(cin,b);
        
        if(a.length() != b.length() || !isPermutation(a, b))
            cout << "[\n]\n";
        else {
            stk = stack<char>();
            ans = "";
            cout << "[\n";
            solve();
            cout << "]\n";
        }
    }
    return 0;
}
