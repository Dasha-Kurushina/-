#include <iostream>
#include <math.h>
using namespace std;

int main (int argc, char *argv[])
{
	char buffer [50];
	
	double a = 100;
	double b = 0.001;
	double c = pow(a + b, 3); 
	double d = pow(a, 3) + 3 * a * pow(b, 2); 
	double e = 3 * pow(a, 2) * b + pow(b, 3); 
	float  T1 = (c - d) / (float) e;
	double T2 = ((float)c - (float)d) / e;
	double T3 = (c - d) / e;
	double T4 = ((float)c - (float)d) / (float)e;
	double T5 = ((float)c - d) / e;
	
	sprintf (buffer, "T1=%f, T2=%f, T3=%f, T4=%f, T5=%f \n", T1, T2, T3, T4, T5);

	cout << buffer;
	return 0;
}


//   ( a+b )^3  - ( a ^3 + 3 a b ^ 2) 
//           3 a ^ 2 b + b ^ 3


