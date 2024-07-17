#include <algorithm>
#include <random>
#include "visual.hpp"

void printStack(vector<string> Stack);
void printRemStack(vector<string> Stack, int * n);
bool Game(vector<string> Stack);
void startRound(vector<string> Stack, int * n, Hand p, Hand d);
void drawingStage(vector<string> Stack, int * n, Hand p, Hand d);


int main() {

    vector<string> Values = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
    vector<string> Suits = {"S","H","D","C"};
    vector<string> Deck(52);
    vector<string>::iterator deck_it = Deck.begin();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j<13; j++) {
            *deck_it = Values[j]+Suits[i];
            ++deck_it;
        }
    }

    bool play = true;

    while(play) {

        int n;
        cout << "Enter Number of Decks in Stack (Standard Amount is 6 Decks): ";
        cin >> n;



        int count = 52 * n;
        vector<string> Stack(count);

        for(int j = 0; j <n; j++) {
            for(int i = 0; i < Deck.size(); i++) {
                Stack[i+(j * 52)] = Deck[i];
            }
        }


        random_device rd;
        mt19937 g(rd());
        shuffle(Stack.begin(), Stack.end(), g);
        ///printStack(Stack);



        vector<string>::iterator stack_it = Stack.begin();

        play = Game(Stack);
    }


    return 0;
}

void printStack(vector<string> Stack) {
    vector<string>::iterator it;
    int i = 0;
    for(it = Stack.begin(); it != Stack.end(); ++it) {
        cout << "Stack[" << i << "]: " << *it << endl;
        i++;
    }
}

void printRemStack(vector<string> Stack, int * n) {

    for(int i = *n; i < Stack.size(); i++) {
        cout << "Stack[" << i - (*n) << "]: " << Stack[i] << endl;
    }
}

bool Game(vector<string> Stack) {

    int insert_card = rand() % 20; //Playing to the end of a deck would lead to empty draws, so end before complete end of deck
    insert_card += 5;

    int num_draws = 0;
    int* drawsptr;
    drawsptr = &num_draws;
    int Wins = 0;
    int Losses = 0;
    int Draws = 0;
    int Blackjacks = 0;

    bool game_flag = true;
    while(game_flag) {
        //init dealer and personal hand:
        int threshold = Stack.size() - insert_card;
        cout << threshold << endl;
        vector<string> person;
        vector<string> dealer;
        Hand playerHand = Hand(person);
        Hand dealerHand = Hand (dealer);
        startRound(Stack, drawsptr, playerHand, dealerHand);
        
        if(num_draws > (threshold)) {
            break;
        }
        string in;
        cout << "next hand?";
        cin >> in;
        if(in == "Yes") {
            game_flag = true;
        }
        else return false;
        }
    string in;
    cout << "Out of Cards, Reshuffle? (Enter Yes to Continue, Any Other Entry To Quit)";
    cin >> in;
    if(in == "Yes") {
        return true;
    }
    else return false;
}

void startRound(vector<string> Stack, int * n, Hand p, Hand d) {
    p.drawCard(Stack, n);
    d.drawCard(Stack, n);
    p.drawCard(Stack, n);
    d.drawCard(Stack, n);

    cout << "Dealer: " << endl;
    d.printCurHand(true);

    cout << "Player: " << endl;
    p.printCurHand(false);

    while(p.value < 21) {
        cout << "Type 'D' or 'S' to Stay:";
        string input;
        cin >> input;
        if(input == "D") {
            cout << endl << endl << endl << endl << endl;
            p.drawCard(Stack, n);
            d.printCurHand(true);
            p.printCurHand(false);
        }
        else {
            break;
        }
    }

    if(d.value == 17) {
        cout << "Dealer(Intermittent): " << endl;
        d.printCurHand(false);
        d.drawCard(Stack, n);
        cout << "Dealer(Intermittent): " << endl;
        d.printCurHand(false);
    }
    while(d.value < 16) {
        cout << "Dealer(Intermittent): " << endl;
        d.printCurHand(false);
        d.drawCard(Stack, n);
        cout << "Dealer(Intermittent): " << endl;
        d.printCurHand(false);
    }

    cout << endl << endl << endl << endl << endl;
    cout << "Dealer: " << endl;
    d.printCurHand(false);
    cout << "Player: " << endl;
    p.printCurHand(false);

}
