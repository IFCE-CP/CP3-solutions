#include <bits/stdc++.h>

using namespace std;

int main () {
	
    int n, count = 0;
    while (cin >> n && n) {
        int last = 0, first = 0;

        printf("Case %d:\n", ++count);

		for (int i = 0, k; i <= n; i++) {
            string line;
            if (i < n) { cin >> line; }
            else { line = "0"; }
            sscanf(line.c_str(), "%d", &k);

            if (!i) { first = last = k; }
            else {
                if (k - last == 1) { last = k; }
                else {
                    string sFirst = to_string(first);
                    cout << "0" + sFirst;
                    if (first != last) {
                        string sLast = to_string(last);
                        for (int j = 0; j < sLast.size(); j++) {
                            if (sFirst[j] != sLast[j]) {
                                cout << "-" << sLast.substr(j, sLast.size() - j);
                                break;
                            }
                        }
                    }
                    cout << endl;
                    first = k;
                    last = k;
                }
            }
        }  
        cout << endl;      
    }
    return 0;
}