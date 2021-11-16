#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <memory>

using namespace std;

class Rover {
public:
	int currentLocX; //current coordinate x
	int currentLocY; //current coordinate y
	char orientation; //compass direction currently facing
	bool move; // move or not
	
};

struct grid {
	vector<int> gridX;
	vector<int> gridY;
};

auto rectangle(int sizeX, int sizeY) { // creating the grid for the rover (dynamic array)
	
	grid coords();
    coords().gridX;
	coords().gridY;

	
	for (int i = 0; i < sizeX; i++) {
		coords().gridX[i] = i;
	}
	for (int i = 0; i < sizeY; i++) {
		coords().gridY[i] = i;
	}


	return coords();
	
	}



int main() {
	auto result = rectangle(3, 5);

	//cout << rectangle(3,5) << endl;
	
}