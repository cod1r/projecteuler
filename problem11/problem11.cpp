#include <string>
#include <iostream>
using namespace std;

int main(){
	int grid[20][20];
	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y ++)
		{
			cin >> grid[x][y];
		}
	}
	long long int max = 0;
	for (int x = 0; x < 20; x ++)
	{
		for (int y = 0 ; y < 20; y ++)
		{
			long long int num = grid[x][y];
			if (y + 3 < 20 && x + 3 < 20){
				num *= grid[x+1][y+1] * grid[x+2][y+2] * grid[x+3][y+3];
				if (num > max )
					max = num;
			}
			cout << num << " diagonal " << endl;
			num = grid[x][y];
			if (y - 3 >= 0 && x-3 >= 0){
				num *= grid[x-1][y-1] * grid[x-2][y-2] * grid[x-3][y-3];
				if (num > max )
					max = num;
			}
			cout << num << " diagonal "<< endl;
			num = grid[x][y];
			if (y -3 >= 0 && x+3 < 20)
			{
				num *= grid[x+1][y-1] * grid[x+2][y-2] * grid[x+3][y-3];
				if (num > max)
					max = num;
			}
			cout << num << " diagonal " << endl;
			num = grid[x][y];
			if ( x- 3 >= 0 && y + 3 < 20)
			{
				num *= grid[x-1][y+1] * grid[x-2][y+2] * grid[x-3][y+3];
				if (num > max)
					max = num;
			}
			cout << num << " diagonal " << endl;
			num = grid[x][y];
			if (y + 3 < 20)
			{
				num *= grid[x][y+1] * grid[x][y+2] * grid[x][y+3];
				if (num > max)
					max = num;
			}
			cout << num << " right " << endl;
			num = grid[x][y];
			if (x + 3 < 20)
			{
				num *= grid[x+1][y] * grid[x+2][y] * grid[x+3][y];
				if (num > max)
					max = num;
			}
			cout << num << " down " << endl;
			num = grid[x][y];
			if (x -3 >= 0)
			{
				num *= grid[x-1][y] * grid[x-2][y] * grid[x-3][y];
				if (num > max )
					max = num;
			}
			cout << num << " up " << endl;
			num = grid[x][y];
			if (y -3 >= 0)
			{
				num *= grid[x][y-1] * grid[x][y-2] * grid[x][y-3];
				if (num > max )
					max = num;
			}
			cout << num << " left " << endl;
		}
	}
		cout << max << endl;
		return 0;
}
