#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Sheet {
    pii front, back;

    Sheet(): front({-1,-1}), back({-1,-1}) {}

    void printFront() {
        printf("front: ");
        if(front.first == -1) printf("Blank, ");
        else printf("%d, ", front.first);
        if(front.second == -1) printf("Blank\n");
        else printf("%d\n", front.second);
    }

    void printBack() {
        printf("back : ");
        if(back.first == -1) printf("Blank, ");
        else printf("%d, ", back.first);
        if(back.second == -1) printf("Blank\n");
        else printf("%d\n", back.second);
    }
};

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        int p = 1;
        vector<Sheet> l;
        while(p <= (n+1)/2) {
            Sheet s;
            s.front.second = p++;
            if(p <= n) s.back.first = p++;
            l.push_back(s);
        }
        for(int i = l.size()-1; i >= 0 && p <= n; --i) {
            l[i].back.second = p++;
            if(p <= n) l[i].front.first = p++;
        }

        printf("Printing order for %d pages:\n", n);
        for(unsigned i = 0; i < l.size(); ++i) {
            if(l[i].front != pii(-1,-1)) {
                printf("Sheet %d, ", i+1);
                l[i].printFront();
            }
            if(l[i].back != pii(-1,-1)) {
                printf("Sheet %d, ", i+1);
                l[i].printBack();
            }
        }

    }
    return 0;
}
