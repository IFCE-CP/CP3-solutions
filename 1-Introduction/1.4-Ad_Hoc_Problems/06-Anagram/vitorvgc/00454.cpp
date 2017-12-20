#include <bits/stdc++.h>

using namespace std;

struct Word {
    string s, sorted;

    Word(string s) {
        this->s = s;
        string aux;
        for(auto c : s)
            if(isalpha(c))
                aux += c;
        sort(aux.begin(), aux.end());
        this->sorted = aux;
    }

    bool isAnagram(const Word other) {
        return this->sorted == other.sorted;
    }

    bool operator<(const Word other) const {
        return this->s < other.s;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int t;
    for(cin >> t, cin.ignore(), getline(cin, s); t--; ) {
        vector<Word> words;
        while(getline(cin, s) && s != "")
            words.push_back(Word(s));

        sort(words.begin(), words.end());
        for(unsigned i = 0; i < words.size(); ++i)
            for(unsigned j = i+1; j < words.size(); ++j)
                if(words[i].isAnagram(words[j]))
                    cout << words[i].s << " = " << words[j].s << '\n';

        if(t) cout << '\n';
    }
    return 0;
}
