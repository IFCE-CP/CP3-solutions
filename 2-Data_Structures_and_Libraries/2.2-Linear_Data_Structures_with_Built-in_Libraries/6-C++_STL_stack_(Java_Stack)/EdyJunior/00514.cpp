#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;

    while (scanf("%d", &n) && n) {
        vector<int> v(n + 1);
        while (scanf("%d", &v[1]) && v[1]) {
            int pos = 1;
            for (int i = 2; i <= n; ++i)
                scanf("%d", &v[i]);
            stack<int> s;
            vector<int> o;
            for (int i = 1; i <= n;) {
                if (i != v[pos]) {
                    if(!s.empty() && s.top() == v[pos]) {
                        o.push_back(s.top());
                        s.pop();
                        pos++;
                    } else { 
                        s.push(i);
                        i++;
                    }
                } else { 
                    o.push_back(i);
                    pos++;
                    i++;
                }
            }
            while (!s.empty()) {
                o.push_back(s.top());
                s.pop();
            }
            bool flag = true;
            for (int i = 1; i <= n && flag; i++)
                flag = flag && (o[i - 1] == v[i]);
            printf("%s\n", flag ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}