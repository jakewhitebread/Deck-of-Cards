// jWhitebread_Deck of Cards.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://codereview.stackexchange.com/questions/124385/distributing-cards-to-players-in-c, https://www.geeksforgeeks.org/c-classes-and-objects/
//Jake Whitebread
//CST-210
//Deck of Cards

#include "pch.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <string>

using namespace std;

class Card {
private:
	int value;
	int suit;
public:
	Card(int v, int s) {
		value = v;
		suit = s;
	}

	int getValue()
	{
		return value;
	}
	string getValueString()
	{
		string values[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
		return values[value - 1];
	}
	int getSuit()
	{
		return suit;
	}

	void print() {
		string suitName(getSuitString());
		string  valueName(getValueString());
		cout << valueName << " of " << suitName;
	}

	string getSuitString()
	{
		string suits[] = { "Hearts", "Spades", "Diamonds", "Clubs" };
		return suits[suit - 1];
	}
};
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
class Game {
public:
	Game(Deck deck, vector<Player> players) {
		for (int i = 0; i < players.size(); i++) {
			players[i].hand = deck.deal(5);
			cout << players[i].name << "'s " << "Cards:" << endl;
			for (int j = 0; j < players[i].hand.size(); j++) {
				players[i].hand[j].print();
				cout << endl;
			}
			cout << endl;
		}
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
					highestPlayer = players[i];
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
int main()
{
	bool playAgain = true;
	string again;
	while (playAgain == true)
	{
		Deck deck = Deck();
		deck.print();
		cout << endl;
		vector<Player> players{ Player("Jake"), Player("Justin"), Player("Hai") };
		Game game = Game(deck, players);
		cout << "\nPlay again? 'Yes' or 'No' ";
		cin >> again;
		cout << endl;
		if (again != "Yes" && again != "yes" && again != "ye" && again != "y")
		{
			playAgain = false;
			cout << "\nThank you for playing!";
			return 0;
		}
	}
}
