#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
/*
 * A pythagorean triplet is a set of three natural numbers, a < b < c, for which, 
 * a^2 + b^2 = c^2
 * There exists exactly one pythagorean triplet for which a + b + c = 1000.
 * Find product abc.
 */
using namespace std;

int main(){
	for (int x = 100 ; x < 500 ; x++)
	{
		for (int y = 100; y < 500 ; y ++)
		{
			if (sqrt(x*x+y*y) == 1000-x-y)
			{
				cout << fixed << setprecision(25) << x*y*sqrt(x*x+y*y) << endl;
				return 0;
			}
		}
	}
	return 0;
}
