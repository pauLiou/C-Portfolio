#include <string>
#include "Header.h"

using namespace std;

auto movement(string rota, int x, int y, int maxX, int maxY) // moveBool = true when set to M, rota = currentOrient, x/y = class currentLoc
{
	loc currentLoc = loc();
	currentLoc.locX = x;
	currentLoc.locY = y;
	currentLoc.curOrient = rota;
	currentLoc.alive = true;
	string north = { 'N' };
	string south = { 'S' };
	string east = { 'E' };
	string west = { 'W' };


	if (rota == north) {
		currentLoc.locY = y + 1;
	}
	else if (rota == south) {
		currentLoc.locY = y - 1;
	}
	else if (rota == east) {
		currentLoc.locX = x + 1;
	}
	else if (rota == west) {
		currentLoc.locX = x - 1;
	}


	
	if (currentLoc.locX < 0 || currentLoc.locY < 0)
		currentLoc.alive = false;
	if (currentLoc.locX > maxX || currentLoc.locY > maxY)
		currentLoc.alive = false;
	// check if rover has crashed

	return currentLoc;
}

loc rotation(string instruction, string orient, int x, int y, int maxX, int maxY) {
	char left = 'L';
	char right = 'R';
	char move = 'M';
	int cardinalIndex;
	string cardinal[4] = { "N","S","E","W" }; // the 4 cardinal compass directions in clockwise order
	loc locationRotation = loc();
	locationRotation.curOrient = orient; // direction currently oriented
	locationRotation.locX = x; // current x coord
	locationRotation.locY = y; // current y coord
	if (x > maxX || y > maxY)
		locationRotation.alive = false;
	else
		locationRotation.alive = true;
	
	for (int i = 0; i < instruction.size(); i++) {

		if (locationRotation.alive == false)
			break;

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
			locationRotation = movement(locationRotation.curOrient, locationRotation.locX, locationRotation.locY, maxX, maxY);
		}

	}
	return locationRotation;
} // for the current orientation

//auto currentLoc(int x, int y) {
//	loc currentCoords = loc();
//	currentCoords.locX = x;
//	currentCoords.locY = y;
//
//	return currentCoords;
//}