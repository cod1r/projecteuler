#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    long long int carry = 0;
    string two = "2";
    ofstream outfile("output.txt");
    outfile << two << endl;
    for (int x = 0; x < 999; x++){
        string temp = "";
        for(int y = two.length()-1; y >= 0; y--){
            if (two.length() > 1){
                temp = to_string(((int(two[y]) - '0')+(int(two[y])-'0')+carry) % 10) + temp;
                carry = ((int(two[y]) - '0')+(int(two[y])-'0')) / 10;
            }
            else{
                temp = to_string(((int(two[y]) - '0')+(int(two[y])-'0')));
            }
        }
        if (carry > 0)
            temp = to_string(carry) + temp;
        two = temp;
        carry = 0;
        outfile << two << endl;
    }
    long long int sum = 0;
    for (int x = 0; x < two.length(); x++){
        sum += int(two[x])-'0';
    }
    outfile << sum << endl;
    outfile.close();
    return 0;
}