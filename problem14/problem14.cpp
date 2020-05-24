#include <string>
#include <iostream>
using namespace std;

int main(){
	long long int start = 1e6;
	int count = 1;
	int maxstart = start;
	int maxcount = 0;
	while(start > 0){
		unsigned long long int n = start;
		while(n>0){
				if (n == 1){
					if (count > maxcount){
					maxstart = start;
					maxcount = count;
					}
					count = 1;
					start --;
					break;
				}
				if (n % 2 == 0){
					n /= 2;
				}
				else {
					n *= 3;
					n += 1;
				}
			count ++;
		}
	}
	cout << "The starting number under 1 mil that produces the longest chain is " << maxstart << endl;
	return 0;
}
