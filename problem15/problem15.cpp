#include <string>
#include <iostream>
using namespace std;

int main(){
    int SIZE = 21;
    long long int grid[SIZE][SIZE];
    for(int x = SIZE-1; x >= 0; x--){
        for (int y = SIZE-1; y >= 0; y--){
            if (x == SIZE-1 || y == SIZE-1){
                grid[x][y] = 1;
            }
            else{
                grid[x][y] = grid[x+1][y] + grid[x][y+1];
            }
        }
    }
    cout << grid[0][0] << endl;
    return 0;
}