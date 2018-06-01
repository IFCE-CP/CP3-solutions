#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t = 1;
    string s;
    
    while (cin >> s && s != "end") {
        vector<stack<char>> v;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            bool flag = true;
            for (int j = 0; j < v.size() && flag; j++) {
                if (!v[j].empty() && v[j].top() >= s[i]) {
                    v[j].push(s[i]);
                    flag = false;
                }
            }
            if (flag) {
                res++;
                stack<char> sta;
                sta.push(s[i]);
                v.push_back(sta);
            }
        }
        printf("Case %d: %d\n", t++, res);
    }
    return 0;
}