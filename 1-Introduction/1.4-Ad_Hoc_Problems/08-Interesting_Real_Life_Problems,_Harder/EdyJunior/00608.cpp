#include <bits/stdc++.h>

using namespace std;

#define UP 2
#define DOWN 1
#define EVEN 0

string values[3][3];

bool checkIt(char c, int disagree, int expectedMove) {

    int count = EVEN, move = EVEN;

    for (int i = 0; i < 3; i++) {
        string d = values[i][2];
        for (int j = 0; j < 2; j++) {
            string s = values[i][j];
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == c) {
                    if (d == "even") { 
                        return false; 
                    }
                    count++;
                    if (!move) {
                        if ((d == "down" && j == 0) ||
                            (d == "up" && j == 1)) { move = UP; }
                        else { move = DOWN; }
                    }
                    else {
                        int currentMove = EVEN;
                        if ((d == "down" && j == 0) ||
                            (d == "up" && j == 1)) { currentMove = UP; }
                        else { currentMove = DOWN; }
                        if (move != currentMove) { 
                            return false; 
                        }
                    }
                }
            }
        }
    }
    return count == disagree && move == expectedMove;
}

int main () {

    int n;
    cin >> n;
    getchar();

    while(n--) {
        int disagree = 0;
        
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                cin >> values[i][j];
                if (j == 2 && values[i][j] != "even") { disagree++; }
            }
        }
        for (char c = 'A'; c <= 'L'; c++) {
            if (checkIt(c, disagree, DOWN)) {
                printf("%c is the counterfeit coin and it is heavy.\n", c);
            } else if (checkIt(c, disagree, UP)) {
                printf("%c is the counterfeit coin and it is light.\n", c);
            }
        }
    }
    return 0;
}