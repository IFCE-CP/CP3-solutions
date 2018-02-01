#include <bits/stdc++.h>

using namespace std;

string values[3], allAborh[] = { "O-", "O+", "B-", "B+", "A-", "A+", "AB-", "AB+" };

vector<string> getAllelesFrom(string abo) {

    vector<string> res;
    if (abo == "A") {
        res.push_back("A");
        res.push_back("O");
    } else if (abo == "B") {
        res.push_back("B");
        res.push_back("O");
    } else if (abo == "AB") {
        res.push_back("A");
        res.push_back("B");
    } else { res.push_back("O"); }

    return res;
}

struct Blood {

    string aborh;
    vector<string> alleles, factors;

    Blood (string);

    Blood (string, string, string, string);

    set<Blood> offspringWith(Blood);

    bool operator< (const Blood other) const {
        return this->aborh < other.aborh;
    }

    bool operator== (const Blood other) const {
        return this->aborh == other.aborh;
    }
};

Blood::Blood (string a, string b, string rh1, string rh2) {

    string aux = a;
    a = min(a, b);
    b = max(aux, b);

    if (b == "O" || a == b) { b = ""; }
    aborh = a + b;

    factors = { "-" };
    if (rh1 == "+" || rh2 == "+") { 
        aborh += "+";
        factors.push_back("+");
    } else { aborh += "-"; }

    alleles = getAllelesFrom(a + b);
}

Blood::Blood (string aborh) { 
        
    this->aborh = aborh;
    string abo = aborh.substr(0, aborh.size() - 1);
    string rh = aborh.substr(aborh.size() - 1, 1);

    factors = { "-" };
    if (rh == "+") { factors.push_back("+"); }

    alleles = getAllelesFrom(abo);
}

set<Blood> Blood::offspringWith(Blood other) {

    set<Blood> res;
    for (int i = 0; i < this->alleles.size(); i++) {
        for (int j = 0; j < other.alleles.size(); j++) {
            for (int k = 0; k < this->factors.size(); k++) {
                for (int l = 0; l < other.factors.size(); l++) {
                    string a = this->alleles[i];
                    string b = other.alleles[j];
                    string c = this->factors[k];
                    string d = other.factors[l];

                    Blood blood (a, b, c, d);
                    res.insert(blood);
                }
            }
        }
    }
    return res;
}

set<Blood> getChild (string pA, string pB) {

    Blood bA (pA), bB (pB);
    return bB.offspringWith(bA);
}

set<Blood> getParent (string pA, string cA) {

    set<Blood> res;
    Blood p (pA), c (cA);
    for (int i = 0; i < 8; i++) {
        Blood b (allAborh[i]);
        set<Blood> children = p.offspringWith(b);
        if (children.find(c) != children.end()) { res.insert(b); }
    }
    return res;
}

int main () {

    bool flag = true;
    string end[] = { "E", "N", "D" };
    int nCase = 1;

    while (flag) {
        int count = 0;
        for (int i = 0; i < 3; i++) {
            cin >> values[i];
            if (values[i] == end[i]) { count++; }
        }

        if (count == 3) { flag = false; }
        else {
            printf("Case %d: ", nCase++);
            string a = "", b = "";
            int unknown;
            for (int i = 0; i < 3; i++) {
                string v = values[i];

                if (v == "?") { unknown = i; }
                else {
                    if (a == "") { a = v; }
                    else { b = v; }
                }
            }
            
            set<Blood> s;
            if (unknown > 1) { s = getChild(a, b); }
            else { s = getParent(a, b); }

            for (int i = 0; i < 3; i++) {
                if (i) { cout << " "; }
                string v = values[i];

                if (v != "?") { cout << v; }
                else {
                    if (s.size() == 0) { cout << "IMPOSSIBLE"; }
                    else {
                        if (s.size() > 1) { cout << "{"; }
                        int j = 0;
                        set<Blood>::iterator it;
                        for (it = s.begin(); it != s.end(); it++) {
                            if (j) { cout << ", "; }
                            else { j = 1; }
                            cout << (*it).aborh;
                        }
                        if (s.size() > 1) { cout << "}"; }
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}