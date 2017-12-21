#include <bits/stdc++.h>

#define TIME_OUT 18000

using namespace std;

struct TrafficLight {
    int cycle, t;
    char state; // g, o, r

    TrafficLight(int c): cycle(c), t(0), state('g') {}

    char increment() {

        switch(state) {
            case 'g':
                if(++t > cycle - 5) state = 'o', t = 1;
                break;
            case 'o':
                if(++t > 5) state = 'r', t = 1;
                break;
            case 'r':
                if(++t > cycle) state = 'g', t = 1;
                break;
        }

        return state;
    }
};

int main2() {

    TrafficLight t(10);

    for(int i = 0; i < 25; ++i) {
        char c = t.increment();
        printf("%d: %d %d %c\n", i, t.cycle, t.t, c);
    }
    return 0;
}

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) && a|b|c) {
        vector<TrafficLight> l = { TrafficLight(a), TrafficLight(b) };
        while(c) {
            l.push_back(TrafficLight(c));
            scanf("%d", &c);
        }

        int s = 1;
        for(; s <= TIME_OUT; ++s) {
            bool green = true;
            for(auto& x : l)
                green &= (x.increment() == 'g');
            if(!green) break;
        }
        
        for(; s <= TIME_OUT; ++s) {
            bool ok = true;
            for(auto& x : l)
                ok &= (x.increment() == 'g');
            if(ok) break;
        }

        if(s > TIME_OUT)
            printf("Signals fail to synchronise in 5 hours\n");
        else {
            int h = s / 3600;
            s -= h * 3600;
            int m = s / 60;
            s -= m * 60;
            printf("%02d:%02d:%02d\n", h, m, s);
        }
    }
    return 0;
}
