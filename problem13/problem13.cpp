#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	string allnums;
	int sums[50];
	ifstream inputfile("input.txt");
	string temp;
	while(getline(inputfile,temp)){
		allnums+=temp;
	}
	inputfile.close();
	for (int x = 49; x >= 0; x--){
		int y = x, z = x + 50, sum = 0;
		while(y < 5000){
			sum += int(allnums[y])-'0';
			sum += int(allnums[z])-'0';
			y += 100;
			z += 100;
		}
		sums[x] = sum;
	}
	int carry = 0;
	for (int x = 49; x >= 0; x--){
		sums[x] += carry;
		carry = sums[x] / 10;
		sums[x] = sums[x] % 10;
	}
	string actual = to_string(carry);
	for (int x = 0; x < 50; x++)
	{
		actual += to_string(sums[x]);
	}
	cout << actual << endl;
	return 0;
}
