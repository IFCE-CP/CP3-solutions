#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define _unique(v) sort(all(v)); v.resize(unique(all(v)) - v.begin())

using namespace std;

vector<char> cols1[5];
vector<char> cols2[5];

string common[5];
int prod[6];

int main() {
    int t, k;

    for(scanf("%d", &t); t--; ) {
        scanf("%d", &k);

        for(int i = 0; i < 5; ++i) {
            cols1[i] = vector<char>(6);
            cols2[i] = vector<char>(6);
        }

        for(int i = 0; i < 6; ++i) {
            getchar();
            for(int j = 0; j < 5; ++j)
                scanf("%c", &cols1[j][i]);
        }
        for(int i = 0; i < 6; ++i) {
            getchar();
            for(int j = 0; j < 5; ++j)
                scanf("%c", &cols2[j][i]);
        }

        for(int i = 0; i < 5; ++i) {
            _unique(cols1[i]);
            _unique(cols2[i]);
        }

        for(auto &s : common) s = "";

        for(int i = 0; i < 5; ++i) {
            for(int p1 = 0, p2 = 0; p1 < cols1[i].size() && p2 < cols2[i].size(); ) {
                if(cols1[i][p1] == cols2[i][p2])
                    common[i] += cols1[i][p1], ++p1, ++p2;
                else if(cols1[i][p1] < cols2[i][p2])
                    ++p1;
                else
                    ++p2;
            }
        }
        
        prod[5] = 1;
        for(int i = 4; i >= 0; --i)
            prod[i] = prod[i+1] * common[i].length();

        if(k > prod[0]) {
            printf("NO\n");
            continue;
        }

        string ans;
        --k;
        for(int i = 0; i < 5; ++i) {
            ans += common[i][k / prod[i + 1]];
            k %= prod[i + 1];
        }
        cout << ans << "\n";
    }
    return 0;
}
