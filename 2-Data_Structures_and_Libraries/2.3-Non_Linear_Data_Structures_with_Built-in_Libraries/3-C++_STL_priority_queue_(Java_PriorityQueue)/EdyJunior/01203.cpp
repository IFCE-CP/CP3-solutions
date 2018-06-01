#include <bits/stdc++.h>

using namespace std;

struct triple {
	
	int qnum, per, tm;

	triple(int a, int b, int c) : qnum(a), per(b), tm(c) {}

	bool operator> (const triple& b) const {

		if (tm > b.tm)
			return true;
		if (tm < b.tm)
			return false;
		return qnum > b.qnum;
	}
};

int main() {
	
	string cmd;
	int k;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<triple, vector<triple>, greater<triple>> pq;
	while(cin >> cmd && cmd != "#") {
		int qnum, per;
		cin >> qnum >> per;
		cin.ignore();
		pq.push(triple(qnum, per, per));
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		triple ret = pq.top();
		pq.pop();
		printf("%d\n", ret.qnum);
		pq.push(triple(ret.qnum, ret.per, ret.per + ret.tm));
	}
	return 0;
}