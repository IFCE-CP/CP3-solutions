#include <bits/stdc++.h>

using namespace std;

string white = "PNBRQK", black = "pnbrqk", board[10];

// void showBoard() {

//     cout << "\nboard\n";
//     for(int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) { cout << board[i][j] << " "; }
//         cout << "\n";
//     }
// }

bool isIn(string a, char c) {
    
    bool res = false;
    int size = a.size();

    for (int i = 0; i < size && !res; i++) {
        if (c == a[i]) { res = true; }
    }
    return res;
}

bool isPiece(char c) {
    return isIn(black, c) || isIn(white, c);
}

bool testPos(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8 && (board[y][x] == '_' || board[y][x] == '*');
}

void attackCross(int l, int c) {

    int x[] = { 1, 0, -1,  0 };
    int y[] = { 0, 1,  0, -1 };

    for (int i = 0; i < 4; i++) {
        int xp = c + x[i];
        int yp = l + y[i];
        while (testPos(xp, yp)) {
            board[yp][xp] = '*';
            xp += x[i];
            yp += y[i];
        }
    }
}

void attackDiagonal(int l, int c) {

    int x[] = {  1, 1, -1, -1 };
    int y[] = { -1, 1,  1, -1 };

    for (int i = 0; i < 4; i++) {
        int xp = c + x[i];
        int yp = l + y[i];
        while (testPos(xp, yp)) {
            board[yp][xp] = '*';
            xp += x[i];
            yp += y[i];
        }
    }
}

void attack(char v, int l, int c) {

    if (!isPiece(v)) { return; }
    if (v == 'P' || v == 'p') {
        int f = v == 'P' ? -1 : 1;

        int x[] = { 1, -1 };
        int y[] = { f, f };

        for (int i = 0; i < 2; i++) {
            int xp = c + x[i];
            int yp = l + y[i];
            if (testPos(xp, yp)) { board[yp][xp] = '*'; }
        }
    } else if (v == 'N' || v == 'n') {
        int x[] = {  1,  2, 2, 1, -1, -2, -2, -1 };
        int y[] = { -2, -1, 1, 2,  2,  1, -1, -2 };

        for (int i = 0; i < 8; i++) {
            int xp = c + x[i];
            int yp = l + y[i];
            if (testPos(xp, yp)) { board[yp][xp] = '*'; }
        }
    } else if (v == 'B' || v == 'b') {
        attackDiagonal(l, c);
    } else if (v == 'Q' || v == 'q') {
        attackDiagonal(l, c);
        attackCross(l, c);
    } else if (v == 'R' || v == 'r') {
        attackCross(l, c);
    } else if (v == 'K' || v == 'k') {
        int x[] = { 1, 1, 0, -1, -1, -1,  0,  1 };
        int y[] = { 0, 1, 1,  1,  0, -1, -1, -1 };

        for (int i = 0; i < 8; i++) {
            int xp = x[i] + c;
            int yp = y[i] + l;

            if (testPos(xp, yp)) { board[yp][xp] = '*'; }
        }
    }
}

int main () {

    string line;

    while (getline(cin, line)) {
        int size = line.size(), l = 0, c = 0;
        for (int i = 0; i < size; ++i) {
            char v = line[i];
            if (isdigit(v)) {
                for(int j = c; j < c + (v - '0'); j++) { board[l][j] = '_'; }
                c += (v - '0');
            } else if (v == '/') { 
                l++;
                c = 0;
            } else if (isPiece(v)) { board[l][c++] = v; }
        }
        for(int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) { attack(board[i][j], i, j); }
        }
        int res = 0;
        for(int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == '_') { res++; }
            }
        }
        cout << res << "\n";
    }
    return 0;
}