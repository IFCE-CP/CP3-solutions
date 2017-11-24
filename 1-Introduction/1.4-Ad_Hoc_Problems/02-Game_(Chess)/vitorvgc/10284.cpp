#include <bits/stdc++.h>

using namespace std;

char board[10][10], quant[10][10];

int dx[8] = {-1, 0,  0, 1, -1, -1,  1, 1};
int dy[8] = { 0, 1, -1, 0, -1,  1, -1, 1};

int nx[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
int ny[8] = {-2, -2, -1, -1,  1, 1,  2, 2};

void parse(string s) {
    
    memset(board, 0, sizeof board);
    memset(quant, 0, sizeof quant);

    int i = 1, j = 1;
    for(auto c : s) {
        if(c >= '1' && c <= '8')
            j += c - 48;
        else if(c == '/')
            ++i, j = 1;
        else {
            quant[i][j] = 1;
            board[i][j++] = c;
        }
    }
}

inline bool isInside(int x, int y) {
    return x > 0 && x <= 8 && y > 0 && y <= 8;
}

void getAttackedPositions(char c, int x, int y) {

    switch(c) {

        case 'p':
            ++quant[y+1][x-1], ++quant[y+1][x+1];
            break;
        case 'P':
            ++quant[y-1][x-1], ++quant[y-1][x+1];
            break;
        case 'k':
        case 'K':
            for(int i = 0; i < 8; ++i) {
                int x2 = x + dx[i];
                int y2 = y + dy[i];
                ++quant[y2][x2];
            }
            break;
        case 'q':
        case 'Q':
        case 'r':
        case 'R':
        case 'b':
        case 'B': {
            int start = tolower(c) == 'b' ? 4 : 0;
            int end   = tolower(c) == 'r' ? 4 : 8;
            for(int i = start; i < end; ++i)
                for(int x2 = x + dx[i], y2 = y + dy[i]; isInside(x2, y2) && !board[y2][x2]; x2 += dx[i], y2 += dy[i])
                    ++quant[y2][x2];
            break;
        }
        case 'n':
        case 'N':
            for(int i = 0; i < 8; ++i) {
                int x2 = x + nx[i];
                int y2 = y + ny[i];
                if(isInside(x2, y2))
                    ++quant[y2][x2];
            }
            break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(cin >> s) {

        parse(s);
        for(int i = 1; i <= 8; ++i)
            for(int j = 1; j <= 8; ++j)
                if(board[i][j])
                    getAttackedPositions(board[i][j], j, i);
        int ans = 0;
        for(int i = 1; i <= 8; ++i)
            for(int j = 1; j <= 8; ++j)
                ans += !quant[i][j];
        cout << ans << '\n';
    }
    return 0;
}

