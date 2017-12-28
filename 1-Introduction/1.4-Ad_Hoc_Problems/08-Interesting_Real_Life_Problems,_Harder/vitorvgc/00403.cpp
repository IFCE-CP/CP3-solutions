#include <bits/stdc++.h>

#define MAX 60

using namespace std;
 
string courier[5] = {
    ".***..****...****.****..*****.*****..****.*...*.*****...***.*...*.*.....*...*.*...*..***..****...***..****...****.*****.*...*.*...*.*...*.*...*.*...*.*****.......",
    "*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*......*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*.*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*........",
    "*****.****..*.....*...*.***...***...*..**.*****...*......*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****...***....*...*...*..*.*..*.*.*...*.....*.....*.........",
    "*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*......*...*...*...*..*.*..**.**..*.*....*....*..........",
    "*...*.****...****.****..*****.*......***..*...*.*****..**...*...*.*****.*...*.*...*..***..*......****.*...*.****...***...***....*...*...*.*...*...*...*****......."
};

int m[66][66];

bool inside(int x, int y) {
    return x >= 0 && x < MAX && y >= 0 && y < MAX;
}

void format(string &s) {
    s = s.substr(2, s.length() - 3);
    for(auto &c : s)
        if(c == ' ') c = '.';
}

void placeC1char(char c, int &x, int y) {
    if(inside(x, y) && c != '.')
        m[y][x] = c;
    ++x;
}

void placeC5char(char c, int &x, int y) {

    int index = (isalpha(c) ? c - 'A' : 26);

    for(int i = 0; i < 5; ++i, ++y)
        for(int j = 6*index, k = 0; j < 6*(index + 1); ++j, ++k)
            if(inside(x+k, y) && courier[i][j] == '*')
                m[y][x+k] = courier[i][j];
    x += 6;
}

void place(string s, bool c1, int x, int y) {
    for(auto c : s)
        c1 ? placeC1char(c, x, y): placeC5char(c, x, y);
}

void printPage() {
    for(int i = 0; i < MAX; ++i) {
        for(int j = 0; j < MAX; ++j)
            printf("%c", m[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < MAX; ++i)
        printf("-");
    printf("\n\n");
}

void clearPage() {
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            m[i][j] = '.';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string command, s, font;
    int x, y;
    bool c1;
    clearPage();
    while(cin >> command) {
        if(command == ".P") {
            cin >> font >> y >> x;
            getline(cin, s);

            --x; --y;
            c1 = (font == "C1");
            format(s);

            place(s, c1, x, y);
        }
        else if(command == ".L") {
            cin >> font >> y;
            getline(cin, s);

            --x; --y;
            c1 = (font == "C1");
            format(s);

            place(s, c1, 0, y);
        }
        else if(command == ".R") {
            cin >> font >> y;
            getline(cin, s);

            --x; --y;
            c1 = (font == "C1");
            format(s);

            int left = MAX - s.length() * (c1 ? 1 : 6);
            
            place(s, c1, left, y);
        }
        else if(command == ".C") {
            cin >> font >> y;
            getline(cin, s);

            --x; --y;
            c1 = (font == "C1");
            format(s);

            int left = MAX/2 - (s.length() * (c1 ? 1 : 6)) / 2;
            
            place(s, c1, left, y);
        }
        else if(command == ".EOP") {
            printPage();
            clearPage();
        }
    }

    return 0;
}
