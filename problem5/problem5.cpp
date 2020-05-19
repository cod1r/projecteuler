/*
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the number from 1-20?
 */

#include <iostream>
using namespace std;

int main(){
	int x = 2520;
	int prev;
	while (true){
		prev = x;
		for (int y = 1 ; y < 21; y++){
			if (x % y != 0)
			{
				x++;
				break;
			}
		}
		if (prev == x)
		{
			cout << x << endl;
			return x;
		}
	}
	return 0;
}
