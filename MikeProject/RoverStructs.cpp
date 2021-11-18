#include <vector>

struct grid {
	std::vector<int> x;
	std::vector<int> y;
};
struct loc {
	int locX;
	int locY;
	char curOrient;
	bool alive;
};
struct input {
	int x;
	int y;
	int z;
};