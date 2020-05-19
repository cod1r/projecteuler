/*
 * the sum of the squares of the first ten natural numbers is 385
 * the square of the sum of the first ten natural numbers is 3025
 * the difference between them is 2640
 */
#include <iostream>
using namespace std;

int main(){
	long long int sum = 0;
	long long int sumtobesquared = 0;
	for (int x = 1; x < 101; x++){
		sumtobesquared+=x;
	}
	sumtobesquared*=sumtobesquared;
	for (int x = 1; x < 101; x++){
		sum += x*x;
	}
	cout << sumtobesquared << " " << sum << endl;
	cout << sumtobesquared - sum << endl;
	return 0;
}
