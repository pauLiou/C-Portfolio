#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <Windows.h>


using namespace std;

class Rover {
public:
	int currentLocX; //current coordinate x
	int currentLocY; //current coordinate y
	char orientation; //compass direction currently facing
	bool move; // move or not
	int gridSize[2];// size of the rectangle
};

struct grid {
	vector<int> x;
	vector<int> y;
};
struct loc {
	int locX;
	int locY;
	char curOrient;
};

auto output() {
	vector<string> text = { "Please write the size of the grid with a space deliminator (e.g. 4 5): ",
"The size of the plateau is = ",
"Please enter the starting location of the rover in integers (for both the X and Y axis) \n followed by a space, followed by the cardinal orientation of the rover (e.g. 1 2 N): ",
"The current location of the Rover is = ",
"The Rover is currently facing = ",
"Please describe how you would like to move with directions(L or R) and movement(M) in one long string of text with no spaces: " };

	return text;
}

auto typing(int num) {
	vector<string> t = output();
	int x = 0;
	while (t[num][x] != '\0')
	{
		cout << t[num][x];
		Sleep(50);
		x++;
	};
}
void run(Rover) {

	string movementInput;
	string orientationInput;
	Rover rover;
	typing(0);

	cin >> rover.gridSize[0] >> rover.gridSize[1];

	typing(1);

	cout << rover.gridSize[0] << " " << rover.gridSize[1] << endl;

	typing(2);

	cin >> rover.currentLocX >> rover.currentLocY >> rover.orientation;
	rover.orientation = toupper(rover.orientation); // convert to uppercase as precaution

	typing(3);

	cout << rover.currentLocX << " " << rover.currentLocY << endl;

	typing(4);

	cout << rover.orientation;

	typing(5);

	cin >> movementInput;
	for (auto& c : movementInput) c = toupper(c); // convert to uppercase just as precaution (but for string)

	auto rotationResult = rotation(movementInput, rover.orientation, rover.currentLocX, rover.currentLocY);
}
auto movement(bool moveBool, char rota, int x, int y) // moveBool = true when set to M, rota = currentOrient, x/y = class currentLoc
{
	loc currentLoc = loc();
	currentLoc.locX = x;
	currentLoc.locY = y;
	currentLoc.curOrient = rota;
	char north = { 'N' };
	char south = { 'S' };
	char east = { 'E' };
	char west = { 'W' };

	if (moveBool == true) {
		if (rota == north) {
			currentLoc.locY = y+1;
		}
		else if (rota == south) {
			currentLoc.locY = y-1;
		}
		else if (rota == east) {
			currentLoc.locX = x+1;
		}
		else if (rota == west) {
			currentLoc.locX = x-1;
		}

	}

	return currentLoc;
}

auto rotation(string instruction,char orient,int x,int y) {
	char left = 'L';
	char right = 'R';
	char move = 'M';
	int cardinalIndex;
	char cardinal[4] = { 'N','E','S','W' }; // the 4 cardinal compass directions in clockwise order
	loc locationRotation = loc();
	locationRotation.curOrient = orient; // direction currently oriented
	locationRotation.locX = x; // current x coord
	locationRotation.locY = y; // current y coord

	for (int i = 0; i < instruction.size(); i++) {

		
		

		for (int j = 0; j < 4; j++) {
			if (locationRotation.curOrient == cardinal[j]) { // check that the entered cardinal direction is valid
				cardinalIndex = j; // set the cardinal index to the current orientation
				break;
			};
		}

		if (instruction[i] == left) {
			int index = cardinalIndex - 1; // turn left by minus 1 to the cardinal position
			if (index < 0) {
				index = 3;
			}
			locationRotation.curOrient = cardinal[index];
		}
		else if (instruction[i] == right) {
			int index = cardinalIndex + 1; // turn right by plus 1 to the cardinal position
			if (index > 3) {
				index = 0;
			}
			locationRotation.curOrient = cardinal[index];
		}
		else if (instruction[i] == move) {
			locationRotation = movement(true, locationRotation.curOrient, locationRotation.locX, locationRotation.locY);
		}
		
	}
	
	return locationRotation;

} // for the current orientation

auto currentLoc(int x, int y) {
	loc currentCoords = loc();
	currentCoords.locX = x;
	currentCoords.locY = y;

	return currentCoords;
}


int main() {
	int totalRovers;
	cout << "How many rovers would you like to deploy?: " << endl;
	cin >> totalRovers;

	run(totalRovers);
	


	
	

	
	
	
	

	
}