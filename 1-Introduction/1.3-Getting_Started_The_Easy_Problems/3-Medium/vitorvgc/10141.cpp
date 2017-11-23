#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, caso = 0;
    while(cin >> n >> p && n|p) {
        string s, ans;
        int ansQuant = -1;
        double ansValue = INT_MAX;
        for(int i = 0; i < n; ++i) {
            cin.ignore();
            getline(cin, s);
        }
        while(p--) {
            string name;
            double value;
            int quant;
            getline(cin, name);
            scanf("%lf %d\n", &value, &quant);
            for(int i = 0; i < quant; ++i)
                getline(cin, s);
            if(quant > ansQuant || (quant == ansQuant && value < ansValue)) {
                ans = name;
                ansQuant = quant;
                ansValue = value;
            }
        }
        if(caso > 0)
            cout << "\n";
        cout << "RFP #" << ++caso << "\n" << ans << "\n";
    }
    return 0;
}
