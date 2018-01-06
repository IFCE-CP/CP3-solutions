#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

void insert(int x) {
    
    if(maxHeap.empty() || x < maxHeap.top())
        maxHeap.push(x);
    else
        minHeap.push(x);

    if(maxHeap.size() > minHeap.size() + 1)
        minHeap.push(maxHeap.top()), maxHeap.pop();
    else if(minHeap.size() > maxHeap.size() + 1)
        maxHeap.push(minHeap.top()), minHeap.pop();
}

int median() {
    
    if(minHeap.size() == maxHeap.size())
        return (minHeap.top() + maxHeap.top()) / 2;

    return (minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top());
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        insert(n);
        printf("%d\n", median());
    }
    return 0;
}
