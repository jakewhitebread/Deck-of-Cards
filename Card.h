//#define Card
#include <iostream>
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
		/*if (value == 1) return "Ace";
		if (value == 2) return "two";
		if (value == 3) return "Three";
		if (value == 4) return "Four";
		if (value == 5) return "Five";
		if (value == 6) return "Six";
		if (value == 7) return "Seven";
		if (value == 8) return "Eight";
		if (value == 9) return "Nine";
		if (value == 10) return "Ten";
		if (value == 11) return "Jack";
		if (value == 12) return "Queen";
		if (value == 13) return "King";
		else return "Unknown value";*/
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
