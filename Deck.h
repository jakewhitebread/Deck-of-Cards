#include <iostream>
#include <vector>
#include <random>
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck() {
		for (int value = 1; value <= 13; value++) {
			for (int suit = 1; suit <= 4; suit++) {
				deck.push_back(Card(value, suit));
			}
		}
		shuffle(begin(deck), end(deck), mt19937(random_device()()));
	}

	void print() {
		for (int i = 0; i < deck.size(); i++) {
			deck[i].print();
			cout << endl;
		}
	}

	vector<Card> deal(int cardsNum) {
		vector<Card> output;
		for (int i = 0; i < cardsNum; i++) {
			output.push_back(deck.back());
			deck.pop_back();
		}
		return output;
	}

	vector<Card> deck;
};
