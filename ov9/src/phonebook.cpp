#include <set>
#include <map>
#include <string>
#include <iostream>


using namespace std;

class PhonebookEntry {
private:
	std::string name;
	std::map<std::string,int> number;
public:
	PhonebookEntry() {};
	PhonebookEntry(std::string name, std::string type, int number);
	std::map<std::string, int>& getNumber() {return number;};
	void addNumber(std::string type, int number);
	void removeNumber(std::string remove);
	void setName(std::string name) {this->name = name;};
	std::string getName() {return name;};
	void print();
	friend bool operator < (const PhonebookEntry &pe1, const PhonebookEntry& pe2);
};

class Phonebook {
private:
	set<PhonebookEntry> persons;
public:
	Phonebook();
	void add(PhonebookEntry &pe);
	void print();
	bool find(std::string name, std::string type, PhonebookEntry& result);
};


// Exercise 4
PhonebookEntry::PhonebookEntry(string name, string type, int number) {
	this->name = name;
	this->number[type] = number;
}

void PhonebookEntry::addNumber(string type, int number) {
	this->number[type] = number;
}

void PhonebookEntry::removeNumber(string remove) {
	number.erase(remove);
}

void PhonebookEntry::print() {
	cout << name << endl;
	map<string, int>::iterator it;
	for(it = number.begin(); it != number.end(); ++it) {
		cout << "\t" << it->first << ": " << it->second << endl;
	}
	cout << endl;
}

bool operator <(const PhonebookEntry& pe1, const PhonebookEntry& pe2) {
	return (pe1.name < pe2.name);
}

// Exercise 4 & 5

void Phonebook::add(PhonebookEntry& pe) {
	set<PhonebookEntry>::iterator it = persons.find(pe);
	if(it != persons.end()) {
		map<string,int>::iterator it2;
		for(it2 = pe.getNumber().begin(); it2 != pe.getNumber().end(); ++it2) {
			it->addNumber(it2->first,it2->second);
		}
	} else {
		persons.insert(pe);
	}
}

void Phonebook::print() {
	set<PhonebookEntry>::iterator it;
	for(it = persons.begin(); it != persons.end(); ++it) {
		it->print();
	}
}

bool Phonebook::find(string name, string type, PhonebookEntry &result) {
	set<PhonebookEntry>::iterator it;
	for(it = persons.begin(); it != persons.end(); ++it) {
		it->getName().
	}

	return false;
}

