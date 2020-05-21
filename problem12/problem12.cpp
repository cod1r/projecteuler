#include <string>
#include <iostream>
using namespace std;

int main(){
	long long int SIZE = 50000;
	long long int trinums[2];
	trinums[0] = 1;
	for (int x = 1; x < SIZE; x++)
	{
		trinums[1] = x+1+trinums[0];
		trinums[0] = trinums[1];
		int factor = 0;
		for (int x = 1; x <= trinums[1]; x++)
		{
			if (factor >= 500){
				cout << trinums[1] << endl;
				return 0;
			}
			if (trinums[1] % x == 0)
			{
				factor ++;
			}
		}
	}
	return 0;
}

