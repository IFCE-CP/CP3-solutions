#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    
    for(scanf("%d", &t); t > 0; t--) {
        int n, s, q, qi, c, cargoes = 0;
        list<pair<int, queue<int>>> plat;
        stack<int> carrier;
        int res = 0;
        
        scanf("%d %d %d", &n, &s, &q);
        for(int i = 0; i < n; i++) {
            queue<int> b;
            
            scanf("%d", &qi);
            cargoes += qi;
            
            for(int j = 0; j < qi; j++) {
                scanf("%d", &c);
                b.push(c);
            }
            plat.push_back(make_pair(i + 1, b));
        }
        
        while (cargoes) {
            list<pair<int, queue<int>>>::iterator it;
            for (it = plat.begin(); it != plat.end() && cargoes; ++it) {
                bool flag = true;
                while (flag) {
                    int cargo = 0;
                    if (!carrier.empty()) {
                        cargo = carrier.top();
                    } else flag = false;
                    
                    if(cargo == it->first) {
                        res++;
                        cargoes--;
                        carrier.pop();
                    } else {
                        if (it->second.size() < q && cargo) {
                            it->second.push(cargo);
                            carrier.pop();
                            res++;
                        } else flag = false;
                    }
                }
                while (carrier.size() < s && it->second.size() > 0) {
                    carrier.push(it->second.front());
                    res++;
                    it->second.pop();
                }
                if (cargoes) { res += 2; }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}