#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;
static string suits[4] = {"S","D","H","C"};

// Part 1a
enum Beatle { JOHN, PAUL, GEORGE, RINGO };

// Part 1b
bool isAlive(Beatle c) {
	switch(c) {
		case JOHN:
			return false;
		case PAUL:
			return true;
		case GEORGE:
			return false;
		case RINGO:
			return true;
		default:
			return false;
	}
}

// Part 2a
struct Musician {
	string name;
	int weight;
	int height;
	int beardLength;

	Musician(): name(""), weight(0),height(0), beardLength(0) {};
	Musician(string name, int weight, int height, int beardLength): name(name),
			weight(weight), height(height), beardLength(beardLength) {}
};

// Part 2b
struct Band {
	string name;
	bool rockBand;
	int releases;
	Musician musicians[4];
	Band() : name(""), rockBand(false), releases(0){};
	Band(string name, bool rockBand, int releases): name(name), rockBand(rockBand), releases(releases) {}
};

// Part 2c
int totalBeardLength(Band band) {
	if(!band.rockBand) {
		return -1;
	}
	int sum = 0;
	for(int i = 0; i < 4; i++) {
		sum += band.musicians[i].beardLength;
	}
	return sum;
}

// Part 3a
string nameFixer(string name) {
	string firstname = "";
	string lastname = "";
	unsigned int space = 0;
	for(unsigned int i = 0; i < name.length(); i++) {
		if (name[i] == ' ') {
			space = i+1;
			break;
		}
		firstname += name[i];
	}
	for(space; space < name.length(); space++) {
		lastname += name[space];
	}
	return lastname + ", " + firstname;
}

// Part 4
class Card {
private:
	int value;
	string suit;

	string intToString(int num) {
		stringstream ss;
		ss << num;
		return ss.str();
	}

public:
	int getValue() {
		return this->value;
	}
	string getSuit() {
		return this->suit;
	}
	void setValue(int value) {
		if(value > 0 && value < 14) {
			this->value = value;
		}
	}
	void setSuit(string suit) {
		if(suit.compare("H") == 0 || suit.compare("S") == 0 || suit.compare("C") == 0 || suit.compare("D") == 0) {
			this->suit = suit;
		}
	}
	string getFace() {
		return (this->suit + this->intToString(this->value));
	}
	Card(): value(0) {};
	Card(string suit, int value) : value(value), suit(suit) {};
};

class CardDeck {
private:
	Card cards[52];
	int numberDealt;
public:
	void buildDeck() {
		//suits = {"S","D","H","C"};
		numberDealt = 0;
		int size = 0;
		Card card;
		for(int i = 0; i < 4; i++) {
			for(int j = 1; j < 14; j++) {
				card.setSuit(suits[i]);
				card.setValue(j);

				cards[size] = card;
				size++;
			}
		}
	}
	void shuffle() {
		numberDealt = 0;
		srand(time(0) + rand() % 49); // Seed of random function
		for(int i = 0; i < (52-1); i++) {
			int r = i + (rand() % (52-i));
			Card temp = cards[i];
			cards[i] = cards[r];
			cards[r] = temp;
		}
	}
	void dealHand(int num, Card array[]) {
		if (num + this->numberDealt > 52) {
			cout << "There isn't enough card for that amount" << endl;
			return;
		}
		for(int i = 0; i < num; i++) {
			array[i] = this->cards[numberDealt + i];
		}
		numberDealt += num;
	}

	void printDeck() {
		for(int i = 0; i < 52; i++) {
			cout << cards[i].getFace();
		}
	}

	CardDeck() : numberDealt(0){
		buildDeck();
	};
	CardDeck(bool shouldShuffle) : numberDealt(0) {
		buildDeck();
		if(shouldShuffle){
			shuffle();
		}
	};
};

int main() {

	// Test Part 1
	cout << isAlive(JOHN);
	cout << isAlive(PAUL);


	// Test Part 2
	cout << endl;
	Musician raymon("Raymond", 80, 180, 5);
	Musician hell("Helsi", 89, 172, 5);
	Musician bot("Botchoe", 85, 185, 10);
	Musician mick("Micky", 90, 190, 7);
	Band band;
	band.name = "Helsinki";
	band.rockBand = true;
	band.releases = 4;

	band.musicians[0] = raymon;
	band.musicians[1] = hell;
	band.musicians[2] = bot;
	band.musicians[3] = mick;

	cout << totalBeardLength(band) << endl;
	cout << endl;

	// Test Part 3
	cout << nameFixer("John-Olav Storvold") << endl;

	// Test Part 4
	Card H5("H",5);
	cout << H5.getFace() << endl;
	H5.setValue(14);
	H5.setSuit("E");
	cout << H5.getFace() << endl;

	// Test Part 5

	CardDeck deck;
	deck.printDeck();
	deck.shuffle();
	cout << endl;
	deck.printDeck();
	cout << endl;
	CardDeck anotherDeck(true);
	anotherDeck.printDeck();
	cout << endl;
	Card array[52];
	Card arrayTo[3];
	anotherDeck.dealHand(50,array);
	anotherDeck.dealHand(3,arrayTo);
	anotherDeck.dealHand(2,arrayTo);
	cout << array << endl << arrayTo << endl;

	for(int i = 0; i < 52; i++) {
		cout << array[i].getFace() << endl;
	}
	cout << "Seperate" << endl;
	for(int j = 0; j < 3; j++) {
		cout << arrayTo[j].getFace() << endl;
	}

}
