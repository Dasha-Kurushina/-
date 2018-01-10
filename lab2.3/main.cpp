#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 0;
    double u = 0.0;

    do {
        n++;
        u = cos(cos(n)/sin(n));
        cout << "n=  " << n << endl;

    } while (u > 0);
    cout << "\nn=  " << n << endl;
    cout << "u = cos(cos(n)/sin(n))=  " << u << endl;

    return 0;
}
