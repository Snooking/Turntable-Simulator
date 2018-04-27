#ifndef STOS
#define STOS
#define DEFAULT_SIZE 10
#include <stdio.h>

template <class T> class Stack {
private:
	int size;
	int buffer_size;
	T* buffer;
public:
	Stack() {
		this->size = 0;
		this->buffer = new T[DEFAULT_SIZE];
		this->buffer_size = DEFAULT_SIZE;
	}

	Stack(int size) {
		this->buffer = new T*[size];
		this->buffer_size = size;
	}

	void Push(T var) {
			if (size >= buffer_size) {
				T* temp_buffer = new T[buffer_size]();

				for (int i = 0; i < buffer_size; i++) {
					temp_buffer[i] = buffer[i];
				}

				delete[] buffer;
				buffer_size *= 2;
				buffer = new T[buffer_size]();

				for (int i = 0; i < buffer_size / 2; i++) {
					buffer[i] = temp_buffer[i];
				}

				delete[] temp_buffer;
			}
			buffer[size] = var;
			size++;
}

	void PushToSize(T var) {
		if (size >= buffer_size)
			return;
		buffer[size] = var;
		size++;
	}

	void PushAtPlace(int position, T var) {
		if (position >= buffer_size) {
			delete[] buffer;
			buffer = new T[position]();
			buffer_size = position;
		}
		buffer[position - 1] = var;
		size++;
	}

	T Pop() {
		if (Empty()) return 99;
		size--;
		return buffer[size];
	}

	bool Empty() {
		if (size <= 0) {
			size = 0;
			return true;
			
		}
		return false;
	}
	int GetSize() {
		return size;
	}

	~Stack() {
		delete this->buffer;
	}
};
#endif