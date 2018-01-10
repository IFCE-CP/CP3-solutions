#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b) {

    string A = a, B = b;
    int As = A.size();
    int Bs = B.size();

    if (As != Bs) { return false; }

    for (int i = 0; i < As; ++i) { A[i] = tolower(A[i]); }
    for (int i = 0; i < Bs; ++i) { B[i] = tolower(B[i]); }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < As; ++i) {
        if (A[i] != B[i]) { return false; }
    }
    return true;
}

int main () {
	
    vector<string> dict, res;
    string word;

    while (cin >> word && word != "#") {
        dict.push_back(word);
    }
    for (int i = 0; i < dict.size(); i++) {
        string w = dict[i];
        bool flag = true;
        for (int j = 0; j < dict.size() && flag; j++) {
            string v = dict[j];
            if (isAnagram(w, v) && i != j) { 
                flag = false;
            }
        }
        if (flag) { res.push_back(w); }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }
	return 0;
}