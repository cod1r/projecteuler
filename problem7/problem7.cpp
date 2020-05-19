#include <iostream>
using namespace std;

int main(){
	int counter = 0;
	for (int x = 2; x < 200000; x++)
	{
		bool prime = true;
		for (int y = 2; y < x; y++)
		{
			if (x % y == 0)
			{
				prime = false; 
				break;
			}
		}
		if (prime){
			counter ++;
			cout << x << " " << counter << endl;
		}
		if (counter == 10001)
			break;
	}
	return 0;
}
