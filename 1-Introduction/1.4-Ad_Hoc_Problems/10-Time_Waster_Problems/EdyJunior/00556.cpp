#include <bits/stdc++.h>

using namespace std;

#define DOWN  0
#define LEFT  1
#define UP    2
#define RIGHT 3

int dy[] = { 1,  0, -1, 0 };
int dx[] = { 0, -1,  0, 1 };

struct Pos {

    int y, x;

    Pos (int a, int b) : y(a), x(b) {};

    bool operator== (const Pos& other) const {
        return this->y == other.y && this->x == other.x;
    }
};

struct Orientation {

    int dir;

    Orientation () : dir(1) {};
    Orientation (int value) : dir(value) {};

    Orientation operator+ (const Orientation& other) {

        Orientation res = *this;
        if (other.dir == LEFT) {
            res.dir--;
            if (res.dir < 0) { res.dir = RIGHT; }
        } else {
            res.dir++;
            if (res.dir > 3) { res.dir = DOWN; }
        }
        return res;
    }

    bool operator== (const Orientation& other) const {
        return this->dir == other.dir;
    }

    void operator= (const Orientation& other) {
        this->dir = other.dir;
    }
};

Orientation r = { RIGHT };
Orientation l = { LEFT };

Pos getNewPos(Pos cPos, Orientation ori) {
    return Pos(cPos.y + dy[ori.dir], cPos.x + dx[ori.dir]);
}

bool canMoveTo(Pos pos, vector<string> maze) {

    if (maze[pos.y][pos.x] == '1') { return false; }
    return true;
}

bool checkRightWall(Pos cPos, Orientation cOri, vector<string> maze) {

    Pos newPos = getNewPos(cPos, cOri + r);
    return !canMoveTo(newPos, maze);
}

void solve(vector<string> maze, int b, int w, int res[]) {

    Pos start = { b, 1 };
    Pos cPos = start;
    int matrix[b + 2][w + 2], count = 0;
    Orientation cOri(RIGHT);

    for (int i = 0; i < b + 2; ++i) {
        for (int j = 0; j < w + 2; ++j) {
            matrix[i][j] = maze[i][j] == '0' ? 0 : -1;
        }
    }
    bool flag = true;
    while (flag) {
        if (cPos == start) { 
            count++; 
        }
        if (count == 2) { flag = false; }
        else {
            Pos nextPos(0, 0);
            if (checkRightWall(cPos, cOri, maze)) {
                cOri = cOri + r;
                while (!canMoveTo(nextPos, maze)) {
                    cOri = cOri + l;
                    nextPos = getNewPos(cPos, cOri);
                }
            } else {
                cOri = cOri + r;
                nextPos = getNewPos(cPos, cOri);
            }
            matrix[cPos.y][cPos.x]++;
            cPos = nextPos;
        }
    }
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= w; j++) {
            if (maze[i][j] == '0') { res[matrix[i][j]]++; }
        }
    }
}

int main () {
	
    int b, w;

    while (cin >> b >> w && b + w) {
        vector<string> maze;
        int res[] = { 0, 0, 0, 0, 0 };
        for (int i = 0; i < b + 2; ++i) {
            if (i < 1 || i > b) {
                string s = "";
                for (int j = 0; j < w + 2; j++) {
                    s += "1";
                }
                maze.push_back(s);
            } else {
                string line;
                cin >> line;
                maze.push_back("1" + line + "1");
            }
        }
        solve(maze, b, w, res);
        for (int i = 0; i < 5; ++i) {
            printf("%3d", res[i]);
        }
        printf("\n");
    }
    return 0;
}