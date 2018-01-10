#include <iostream>
#include <math.h>

using namespace std;

int main (int argc, char *argv[])
{
	double a = 100; 
	double b = 0.001;

	double c = pow((a + b), 3); 
	double d = (pow(a, 3)) + (3 * pow(a, 2) * b);

	double e = (3 * a * pow(b, 2)) + (pow(b, 2));

	float result = (c - d) / e;

	cout << result; 

	return 0;

}