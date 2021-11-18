#include <iostream>
#include <string>
#include <vector>

#include "Header.h"

using namespace std;

class Rover {
public:
	Rover(int i = 0);
	int currentLocX; //current coordinate x
	int currentLocY; //current coordinate y
	char orientation; //compass direction currently facing
	bool move; // move or not
	int gridSize[2] = {};// size of the plateau
	int m_number;
	char validDir[4] = { 'N','S','E','W'};
};

Rover::Rover(int i)
{
	m_number = i;
}

void run(int num) {
	int number;
	string movementInput;
	string orientationInput;
	vector<Rover> rover;

	for (int i = 0; i < num; i++)
	{
		
		rover.emplace_back(i);// dynamic number of objects of class
		cout << "Activating Rover " << i+1 << endl;

		typing(0);
		rover[i].gridSize[0] = inputdataInt(); rover[i].gridSize[1] = inputdataInt();
	

		typing(1);
		cout << rover[i].gridSize[0] << " " << rover[i].gridSize[1] << endl;

		typing(2);
		rover[i].currentLocX = inputdataInt(); rover[i].currentLocY = inputdataInt(); 
		rover[i].orientation = inputdataChar();
		rover[i].orientation = toupper(rover[i].orientation); // convert to uppercase as precaution
		for (int j = 0; j < 4; j++) { // sanitise char input
			if (rover[i].orientation == rover[i].validDir[j]) {
				break;
			}
			else {
				cout << "Invalid cardinal direction, please select N S E or W: ";
				rover[i].orientation = inputdataChar();
			}
		}

		

		typing(3);
		cout << rover[i].currentLocX << " " << rover[i].currentLocY << endl;

		typing(4);
		cout << rover[i].orientation << endl;

		typing(5);
		movementInput = inputdataChar();
		for (auto& c : movementInput) c = toupper(c); // convert to uppercase just as precaution (but for string)
		auto rotationResult = rotation(movementInput, rover[i].orientation, rover[i].currentLocX, rover[i].currentLocY, rover[i].gridSize[0], rover[i].gridSize[1]);

		if (rotationResult.alive) {
			typing(6);
			cout << rotationResult.locX << " " << rotationResult.locY << " " << rotationResult.curOrient << endl;
		}
		else {
			typing(8);
			cout << endl;
		}


		system("pause");
	}

}

int main() {
	int totalRovers;
	cout << "How many rovers would you like to deploy?: " << endl;
	totalRovers = inputdataInt();

	run(totalRovers);
			
}