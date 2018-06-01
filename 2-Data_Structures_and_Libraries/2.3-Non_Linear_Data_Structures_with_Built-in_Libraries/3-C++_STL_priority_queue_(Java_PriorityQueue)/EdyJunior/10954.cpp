#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, v;
    while (scanf("%d", &n) != EOF && n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        while (n--) {
            scanf("%d", &v);
            pq.push(v);
        }
        while (!pq.empty()) {
            int a = 0, b = 0;
            a = pq.top();
            pq.pop();
            if (!pq.empty()) {
                b = pq.top();
                pq.pop();
            }
            a += b;
            sum += a;
            if (!pq.empty())
                pq.push(a);
        }
        printf("%d\n", sum);
    }
    return 0;
}