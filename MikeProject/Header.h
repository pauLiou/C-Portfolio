#include <string>

using namespace std;

#pragma once

auto output(); // the output text arrays
void typing(int num); // the function that allows for the typing animation
int inputdataInt(); // checking if the input values are integers
string inputdataChar(); // checking if the input values are chars


void run(int num); // the main run function that accesses the terminal/cmd to allow uses to play


// a view structs that are used in generating other functions

struct loc {
	int locX;
	int locY;
	string curOrient;
	bool alive;
};
struct input {
	int x;
	int y;
	int z;
};

auto movement(string rota, int x, int y, int maxX, int maxY); //  function that defines if the rover moves +1/-1 in any direction
loc rotation(string instruction, string orient, int x, int y, int maxX, int maxY); // function that rotates the direction the rover is facing
//auto currentLoc(int x, int y); // outputs the current location of the rover