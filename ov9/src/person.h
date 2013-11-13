#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person {
private:
	std::string firstname;
	std::string lastname;
public:
	Person(std::string fname, std::string lname);
	friend std::ostream& operator <<(std::ostream &out, Person &m);
	bool operator<(Person &p);
	std::string getFirst();
	std::string getLast();
	Person data();
	void listsWithPersons();
};
#endif
