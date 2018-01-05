#include <bits/stdc++.h>

using namespace std;

bool win(bool mark[5][5]) {

    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5 && flag; j++) 
            flag &= mark[i][j];

        if (flag) { return true; }
    }
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        for (int j = 0; j < 5 && flag; j++)
            flag &= mark[j][i];

        if (flag) { return true; }
    }
    bool flag = true;
    for (int i = 4, j = 0; j < 5 && flag; j++, i--)
        flag &= mark[i][j];

    if (flag) { return true; }

    flag = true;
	for (int i = 0, j = 0; j < 5 && flag; j++, i++)
        flag &= mark[i][j];

    if (flag) { return true; }

    return false;
}

int main() {

    int t;

    for (cin >> t; t > 0; t--) {
        int card[5][5], res = 0;
        bool mark[5][5], isOver = false;

		for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!(i == 2 && j == 2)) { 
                    cin >> card[i][j];
                    mark[i][j] = false;
                } else {
                    card[i][j] = 0;
                    mark[i][j] = true;
                }
            }
        }
        for (int h = 0, n; h < 75; h++) {
            cin >> n;

            for (int i = 0; i < 5 && !isOver; i++) {
                for (int j = 0; j < 5 && !isOver; j++) {
                    if (card[i][j] == n) { 
                        mark[i][j] = true;
                        isOver = win(mark);
                        res = h + 1;
                    }
                }
            }
        }
        printf("BINGO after %d numbers announced\n", res);
    }
    return 0;
}