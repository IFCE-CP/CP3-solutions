#include <bits/stdc++.h>

using namespace std;

string cards[60];

int main() {
    
    int t;
    scanf("%d\n", &t);
    for(int caso = 1; caso <= t; ++caso) {

        for(int i = 0; i < 52; ++i)
            cin >> cards[i];

        int top = 26, y = 0;

        for(int i = 0; i < 3; ++i) {

            char c = cards[top][0];
            int x = (c >= '2' && c <= '9' ? c - 48 : 10);

            y += x;
            top -= 11 - x;
        }
        
        string card;
        if(y-1 <= top) card = cards[y-1]; 
        else card = cards[y-1-top+26];

        cout << "Case " << caso << ": " << card << "\n";
    }
    return 0;
}
