#ifndef TURNTABLE
#define TURNTABLE

#include "Stack.h"

class Turntable {
private:
	int number_of_functions;
	int number_of_platforms;
	Stack<int>* stack;
	Stack<int>** trains;
	int looking_at;
	enum {
		CMD_CLOCKWISE,
		CMD_COUNTER_CLOCKWISE,
		CMD_IN,
		CMD_OUT,
		CMD_ERROR
	} func;
	char cmd;
public:
	Turntable();
	void GetPlatforms();

	void SetNumberOfPlatforms(int nr);
	int GetNumberOfPlatforms();

	int ParseEnum();
	void Functions();
	void ReactToFunctions(int how_many);

	void GiveScore();

	~Turntable();
};

#endif