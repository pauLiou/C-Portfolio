#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Rover {
public:
	int currentLocX; //current coordinate x
	int currentLocY; //current coordinate y
	char orientation; //compass direction currently facing
	bool move; // move or not
};

struct grid {
	vector<int> x;
	vector<int> y;
};

auto rectangle(int sizeX, int sizeY) { // creating the grid for the rover (dynamic array)

	grid coords = grid();

	for (int i = 0; i < sizeX; i++) {
		coords.x.push_back(i);
	}
	for (int i = 0; i < sizeY; i++) {
		coords.y.push_back(i);
	}

	return coords;
};

auto rotation(char direction,char turn) {
	char left = 'L';
	char right = 'R';
	int cardinalIndex;
	char currentOrient = direction; // direction currently oriented
	char cardinal[4] = { 'N','E','S','W' }; // the 4 cardinal compass directions in clockwise order

	for (int i = 0; i < 4; i++) {
		if (currentOrient == cardinal[i]) { // check that the entered cardinal direction is valid
			cardinalIndex = i; // set the cardinal index to the current orientation
			break;
		};
	}
	
	if (turn == left) {
		int index = cardinalIndex - 1; // turn left by minus 1 to the cardinal position (modulo)
		if (index < 0) {
			index = 3;
		}
		currentOrient = cardinal[index];
	}
	else if (turn == right) {
		int index = cardinalIndex + 1 % 3; // turn right by plus 1 to the cardinal position (modulo)
		if (index > 3) {
			index = 0;
		}
		currentOrient = cardinal[index];
	}
	
	return currentOrient;

}

int main() {
	auto result = rectangle(3, 5);



	
}