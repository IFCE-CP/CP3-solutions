#include <bits/stdc++.h>

using namespace std;

struct Sig {

    int green, cycle;

    Sig (int red) {

        this->green = red - 5;
        this->cycle = red * 2;
    }

    bool isGreenAt (int T) {

        int t = T;
        t %= this->cycle;
        if (t && t <= this->green) { return true; }
        
        return false;
    }
};

string secondsToWatch (int T) {

    int t = T;
    int sec = t % 60;
    t -= sec;
    int min = t / 60;
    int hour = min / 60;
    if (min) { min = min % 60; }

    char watch[10];
    sprintf(watch, "%0.2d:%0.2d:%0.2d", hour, min, sec);
    string str(watch);

    return str;
}

int main () {

    bool flag = true;

    while (flag) {
        int a, b, c;
        vector<Sig> signals;

        cin >> a >> b >> c;
        if (a + b + c) {
            Sig A = Sig(a);
            Sig B = Sig(b);
            Sig C = Sig(c);
            signals.push_back(A);
            signals.push_back(B);
            
            if (c) {
                signals.push_back(C);
                while (cin >> a) {
                    if (!a) { break; }
                    A = Sig(a);
                    signals.push_back(A);
                }
            }
            bool thereWasNotGreen = false, found = false;
            for (int i = 1; i <= 18001 && !found; i++) {
                bool allGreen = true;
                for (int j = 0; j < signals.size(); j++) {
                    Sig s = signals[j];
                    allGreen = s.isGreenAt(i);
                    if (!allGreen) {
                        thereWasNotGreen = true;
                        break;
                    }
                }
                if (allGreen && thereWasNotGreen) {
                    cout << secondsToWatch(i - 1) << endl;
                    found = true;                
                }
            }
            if (!found) { cout << "Signals fail to synchronise in 5 hours\n"; }
        } else { flag = false; }
    }
    return 0;
}