#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()

using namespace std;

map<char, int> suitsIndex = { {'S', 0}, {'H', 1}, {'D', 2}, {'C', 3} };
string suits = "SHDC";

string cardsOfSuit[4];

int main() {
    
    int points = 0, rules567 = 0, stopped = 0;
    string card;

    while(1) {

        for(int i = 0; i < 13; ++i) {

            if(!(cin >> card)) return 0;

            switch(card[0]) {
                case 'A': points += 4; break;
                case 'K': points += 3; break;
                case 'Q': points += 2; break;
                case 'J': points += 1; break;
            }

            cardsOfSuit[suitsIndex[card[1]]] += card[0];
        }

        for(auto cards : cardsOfSuit) {
            
            int n = cards.length();
            
            // rule 2
            int king = count(all(cards), 'K');
            if(king && n - king == 0)
                points -= king;

            // rule 3
            int queen = count(all(cards), 'Q');
            if(queen && n - queen <= 1)
                points -= queen;

            // rule 4
            int jack = count(all(cards), 'J');
            if(jack && n - jack <= 2)
                points -= jack;

            // rule 5
            if(n == 2) ++points, ++rules567;

            // rule 6 & 7
            else if(n <= 1) points += 2, rules567 += 2;

            // count stopped
            int ace = count(all(cards), 'A');
            
            stopped += ace || (king && n - king >= 1) || (queen && n - queen >= 2);
        }

        if(points - rules567 >= 16 && stopped == 4)
            printf("BID NO-TRUMP\n");
        else if(points >= 14) {

            int quant = -1;
            char suit = '?';
            for(int i = 0; i < 4; ++i)
                if((int)cardsOfSuit[i].length() > quant)
                    quant = cardsOfSuit[i].length(), suit = suits[i];

            printf("BID %c\n", suit);
        }
        else
            printf("PASS\n");

        points = rules567 = stopped = 0;
        for(auto& cards : cardsOfSuit) cards = "";
    }

    return 0;
}
