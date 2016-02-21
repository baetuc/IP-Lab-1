#include<iostream>
#include<vector>
using namespace std;

int totalNumber;
vector<int> numbers;
int max;

void readInfo() {
	cout << "Introduceti numarul de coloane: ";
	cin >> totalNumber;
	while (totalNumber <= 0) {
		cout << "Numar de coloane invalid. Introduceti o noua valoare: ";
		cin >> totalNumber;
	}
	int number;
	for (int i = 0; i < totalNumber; ++i) {
		cout << "Introduceti numarul " << i + 1 << ": ";
		cin >> number;
		while (number < 0) {
			cout << "Numar negativ. Introduceti din nou numarul " << i + 1 << ": ";
			cin >> number;
		}
		if (number > max) {
			max = number;
		}
		numbers.push_back(number);
	}
}

void solve() {
	cout << "|\n";
	while (max > 0) {
		cout << "| ";
		for (int i = 0; i < totalNumber; ++i) {
			cout << (numbers[i] >= max ? "* " : "  ");
			/*if (numbers[i] >= max) {
			cout << "* ";
			}
			else {
			cout << "  ";
			}
			*/
		}
		cout << '\n';
		--max;
	}
	cout << '+';
	for (int i = 0; i <= 2 * totalNumber; ++i) {
		cout << '-';
	}
	cout << "\n ";
	for (int i = 0; i < totalNumber; ++i) {
		cout << ' ' << i + 1;
	}
	cout << '\n';
}
/*
int main()
{
	readInfo();
	solve();
}
*/