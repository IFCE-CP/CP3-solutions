#include <bits/stdc++.h>

using namespace std;

void print(priority_queue<int> pq) {
    for(; !pq.empty(); pq.pop())
        printf("%d\n", pq.top());
}

int main() {
    int t;
    for(scanf("%d", &t); t--; ) {
        int b, sg, sb;
        priority_queue<int> pqg, pqb;
        scanf("%d %d %d", &b, &sg, &sb);
        for(int i = 0, x; i < sg; ++i) {
            scanf("%d", &x);
            pqg.push(x);
        }
        for(int i = 0, x; i < sb; ++i) {
            scanf("%d", &x);
            pqb.push(x);
        }

        while(!pqg.empty() && !pqb.empty()) {
            
            int n = min(b, (int)min(pqg.size(), pqb.size()));
            vector<int> surv;
            for(int i = 0; i < n; ++i) {
                int g = pqg.top(); pqg.pop();
                int b = pqb.top(); pqb.pop();

                surv.push_back(g-b);
            }
            for(auto x : surv) {
                if(x > 0) pqg.push(x);
                else if(x < 0) pqb.push(-x);
            }
        }
        
        if(pqg.empty() && pqb.empty())
            printf("green and blue died\n");
        else {
            printf("%s wins\n", !pqg.empty() ? "green" : "blue");
            print(!pqg.empty() ? pqg : pqb);
        }

        if(t) printf("\n");
    } 
    return 0;
}
