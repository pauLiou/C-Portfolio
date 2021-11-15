#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Rover {
public:
	int currentLocX; //current coordinate x
	int currentLocY; //current coordinate y
	char direction; //direction either left or right
	bool move; // move or not
};


int rectangle(int sizeX,const int sizeY) { // creating the grid for the rover (dynamic array)
	
	int** grid = new int* [sizeY];
	for (int i = 0; i < sizeY; ++i) { // intialise the size of the matrix grid 
		grid[i] = new int[sizeX];
	}

	for (int i = 0; i < sizeY; ++i) {
		for (int k = 0; k < sizeX; ++k) // fill in the coordinates grid
			grid[sizeX][sizeY] = i;
	}
	
	return grid[1][3];
	
	}


int main() {

	cout << rectangle(3,5) << endl;
	
}