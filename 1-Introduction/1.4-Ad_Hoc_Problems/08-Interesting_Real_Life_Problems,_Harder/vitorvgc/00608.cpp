#include <bits/stdc++.h>

using namespace std;

string weights[3][3];
bool canBe[12];
int weight[12]; // -1 - unknown, 0 - light, 1 - heavy

int main() {
    int t;
    for(cin >> t; t--; ) {
        for(auto &x : canBe) x = 1;
        memset(weight, -1, sizeof weight);
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                cin >> weights[i][j];
        
        // discard surely silver coins
        for(auto w : weights)
            if(w[2] == "even") {
                string coins = w[0] + w[1];
                for(auto x : coins) canBe[x-'A'] = false;
            }

        // discard weight inconsistencies
        for(auto w : weights)
            if(w[2] != "even") {
                int value = (w[2] == "up" ? 1 : 0);
                for(auto x : w[0]) {
                    if(weight[x-'A'] == -1) weight[x-'A'] = value;
                    else if(weight[x-'A'] != value) canBe[x-'A'] = false;
                }
                value = !value;
                for(auto x : w[1]) {
                    if(weight[x-'A'] == -1) weight[x-'A'] = value;
                    else if(weight[x-'A'] != value) canBe[x-'A'] = false;
                }
            }

        // solve intersections
        int ans = (1 << 12) - 1;
        for(auto w : weights)
            if(w[2] != "even") {
                int k = 0;
                string coins = w[0] + w[1];
                for(auto x : coins)
                    if(canBe[x-'A']) k |= (1 << (x-'A'));
                ans &= k;
            }

        // find coin
        char coin = 0;
        for(int i = 0; i < 12; ++i)
            if(ans & (1 << i))
                coin = i + 'A';

        cout << coin << " is the counterfeit coin and it is " << (weight[coin-'A'] ? "heavy" : "light") << ".\n";
    }
    return 0;
}
