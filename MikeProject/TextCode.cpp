#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include "Header.h"
using namespace std;


auto output() {
	vector<string> text = { "Please write the size of the grid with a space deliminator (e.g. 4 5): ",
		"The size of the plateau is = ",
		"Please enter the starting location of the rover in integers (for both the X and Y axis) \nFollowed by a space, followed by the cardinal orientation of the rover (e.g. 1 2 N): ",
		"The current location of the Rover is = ",
		"The Rover is currently facing = ",
		"Please describe how you would like to move with directions(L or R) and movement(M) in \none long string of text with no spaces: ",
		"The new location and orientation of the rover = ",
		"Press any key to deploy next rover...",
		"This robot has crashed (out of bounds)" };

	return text;
}

void typing(int num) {
	vector<string> t = output();
	int x = 0;
	while (t[num][x] != '\0')
	{
		std::cout << t[num][x];
		Sleep(1);
		x++;
	};
}
int inputdataInt() {
	
	int data;
	cin >> data;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid Instructions" << endl;
		cin >> data;
	}
	return abs(data);
}

string inputdataChar() {
	
	string data;
	cin >> data;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid Instructions" << endl;
		cin >> data;
	}
	return data;
}