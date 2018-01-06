#include <bits/stdc++.h>

using namespace std;

struct Team {
    
    int id, problems, time;
    int tries[10];

    Team() {}
    Team(int n): id(n), problems(0), time(0) {
        memset(tries, 0, sizeof tries);
    }

    bool operator<(const Team& other) const {
        if(problems != other.problems)
            return problems > other.problems;
        if(time != other.time)
            return time < other.time;
        return id < other.id;
    }

    void print() {
        printf("%d %d %d\n", id, problems, time);
    }
};

Team teams[110];
set<int> participating;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    string s;
    for(cin >> tests, cin.ignore(), getline(cin, s); tests--; ) {
        int i, p, t;
        char result;

        participating.clear();
        for(int i = 0; i <= 100; ++i)
            teams[i] = Team(i);
        
        while(getline(cin, s) && s.length() > 2) {

            sscanf(s.c_str(), "%d %d %d %c", &i, &p, &t, &result);

            participating.insert(i);

            if((result != 'C' && result != 'I') || teams[i].tries[p] == -1) continue;

            if(result == 'C') {
                teams[i].problems++;
                teams[i].time += t + 20 * teams[i].tries[p];
                teams[i].tries[p] = -1;
            }
            else
                teams[i].tries[p]++;
        }

        vector<Team> v;
        for(auto it = participating.begin(); it != participating.end(); ++it)
            v.push_back(teams[*it]);

        sort(v.begin(), v.end());

        for(auto team : v) team.print();

        if(tests) printf("\n");
    }
    return 0;
}
