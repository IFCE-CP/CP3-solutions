#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(getline(cin, s) && s != "Game Over") {
        int points = 0, round = 1, last = 0;
        bool rolled = false;
        list<int> extras;

        for(unsigned i = 0; i < s.length(); i += 2) {

            int p = s[i] == 'X' ? 10 : s[i] == '/' ? 10 - last : s[i] - 48;

            for(auto it = extras.begin(); it != extras.end(); ++it) {
                points += p;
                if(--(*it) == 0)
                    it = --extras.erase(it);
            }

            if(round <= 10) {
                points += p;
                if(s[i] == 'X') extras.push_back(2);
                else if(s[i] == '/') extras.push_back(1);
            }

            if(s[i] == 'X') {
                ++round;
                rolled = false;
            }
            else {
                if(!rolled) rolled = true;
                else ++round, rolled = false;
            }

            last = p;
        }
        
        printf("%d\n", points);
    }
    return 0;
}
