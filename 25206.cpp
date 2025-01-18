#include <iostream>

using namespace std;

int main() {
	double myTotal = 0, total = 0;
	for (int i = 0; i < 20; i++) {
		string subject, myScore;
		double credit;
		cin >> subject >> credit >> myScore;
		if (myScore != "P") {
			if (myScore == "A+")
				myTotal += credit * 4.5;
			else if (myScore == "A0")
				myTotal += credit * 4.0;
			else if (myScore == "B+")
				myTotal += credit * 3.5;
			else if (myScore == "B0")
				myTotal += credit * 3.0;
			else if (myScore == "C+")
				myTotal += credit * 2.5;
			else if (myScore == "C0")
				myTotal += credit * 2.0;
			else if (myScore == "D+")
				myTotal += credit * 1.5;
			else if (myScore == "D0")
				myTotal += credit * 1.0;
			total += credit;
		}
	}
	cout << myTotal / total;
}
