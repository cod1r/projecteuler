#include <iostream>
#include <string>
using namespace std;

int main(){
	long long int max = 0;
	string digit;
	cin >> digit;
	for (int x = 0; x < digit.length()-12; x++)
	{
		long long int multiply = 1;
		for (int y = x; y < x+13; y++)
		{
			multiply*=int(digit[y])-'0';
			if (multiply > max)
				max = multiply;
		}
		cout << multiply << endl;
	}
	cout << endl;
	cout << max << endl;
	return 0;
}

