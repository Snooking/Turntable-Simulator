#include "Turntable.h"

Turntable *turntable = new Turntable();

int main() {
	int number_of_platforms;
	scanf("%d\n", &number_of_platforms);
	turntable->SetNumberOfPlatforms(number_of_platforms);
	turntable->GetPlatforms();
	turntable->Functions();
	turntable->GiveScore();
	delete turntable;
	return 0;
}
