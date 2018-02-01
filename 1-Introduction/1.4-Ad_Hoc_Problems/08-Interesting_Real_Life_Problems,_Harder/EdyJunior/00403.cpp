#include <bits/stdc++.h>

using namespace std;

string alpha[] = { { ".***..****...****.****..*****.*****..****.*...*.*****...***.*...*.*.....*...*.*...*..***..****...***..****...****.*****.*...*.*...*.*...*.*...*.*...*.*****......." },
                   { "*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*......*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*.*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*........" },
                   { "*****.****..*.....*...*.***...***...*..**.*****...*......*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****...***....*...*...*..*.*..*.*.*...*.....*.....*........." },
                   { "*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*......*...*...*...*..*.*..**.**..*.*....*....*.........." },
                   { "*...*.****...****.****..*****.*......***..*...*.*****..**...*...*.*****.*...*.*...*..***..*......****.*...*.****...***...***....*...*...*.*...*...*...*****......." }
                };

void drawC1In(string grid[], char letter, int x, int y) {

    if (letter != '.' && x > 0 && x < 61 && y > 0 && y < 61) {
        grid[x][y] = letter;
    }
}

void drawC1In(string grid[], string text, int x, int y) {

    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        drawC1In(grid, c != ' ' ? c : '.' , x, y + i);
    }
}

void drawC5In(string grid[], char letter, int x, int y) {

    int posInAlpha;
    if (letter != ' ') { posInAlpha = (letter - 'A') * 6; }
    else { posInAlpha = 26 * 6; }

    for (int i = x; i < x + 5; i++) {
        for (int j = y; j < y + 6; j++) {
            char a = alpha[i - x][j - y + posInAlpha];
            drawC1In(grid, a, i, j);
        }
    }
}

void drawC5In(string grid[], string text, int x, int y) {

    for (int i = 0, j = 0; i < text.size(); i++, j += 6) {
        char c = text[i];
        drawC5In(grid, c, x, y + j);
    }
}

int main () {
	
    bool flag = true;

    while (flag) {
        string line = "";
        string grid[65];

        for (int i = 1; i <= 60; i++) {
            for (int j = 1; j <= 61; j++) { grid[i] += '.'; }
        }

        while (getline(cin, line) && line != ".EOP") {
            char font[5], aux[5];
            int x, y, size;
            string cmd = line.substr(0, 2), fontS, textS;

            if (cmd == ".P") {
                sscanf(line.c_str(), "%s %s %d %d", aux, font, &x, &y);
            } else {
                sscanf(line.c_str(), "%s %s %d", aux, font, &x);
            }
            int pos = 0;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '|') {
                    pos = i;
                    break;
                }
            }
            fontS = string(font), textS = line.substr(pos + 1, line.size() - pos - 2);
            if (cmd != ".P") {
                size = textS.size() * (fontS == "C1" ? 1 : 6);

                if (cmd == ".C") { y = 31 - size / 2; }
                else if (cmd == ".L") { y = 1; }
                else { y = 61 - size; }
            }
            if (fontS == "C5") { drawC5In(grid, textS, x, y); }
            else { drawC1In(grid, textS, x, y); }
        }
        if (line != ".EOP") { flag = false; }
        else {
            for (int i = 1; i <= 60; i++) {
                cout << grid[i].substr(1, 61) << endl;
            }
            cout << "\n";
            for (int i = 0; i < 60; i++) { cout << "-"; }
            cout << "\n\n";
        }
    }	
    return 0;
}