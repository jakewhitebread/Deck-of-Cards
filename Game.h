#include <iostream>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include <vector>

using namespace std;

class Game {
public:
	Game(Deck deck, vector<Player> players) {
		for (int i = 0; i < players.size(); i++) {
			players[i].hand = deck.deal(5);
		}
		cout << "test" << endl;
		Player highestPlayer;
		int highestValue = 0;
		bool tie = false;
		for (int i = 0; i < players.size(); i++) {
			for (int j = 0; j < players[i].hand.size(); j++) {
				if (players[i].hand[j].getValue() == highestValue && highestPlayer.name != players[i].name) {
					tie = true;
				}
				if (players[i].hand[j].getValue() > highestValue) {
					highestValue = players[i].hand[j].getValue();
					tie = false;
				}
			}
		}
		if (tie) {
			cout << "Issa tie";
		}
		else {
			cout << highestPlayer.name << " gotted the dub";
		}
	}
};