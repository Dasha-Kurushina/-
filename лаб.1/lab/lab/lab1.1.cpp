#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char *argv[])
{
	setlocale(0,"");
	int m, n;
	double r1, r4, x;
	bool r2, r3;
	cout << "\n Каким будет m?"; cin >> m;
	cout << "\n Каким будет n?"; cin >> n;
	cout << "\n Каким будет x?"; cin >> x;
	if (n > 0)
	{ 
		r1 = (float) m++ / n--;
		cout << "\n r1 = m++ / n--= " << r1 << endl;
		cout << "\n m1=" << m << endl;
		cout << "\n n1=" << n << endl;
	} else 
	{
		cout << "\n r1 невычислимо" << endl;
	}

	r2 = ++m < n--;
	cout << "\n r2 = ++m < n--= " << r2 << endl;
	cout << "\n m2=" << m << endl;
	cout << "\n n2=" << n << endl;

	r3 = n-- > m;
	cout << "\n r3 = n-- > m= " << r3 << endl;
	cout << "\n m3=" << m << endl;
	cout << "\n n3=" << n << endl;
	
	if (pow(x,2) + pow(x,3) > 0)
	{ 
		r4 = sin(pow(x,3)) + pow(x,4) + pow(pow(x,2) + pow(x,3),1/5);
		cout << "\n r4 = sin(pow(x,3)) + pow(x,4) + pow(pow(x,2) + pow(x,3),1/5)=" << r4 << endl;
		cout << "\n x=" << x << endl;
	} else 
	{
		cout << "\n r4 невычислимо" << endl;
	}
	

	return 0;
}

