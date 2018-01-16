#include <bits/stdc++.h>

using namespace std;

bool cmp(const string& a, const string& b) {
    return a < b;
}

string removeSpaces(string line) {

    string lineTrim;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') { 
            lineTrim.insert(lineTrim.end(), line[i]);
        }
    }
    return lineTrim;
}

bool isAnagram(string a, string b) {

    string A = a, B = b;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    return A == B;
}

int main () {

    int n, k;
    cin >> n;
    k = n - 1;
    getchar();
    getchar();

    while (n--) {
        if (n < k) { printf("\n"); }

        string line;
        vector<string> list;

        while (getline(cin, line) && line != "") {
            list.push_back(line);
        }
        sort(list.begin(), list.end(), cmp);

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                string li = removeSpaces(list[i]);
                string lj = removeSpaces(list[j]);
                string lilj = list[i] + " = " + list[j];
                if (isAnagram(li, lj)) {
                    cout << lilj << endl;
                }
            }
        }
    }
    return 0;
}