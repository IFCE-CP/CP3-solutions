#include <bits/stdc++.h>

#define LEDS 7

using namespace std;

bool led[10][LEDS] = {
    { 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 1 },
    { 1, 1, 1, 1, 0, 0, 1 },
    { 0, 1, 1, 0, 0, 1, 1 },
    { 1, 0, 1, 1, 0, 1, 1 },
    { 1, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 0 ,0 ,0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 0, 1, 1 }
};

bool burned[LEDS];
string state[10];

bool solve(int digit, int i, int n) {

    if(i >= n)
        return true;

    for(int j = 0; j < LEDS; ++j) {
        if(state[i][j] == 'Y' && (!led[digit][j] || burned[j]))
            return false;
        else if(state[i][j] == 'N' && led[digit][j])
            burned[j] = true;
    }
    
    return solve(digit - 1, i + 1, n);
}

int main() {
    int n;
    while(cin >> n && n) {
        for(int i = 0; i < n; ++i)
            cin >> state[i];

        bool ans = false;
        for(int i = n-1; i < 10 && !ans; ++i) {
            memset(burned, 0, sizeof burned);
            ans |= solve(i, 0, n);
        }

        cout << (ans ? "" : "MIS") << "MATCH\n";
    }
    return 0;
}
