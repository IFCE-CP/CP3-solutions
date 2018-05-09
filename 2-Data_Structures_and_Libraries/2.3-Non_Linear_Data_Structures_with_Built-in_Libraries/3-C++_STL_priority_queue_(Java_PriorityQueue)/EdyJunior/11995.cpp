#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    while (scanf("%d", &n) != EOF) {
        stack<int> sta;
        priority_queue<int> pri;
        queue<int> que;
        
        int s = 0, p = 0, q = 0, h = 0;
        
        for (int i = 0; i < n; i++) {
            int c, x;
            scanf("%d %d", &c, &x);
            if (c == 1) {
                sta.push(x);
                pri.push(x);
                que.push(x);
            } else {
                int a = -1, b = -1, c = -1;
                h++;
                if (!sta.empty()) {
                    a = sta.top();
                    sta.pop();
                }
                if (!pri.empty()) {
                    b = pri.top();
                    pri.pop();
                }
                if (!que.empty()) {
                    c = que.front();
                    que.pop();
                }
                if(a == x)
                    s++;
                if(b == x)
                    p++;
                if(c == x)
                    q++;
            }
        }
        if(s == h) {
            if (s != p && s != q)
                printf("stack\n");
            else
                printf("not sure\n");
        } else if(p == h) {
            if (p != s && p != q)
                printf("priority queue\n");
            else
                printf("not sure\n");
        } else if(q == h) {
            if (q != p && q != s)
                printf("queue\n");
            else
                printf("not sure\n");
        } else
            printf("impossible\n");
    }
    return 0;
}