#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n, c;
    while (scanf("%d", &n) != EOF && n) {
        map<set<int>, int> m;
        int res = 0;
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j < 5; j++) {
                scanf("%d", &c);
                s.insert(c);
            }
            if (m.find(s) != m.end())
                m[s]++;
            else
                m[s] = 1;
            if(res < m[s])
            	res = m[s];
        }
        int c = 0;
        for (auto it : m)
            if (it.second == res)
            	c += res;
        printf("%d\n", c);
    }
    return 0;
}