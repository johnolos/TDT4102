
#include <iostream>

using namespace std;

void taskOne() {
	int num1 = 0;
	cout << "Skriv inn et tall: ";
	cin >> num1;
	cout << "Du skrev: " << num1 << endl;
	int num2 = 0;
	cout << "Skriv inn et tall til: ";
	cin >> num2;
	cout << "Summen av de to tallene er: " << num1 + num2 << endl;
}

void taskTwo() {
	int seconds;
	cout << "Skriv antall sekunder: ";
	cin >> seconds;
	int min = seconds / 60;
	seconds -= (min * 60);
	int hour = min / 60;
	min -= (hour * 60);
	cout << hour << " timer, " << min << " minutter og " << seconds << " sekunder " << endl;
	double dinner = 44.50;
	cout << "Måltidet: $" << dinner << endl;
	double mva = dinner/100*6.75;
	cout << "Mva: $" << mva << endl;
	cout << "Tips: $" << (dinner+mva)/100*15 << endl;
}

void taskThree() {
	int num;
	cout << "Skriv inn et tall: ";
	cin >> num;
	int odd = num % 2;
	if (odd) {
		cout << "Tallet er oddetall." << endl;
	} else {
		cout << "Tallet er partall." << endl;
	}

	double num2,num3;
	cout << "Skriv inn et tall: ";
	cin >> num2;
	cout << "Skriv inn et annet tall: ";
	cin >> num3;
	cout << (num2 > num3 ? num2 : num3) << " tallet er størst." << endl;
}

void taskFour() {
	cout << "N\t10*N\t100*N\t1000*N"<< endl;
	int a = 1;
	while (a != 6) {
		cout << a << "\t" << a*10 << "\t" << a*100 << "\t" << a*1000 << endl;
		a++;
	}
	double nok;
	cout << "Skriv inn antall NOK: " << endl;
	cin >> nok;
	while (nok < 0) {
		cout << "Skriv inn positivt tall: ";
		cin >> nok;
	}
	double euro = nok / 9.22;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << nok << " NOK er " << euro << " EUR." << endl;
	double amount, rente;
	cout << "Skriv inn laanebeloop: ";
	cin >> amount;
	cout << "Skriv inn rente: ";
	cin >> rente;
	a = 1;
	double betaling;
	double rest = amount;
	while (a != 11) {
		betaling = (amount/10) + ((rente/100)*rest);
		cout << "Year " << a << ":" << betaling << endl;
		rest -= betaling;
		cout << "Remaining: " << rest << endl;
		a++;
	}


}




int main() {
	taskOne();
	taskTwo();
	taskThree();
	taskFour();
	int a;
	cin >> a;
	return 0;
}


