#include <bits/stdc++.h>

#define MAX 150

using namespace std;

bool guessed[MAX], contains[MAX];

int main() {
    int round;
    string s, guess;
    while(cin >> round && round != -1) {
        cin >> s >> guess;

        int errors = 0, quant = 0;
        memset(guessed, 0, sizeof guessed);
        memset(contains, 0, sizeof contains);
        for(auto c : s)
            if(!contains[c])
                contains[c] = true, ++quant;
        for(auto c : guess) {
            if(guessed[c]) continue;
            if(contains[c]) --quant;
            else ++errors;
            if(errors >= 7 || quant <= 0) break;
            guessed[c] = true; 
        }

        printf("Round %d\n", round);
        if(quant <= 0) printf("You win.\n");
        else if(errors >= 7) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}
