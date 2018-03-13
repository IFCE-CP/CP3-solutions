#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

struct Contest {
    
    int number, correct, penalty;
    pair<int, int> problems[10];
    bool submitted;

    Contest () {
        
        number = correct = penalty = 0;
        submitted = false;
        for (int i = 0; i < 10; i++) {
            problems[i].F = 0;
            problems[i].S = -1;
        }
    }

    bool operator< (const Contest other) const {

        if (this->correct > other.correct) { return true ; }
        if (this->correct < other.correct) { return false; }
        if (this->penalty < other.penalty) { return true ; }
        if (this->penalty > other.penalty) { return false; }
        return this->number < other.number;
    }
};

int main () {

    int n, k;
    scanf("%d", &n);
    k = n;
    getchar();
    getchar();
    
    for (; n > 0; n--) {

        if (k != n) { printf("\n"); }
        Contest contest[101];
        for (int i = 0; i < 101; i++)
            contest[i].number = i;
        
        string line;
        while (getline(cin, line) && line != "") {
            int c, p, t;
            char L;
            sscanf(line.c_str(), "%d %d %d %c\n", &c, &p, &t, &L);
            if (L != 'R') { contest[c].submitted = true; }
            
            if (L == 'C') {
                if (contest[c].problems[p].S == -1) {
                    contest[c].penalty += (contest[c].problems[p].F + t);
                    contest[c].problems[p].S = t;
                    contest[c].correct++;
                }
            } else if (L == 'I') {
                if (contest[c].problems[p].S == -1)
                    contest[c].problems[p].F += 20;
            }
        }
        sort(contest, contest + 101);
        for (int i = 0; i < 101; i++) {
            Contest ci = contest[i];
            if (ci.submitted)
                printf("%d %d %d\n", ci.number, ci.correct, ci.penalty);
        }
    }
    return 0;
}