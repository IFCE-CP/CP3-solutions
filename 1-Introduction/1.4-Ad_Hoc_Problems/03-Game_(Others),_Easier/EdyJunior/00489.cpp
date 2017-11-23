#include <bits/stdc++.h>

using namespace std;

int main() {

	int r;
	while (cin >> r && r != -1) {
		getchar();

		string word, guess;
		getline(cin, word);
		getline(cin, guess);

		int count = 0, wordSize = word.size(), lost = 0;
		bool match[wordSize], found = false;
		set <char> s;

		for (int i = 0; i < wordSize; ++i) { match[i] = false; }

		for (int i = 0; i < guess.size(); ++i) {
			char c = guess[i];
			if (s.find(c) != s.end()) { continue; }

			found = false;

			for (int j = 0; j < wordSize; j++) {
				if (c == word[j] && !match[j]) { 
					count++; 
					found = match[j] = true;
				}
			}
			s.insert(c);
			if (!found) { lost++; }
			if (lost >= 7 || wordSize == count) { break; }
		}
		cout << "Round " << r << "\n";
		if (lost >= 7) { cout << "You lose.\n"; }
		else if (wordSize == count) { cout << "You win.\n"; }
		else { cout << "You chickened out.\n"; }
	}
	return 0;
}