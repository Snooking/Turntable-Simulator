#include "Turntable.h"

Turntable::Turntable() {
	this->stack = new Stack<int>();
	this->looking_at = 0;
}

void Turntable::SetNumberOfPlatforms(int nr) {
	this->number_of_platforms = nr;
	this->trains = new Stack<int>*[nr]();
}

int Turntable::GetNumberOfPlatforms() {
	return this->number_of_platforms;
}

void Turntable::GetPlatforms() {
	int trains_on_platform;
	int train;
	for (int i = 0; i < this->number_of_platforms; i++) {
		scanf("%d", &trains_on_platform);
		this->trains[i] = new Stack<int>();
		for (int j = 0; j < trains_on_platform; j++) {
			scanf("%d", &train);
			this->trains[i]->PushAtPlace(trains_on_platform - j, train);
		}
	}
}

int Turntable::ParseEnum() {
	return this->cmd == 'z' ? CMD_CLOCKWISE :
		this->cmd == 'o' ? CMD_COUNTER_CLOCKWISE :
		this->cmd == 'w' ? CMD_IN :
		this->cmd == 'j' ? CMD_OUT :
		CMD_ERROR;
}

void Turntable::ReactToFunctions(int how_many) {
	switch (ParseEnum()) {
	case CMD_CLOCKWISE:
		this->looking_at = (this->looking_at + how_many) % this->number_of_platforms;
		break;
	case CMD_COUNTER_CLOCKWISE:
		this->looking_at = (this->looking_at - how_many) % this->number_of_platforms;
		if (this->looking_at < 0)
			this->looking_at += this->number_of_platforms;
		break;
	case CMD_IN:
		int train;
		for (int i = 0; i < how_many; i++)
		{
			if (stack->GetSize() < 10 && !trains[looking_at]->Empty()) {
				train = trains[looking_at]->Pop();
				stack->PushToSize(train);
			}
			else break;
		}
		break;
	case CMD_OUT:
		for (int i = 0; i < how_many; i++)
		{
			if (!stack->Empty()) {
				train = stack->Pop();
				trains[looking_at]->Push(train);
			}
			else break;
		}
		break;
	case CMD_ERROR:
		printf("Nierozpoznana komenda\n");
		break;
	default:
		printf("Zla komenda\n");
		break;
	}
}

void Turntable::Functions() {
	int number_of_elements;
	scanf("%d", &this->number_of_functions);
	for (int i = 0; i < this->number_of_functions; i++) {
		scanf(" %c %d", &this->cmd, &number_of_elements);
		ReactToFunctions(number_of_elements);
	}
}

void Turntable::GiveScore() {
	int train;
	int size;
	size = stack->GetSize();
	printf("%d ", size);
	for (int i = 0; i < size; i++)
	{
		train = stack->Pop();
		printf("%d ", train);
	}
	printf("\n");
	for (int i = 0; i < number_of_platforms; i++)
	{
		
		size = trains[looking_at]->GetSize();
		printf("%d ", size);
		for (int i = 0; i < size; i++)
		{
			train = trains[looking_at]->Pop();
			printf("%d ", train);
		}
		printf("\n");
		looking_at < number_of_platforms - 1 ? looking_at++ : looking_at = 0;
	}
}

Turntable::~Turntable() {
	delete this->stack;
	for (int i = 0; i < this->number_of_platforms; i++) {
		delete this->trains[i];
	}
	delete this->trains;
}