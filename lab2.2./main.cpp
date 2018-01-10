#include<iostream>

using namespace std;

int main() {
	int input = 0, max, n = 0, maxN = 0;

	cout<<"Введите число: ";
	cin>> input;
	n++;
	max = input;
	maxN = n;

	if (input == 0) {
		cout<<"\nОшибка";

	}
	else {
		while (true) {
		cout<<"\nВведите число: ";
		cin>> input;
		if (input == 0) {
			cout<<"\nНомер максимального числа = "<<maxN;

			break;
		}
		else {
			n++;
			if (input > max) {
				max = input;
				maxN = n;
			}
		}
		}
	}
}
