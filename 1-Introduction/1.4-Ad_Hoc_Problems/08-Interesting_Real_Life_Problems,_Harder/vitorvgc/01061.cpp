#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define _unique(v) sort(all(v)); (v).resize(unique(all(v)) - (v).begin())

using namespace std;

typedef vector<string> vs;

unordered_map<string, string> abo = {
    {"AA", "A"}, {"AB", "AB"}, {"AO", "A"},
    {"BB", "B"}, {"BO", "B"}, {"OO", "O"}
};

unordered_map<string, string> combination = {
    {"A", "AO"}, {"B", "BO"}, {"AB", "AB"}, {"O", "OO"}
};

vs aboUnion(string a, string b) {
    
    string ca = combination[a];
    string cb = combination[b];

    vs possibilities;
    for(auto c1 : ca)
        for(auto c2 : cb)
            possibilities.push_back(string() + c1 + c2);

    vs ans;
    for(auto &p : possibilities) {
        sort(all(p));
        ans.push_back(abo[p]);
    }

    _unique(ans);
    return ans;
}

vs rhUnion(string a, string b) {
    return a + b == "--" ? vs({"-"}) : vs({"-", "+"});
}

vs rhParent(string p, string c) {
    return p + c == "-+" ? vs({"+"}) : vs({"-", "+"});
}

vs aboPlusRh(vs abos, vs rhs) {

    vs ans;
    for(auto abo : abos)
        for(auto rh : rhs)
            ans.push_back(abo + rh);

    return ans;
}

vs getChild(string a, string b) {
    
    string rha = string(&a[a.length()-1]);
    string rhb = string(&b[b.length()-1]);

    a.pop_back();
    b.pop_back();

    vs abos = aboUnion(a, b);
    vs rhs = rhUnion(rha, rhb);

    return aboPlusRh(abos, rhs);
}

vs getParent(string p, string c) {
    
    string rhp = string(&p[p.length()-1]);
    string rhc = string(&c[c.length()-1]);

    p.pop_back();
    c.pop_back();

    vs abos = {};
    vs possibilities = {"A", "B", "AB", "O"};
    for(auto type : possibilities) {
        vs result = aboUnion(p, type);
        bool containsChild = false;
        for(auto r : result) containsChild |= (r == c);
        if(containsChild) abos.push_back(type);
    }
    
    vs rhs = rhParent(rhp, rhc);

    return aboPlusRh(abos, rhs);
}

void printVector(vs v) {
    
    if(v.empty()) {
        cout << "IMPOSSIBLE";
        return;
    }

    if(v.size() == 1) {
        cout << v[0];
        return;
    }

    cout << "{" << v[0];
    for(unsigned i = 1; i < v.size(); ++i)
        cout << ", " << v[i];
    cout << "}";
}

int main() {
    int t = 0;
    string a, b, c;
    while(cin >> a >> b >> c && a+b+c != "END") {

        vs ans = {};
        if(a == "?") ans = getParent(b, c);
        else if(b == "?") ans = getParent(a, c);
        else ans = getChild(a, b);

        vs types = {a, b, c};
        string spacing = "  \n";

        cout << "Case " << ++t << ": ";
        for(int i = 0; i < 3; ++i) {
            if(types[i] != "?") cout << types[i];
            else printVector(ans);
            cout << spacing[i];
        }
    }
    return 0;
}
