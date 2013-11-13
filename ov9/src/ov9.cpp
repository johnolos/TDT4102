#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <vector>
#include "Person.h"
#include <list>
#include <map>

using namespace std;

// Exercise 1a
template <class T> T shuffle(T a[], unsigned int size) {
	srand(time(0) + rand() % 49);
	for(unsigned int i = 0; i < size; ++i) {
		int num1 = rand() % size;
		int num2 = rand() % size;
		T temp1 = a[num1];
		T temp2 = a[num2];
		a[num2] = temp1;
		a[num1] = temp2;
	}
}
// Exerise 1b
template <class T> T maximum(T a, T b) {
	return (a > b) ? a : b;
}

/*Exercise 1c
 * Template-funksjonen maximum vil ikke fungere
 * på typer som ikke kan sammenlignes. Det betyr
 * at dersom jeg lager mine egne klasser, så må
 * jeg sørge for at de klassene implementerer
 * en form for komparator som sørger for at
 * objektene er sammenlignbare.
 */

// Exercise 2c
void replace(vector<string> v, string old, string replacement) {
	for(std::vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		if(old == *it) {
			v.erase(it);
			v.insert(it, replacement);
		}
	}
}

// Exercise 3
Person::Person(string fname, string lname) {
	this->firstname = fname;
	this->lastname = lname;
}

string Person::getFirst() {
	return this->firstname;
}

string Person::getLast() {
	return this->lastname;
}

ostream& operator <<(ostream &out, Person &m) {
	out << m.lastname << ", " << m.firstname << endl;
	return out;
}

bool Person::operator<(Person &p) {
	if(lastname == p.lastname) {
		return firstname < p.firstname;
	}
	return lastname < p.lastname;

}

Person Person::data(){
	return *this;
}

void insertOrdered(list<Person> &l, Person p) {
	list<Person>::iterator it;
	for(it = l.begin(); it != l.end(); ++it) {
		if(p < *it) {
			l.insert(it, p);
			return;
		}
	}
	l.push_back(p);
}

void listsWithPersons() {
	Person john("John","Storvold");
	Person ole("Ole","Saeboe");
	Person hanso("Hans-Olav","Hessen");
	Person sindre("Sindre","Magnussen");
	Person hanne("Hanne","Olsen");

	list<Person> persons;
	insertOrdered(persons,john);
	insertOrdered(persons,ole);
	insertOrdered(persons,hanso);
	insertOrdered(persons,sindre);
	insertOrdered(persons,hanne);

	list<Person>::iterator it;
	for(it = persons.begin(); it != persons.end(); ++it) {
		cout << *it << endl;
	}

}




int main() {
	int a[] = {1,2,3,4,5,6,7};
	shuffle(a,7);
	for(int i = 0; i < 7; ++i) {
		cout << a[i];
	}
	cout << endl;
	int num1 = 1;
	int num2 = 2;
	int num3 = maximum(num1, num2);
	cout << num3;

	cout << endl;
	double d = 2.4;
	double e = 3.2;
	double f = maximum(d,e);
	cout << f;

	// Exercise 2
	vector<string> strings;
	string strs[] = {"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur","Lorem"};
	for(unsigned i = 0; i < 7; ++i) {
		strings.push_back(strs[i]);
	}

	//Exercise 2a
	cout << endl;
	for(std::vector<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
		cout << it->data() << endl;
	}
	// Exercise 2b
	cout << endl;
	for(std::vector<string>::reverse_iterator it = strings.rbegin(); it != strings.rend(); ++it) {
		cout << it->data() << endl;
	}
	// Exercise 2c
	cout << endl;
	replace(strings,"Lorem","Latin");
	for(std::vector<string>::iterator it = strings.begin(); it != strings.end(); ++it) {
		cout << it->data() << endl;
	}

	// Exercise 3
	listsWithPersons();

	int b;
	cin >> b;
}

