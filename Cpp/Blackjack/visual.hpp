#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Hand
{
private:
    vector<string> cur_hand;
public:
    int value;

    void printCurHand(bool dealer);
    void drawCard(vector<string> Stack, int * n);
    void update_value();
    int getValue() {
        return value;
    }
    int getHandSize() {
        return cur_hand.size();
    }
    Hand() {}
    Hand(vector<string>_cur_hand) {
        cur_hand = _cur_hand;

        vector<string>::iterator it;
        value = 0;
        int ace_flag = 0;
        for(it = _cur_hand.begin(); it != _cur_hand.end(); ++it) {
            string cur_card = *it;
            if(cur_card[0] == 'A') {
                value += 11;
                ace_flag++;
            }
            else if (cur_card[0] == 'K' || cur_card[0] == 'Q' ||cur_card[0] == 'J' || cur_card[0] == 'T') {
                value += 10;
            }
            else {
                value += (int) cur_card[0] - 48;
            }
        }
        while((ace_flag != 0) && value > 21) {
            ace_flag--;
            value -= 10;
        }
        if (value > 21) {
            cout << "Bust!" << endl;
        }
    }
    ~Hand() {}
};

void Hand::printCurHand(bool dealer) {
    vector<string>::iterator it;

    string top = "┌────────┐";
    string mid = "│        │";
    string bot = "└────────┘";

    string hidden = "│XXXXXXXX│";

    vector<string> spade = {  "│  ,'`.  │", 
                              "│ (_,._) │", 
                              "│   /\\   │"};
    vector<string> heart = {  "│  _  _  │",
                              "│ ( `' ) │",
                              "│  `.,'  │"};
    vector<string> diamond = {"│   /\\   │",
                              "│  <  >  │",
                              "│   \\/   │"};
    vector<string> club = {   "│  (_)   │",
                              "│ (_Y_)  │",
                              "│   │    │"};

    vector<string> mid_complete(7);
    vector<string>::iterator mit;
    for(mit = mid_complete.begin(); mit != mid_complete.end(); ++mit) {

        if(mit == mid_complete.begin() || mit == (mid_complete.end()-1)) { //writing numbered lines to mid_complete
            for(it = cur_hand.begin(); it != cur_hand.end(); ++it) {
                if((dealer) && (it == cur_hand.begin())) {
                    *mit += hidden;
                    continue;
                }
                

                string num_top = "│       │"; //2nd char num to be inserted 
                string num_bot = "│       │"; //10th char num to be inserted

                string cur_card = *it;


                num_top.insert(num_top.begin() + 3, cur_card[0]);
                num_bot.insert(num_bot.begin() + 10, cur_card[0]);
                if(mit == mid_complete.begin()) {
                    *mit += num_top;
                }
                else if (mit == (mid_complete.end()-1)) {
                    *mit += num_bot;
                }

            }
        }

        else if(mit == mid_complete.begin()+1 || mit == (mid_complete.end()-2)) {
            for (int i = 0; i != cur_hand.size(); i++) {
                if((dealer) && (i == 0)) {
                    *mit += hidden;
                    continue;
                }
                *mit += mid;
            }
        }

        else if(mit > mid_complete.begin()+1 || mit < mid_complete.end()-2) {
            
            string suit1;
            string suit2;
            string suit3;

            for(it = cur_hand.begin(); it != cur_hand.end(); ++it) {
                if((dealer) && (it == cur_hand.begin())) {
                    *mit += hidden;
                    continue;
                }
                string cur_card = *it;
                char suit = cur_card[1];
                if(suit == 'S'){
                    suit1 += spade[0];
                    suit2 += spade[1];
                    suit3 += spade[2];
                }
                if(suit == 'H'){
                    suit1 += heart[0];
                    suit2 += heart[1];
                    suit3 += heart[2];
                }
                if(suit == 'D'){
                    suit1 += diamond[0];
                    suit2 += diamond[1];
                    suit3 += diamond[2];
                }
                if(suit == 'C'){
                    suit1 += club[0];
                    suit2 += club[1];
                    suit3 += club[2];
                }
                
            }
            if (mit == mid_complete.begin()+2) *mit += suit1;
            if (mit == mid_complete.begin()+3) *mit += suit2;
            if (mit == mid_complete.begin()+4) *mit += suit3;
        }
    }

    for (int i = 0; i != cur_hand.size(); i++) { //prints all tops
        cout << top;
    }
    cout <<endl;

    for (mit = mid_complete.begin(); mit != mid_complete.end(); ++mit) { //prints midsection
        cout << *mit << endl;
    }

    for (int i = 0; i != cur_hand.size(); i++) { //prints all bots
        cout << bot;
    }
    cout <<endl;

    if(!dealer) {
        cout << "Value: " << value << endl;
        if(value>21) cout << "BUST!" << endl;
        else if (value == 21 && cur_hand.size() == 2) cout << "Blackjack!" << endl;
    }

};


void Hand::drawCard(vector<string> Stack, int * n) {
    int i = *n;
    string drawn = Stack[i];
    *n += 1;
    cur_hand.insert(cur_hand.begin(), drawn);
    update_value();
}

void Hand::update_value() {

    vector<string>::iterator it;
        value = 0;
        int ace_flag = 0;
        for(it = cur_hand.begin(); it != cur_hand.end(); ++it) {
            string cur_card = *it;
            if(cur_card[0] == 'A') {
                value += 11;
                ace_flag++;
            }
            else if (cur_card[0] == 'K' || cur_card[0] == 'Q' ||cur_card[0] == 'J' || cur_card[0] == 'T') {
                value += 10;
            }
            else {
                value += (int) cur_card[0] - 48;
            }
        }
        while((ace_flag != 0) && value > 21) {
            ace_flag--;
            value -= 10;
        }
}

