#include <bits/stdc++.h>

using namespace std;

struct Word {
    string s, sorted;

    Word(string s) {
        this->s = s;
        for(auto &c : s) c = tolower(c);
        sort(s.begin(), s.end());
        this->sorted = s;
    }

    bool isAnagram(const Word other) {
        return this->s.length() > 1 && this->sorted == other.sorted;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<Word> words;
    vector<string> ans;
    string s;
    while(cin >> s && s != "#")
        words.push_back(Word(s));

    for(auto w : words) {
        bool ananagram = true;
        for(auto w2 : words)
            if(w.s != w2.s)
                ananagram &= !(w.isAnagram(w2));
        if(ananagram) ans.push_back(w.s);
    }

    sort(ans.begin(), ans.end());
    for(auto s : ans) cout << s << '\n';
    return 0;
}
