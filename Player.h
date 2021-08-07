#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <string>
#include <vector>
using namespace std;

class Player {
public:
	Player() {}
	Player(string name) {
		this->name = name;
	}
	vector<Card> hand;
	int score = 0;
	string name = "";
};