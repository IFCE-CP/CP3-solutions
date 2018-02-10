#include <bits/stdc++.h>

using namespace std;

int main () {
	
    int n, k, v;
    for (cin >> n; n > 0; n--) {
        map<char, int> m;
        
        for (cin >> k; k > 0; k--) {
            char c;
            cin >> c >> v;
            m[c] = v; 
        }
        string line;
        int tot = 0;
        cin >> k;
        getchar();
        for (int j = 0; j < k; j++) {
            getline(cin, line);
            for (int i = 0; i < line.size(); i++) {
                if (m.find(line[i]) != m.end()) {
                    tot += m[line[i]];
                }
            }
        }
        printf("%d.%02d$\n", tot / 100, tot % 100);
    }
    return 0;
}