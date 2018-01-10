#include <iostream>
using namespace std;
int main (int argc, char *argv[])
{
	double x, y;
	while(1)
	{
		cout << "\n Введите значение x: ";
		cin >> x;
		cout << "\n Введите значение y: ";
		cin >> y;
		bool t1 = (y >= 0);
		bool t2 = (x > 0) && (y <= -2*x + 2);
		bool t3 = (x <=0) && (y <= 2*x + 2);
		cout << (t1 && (t2 || t3) ? 1 : 0);
	}		
	return 0;
}       


