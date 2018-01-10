#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        bool isStack = true, isQueue = true, isPQ = true;
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;

        while(n--) {
            int op, x;
            scanf("%d %d", &op, &x);
            if(op == 1) {
                if(isStack) stk.push(x);
                if(isQueue) q.push(x);
                if(isPQ) pq.push(x);
            }
            else {
                if(isStack) {
                    if(!stk.empty() && stk.top() == x) stk.pop();
                    else isStack = false;
                }
                if(isQueue) {
                    if(!q.empty() && q.front() == x) q.pop();
                    else isQueue = false;
                }
                if(isPQ) {
                    if(!pq.empty() && pq.top() == x) pq.pop();
                    else isPQ = false;
                }
            }
        }

        int count = isStack + isQueue + isPQ;
        if(count == 0)
            printf("impossible\n");
        else if(count > 1)
            printf("not sure\n");
        else if(isStack)
            printf("stack\n");
        else if(isQueue)
            printf("queue\n");
        else
            printf("priority queue\n");
    }
    return 0;
}
