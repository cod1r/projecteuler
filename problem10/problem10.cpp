#include <string>
#include <iostream>
#include <math.h>
using namespace std;
/*
 * find the sum of all primes less than 2 million.
 */
int main(){
	long long int sum = 2;
	for (long long int x = 2; x < 2e6; x++)
	{
		bool isprime = true;
		for(long long int y = 2; y < sqrt(x)+1; y++)
		{
			if (x % y == 0)
			{
				isprime = false;
				break;
			}
		}
		if (isprime){
			sum += x;
		}
	}
	cout << sum << endl;
	return 0;
}
