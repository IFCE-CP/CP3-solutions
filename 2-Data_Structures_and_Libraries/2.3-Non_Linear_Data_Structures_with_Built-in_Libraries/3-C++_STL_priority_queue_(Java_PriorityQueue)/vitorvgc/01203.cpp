#include <bits/stdc++.h>

using namespace std;

struct Query {
    int id, p, t;

    Query() {}
    Query(int id, int p): id(id), p(p), t(p) {}

    bool operator<(const Query& other) const {
        return t != other.t ? t > other.t : id > other.id;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    priority_queue<Query> pq;
    string s;
    int n;
    while(getline(cin, s) && s != "#") {
        int id, p;
        sscanf(s.c_str(), "Register %d %d", &id, &p);
        pq.push(Query(id, p));
    }
    for(cin >> n; n--; ) {
        Query q = pq.top(); pq.pop();
        cout << q.id << "\n";
        q.t += q.p;
        pq.push(q);
    }
    return 0;
}
