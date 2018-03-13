#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string line;
    while (getline(cin, line)) {
        list<char> front, back;
        bool inBack = true;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '[') { 
                inBack = false;
                back.insert(back.begin(), front.begin(), front.end());
                front.clear();
            } else if (line[i] == ']')
                inBack = true;
            else {
                if (inBack)
                    back.push_back(line[i]);
                else { front.push_back(line[i]); }
            }
        }
        list<char>::iterator it;
        for (it = front.begin(); it != front.end(); it++)
            printf("%c", *it);
        for (it = back.begin(); it != back.end(); it++)
            printf("%c", *it);
        printf("\n");
    }
    return 0;
}