#pragma once

class GRADES {
private:
	int* grades;
	int size;
public:
	GRADES() : size(0), grades(new int[0]) {}

	GRADES(const GRADES& other) : size(other.size), grades(new int[other.size]) {
		for (int i = 0; i < other.size; ++i) {
			grades[i] = other.grades[i];
		}
	}

	GRADES& operator=(const GRADES& other) {
		if (this != &other) {
			delete[] grades;
			size = other.size;
			grades = new int[size];
			for (int i = 0; i < size; ++i) {
				grades[i] = other.grades[i];
			}
		}
		return *this;
	}

	~GRADES() {
		delete[] grades;
	}

	int getSize() const {
		return size;
	}

	int getGrade(int index) const {
		return grades[index];
	}

	void push(int grade) {
		int newSize = size + 1;
		int* newGrades = new int[newSize];

		for (int i = 0; i < size; ++i) {
			newGrades[i] = grades[i];
		}
		newGrades[size] = grade;

		delete[] grades;
		grades = newGrades;
		size = newSize;
	}

	void pop() {
		if (size == 0) {
			return;
		}
		size--;
	}

};