#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool comp(char a, char b) {

    char ac = a, bc = b;
    if ((islower(ac) && islower(bc)) ||
        (isupper(ac) && isupper(bc))) { return a < b; }

    if (islower(ac)) { 
        ac = toupper(ac);
        return ac < bc; 
    } else {
        bc = toupper(bc);
        return ac <= bc;
    }
}

int main () {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string w;
        cin >> w;

        sort(w.begin(), w.end(), comp);

        do {
            cout << w << "\n";
        } while (next_permutation(w.begin(), w.end(), comp));
    }
    return 0;
}