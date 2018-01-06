#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string line;

    while (getline(cin, line) && line != "Game Over") {
        int  frame = 0;
        int  size = line.size();
        int  score = 0;
        int  pinsDown = 0;
        int  pendentStrike = 0;
        bool firstOfFrame = true;
        bool thereWasSpare = false;
        bool lastWasStrike = false;

        for (int i = 0; i < size; i += 2) {
            char point = line[i];

            if (frame > 9) { lastWasStrike = false; }

            if (isdigit(point) && firstOfFrame) {
                pinsDown = point - '0';
                firstOfFrame = false;

                if (thereWasSpare) { score += pinsDown; }
                thereWasSpare = false;

                if (lastWasStrike && pendentStrike == 3) {
                    score += (2 * pinsDown);
                    pendentStrike = 1;
                } else if (pendentStrike) {
                    score += pinsDown;
                    pendentStrike--;
                }
                lastWasStrike = false;
            } else if (isdigit(point) && !firstOfFrame) {
                pinsDown = point - '0';
                firstOfFrame = true;

                if (pendentStrike) { score += pinsDown; }
                pendentStrike = 0;
                lastWasStrike = false;

                frame++;
            } else if (point == '/') {
                pinsDown = 10 - pinsDown;
                firstOfFrame = true;

                if (pendentStrike) { score += pinsDown; }
                lastWasStrike = false;
                pendentStrike = 0;
                
                if (frame < 9) { thereWasSpare = true; }

                frame++;
            } else {
                pinsDown = 10;
                
                if (thereWasSpare) { score += pinsDown; }
                thereWasSpare = false;
        
                if (frame < 10) {
                    if (lastWasStrike && pendentStrike != 3) {
                        score += pinsDown;
                        pendentStrike = 3;
                    } else if (pendentStrike == 3) {
                        score += 2 * pinsDown;
                    } else if (pendentStrike == 1) {
                        score += pinsDown;
                        pendentStrike = 2;
                    } else { pendentStrike = 2; }

                    if (frame < 9) { lastWasStrike = true; }
                    else {
                        lastWasStrike = false;
                        pendentStrike = pendentStrike == 3 ? 1 : 0;
                    }
                    frame++;
                } else {
                    if (pendentStrike) {
                        pendentStrike = 0;
                        score += pinsDown;
                    }
                }
                firstOfFrame = true;
            }
            score += pinsDown;
        }
        printf("%d\n", score);
    }
    return 0;
}