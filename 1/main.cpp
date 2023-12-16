#include "GROUP.h"


void sortGroupsByNumber(GROUP* groups, int size) {
	for (int i = 1; i < size; i++) {
		GROUP temp = groups[i];
		int j = i - 1;

		// Перемещение элементов, которые больше чем temp.groupNumber, на одну позицию вперед
		while (j >= 0 && groups[j].getGroupNumber() > temp.getGroupNumber()) {
			groups[j + 1] = groups[j];
			j--;
		}
		groups[j + 1] = temp;
	}
}

int main() {
	
	bool run = true;
	int choose;

	int countGroup = 0;
	GROUP* groups = new GROUP[countGroup];

	while (run) {
		system("cls");
		std::cout << "1. Add GROUP\n";
		std::cout << "2. Delete GROUP\n";
		std::cout << "3. Print GROUPS\n";
		std::cout << "4. Print STUDENTS where GRADES > 4.0\n";
		std::cout << "5. Exit\n";

		std::cout << "Choose index: ";
		std::cin >> choose;

		if (choose == 1) {
			system("cls");
			int newCountGroup = countGroup + 1;
			GROUP* newGroups = new GROUP[newCountGroup];

			for (int i = 0; i < countGroup; ++i) {
				newGroups[i] = groups[i];
			}
			delete[] groups;

			std::string numberGroup;
			std::cout << "Enter number group: ";
			std::cin >> numberGroup;

			GROUP tempGroup;

			tempGroup.setGroupNumber(numberGroup);

			int quantityStudents;
			std::cout << "Enter quantity students: ";
			std::cin >> quantityStudents;

			for (int i = 0; i < quantityStudents; ++i) {
				STUDENT tempStudent;
				std::cout << i + 1 << " student:\n";
				std::cin >> tempStudent;
				std::cout << std::endl;
				tempGroup.push(tempStudent);
			}

			newGroups[countGroup] = tempGroup;
			groups = newGroups;
			countGroup = newCountGroup;

			sortGroupsByNumber(groups, countGroup);
			system("pause");
		}

		if (choose == 2) {
			system("cls");
			for (int i = 0; i < countGroup; ++i) {
				std::cout << i + 1 << ") \n";
				std::cout << "Group number: " << groups[i].getGroupNumber() << std::endl;
				groups[i].printStudets();
				std::cout << std::endl;
			}
			std::cout << "Input index: ";
			int index;
			std::cin >> index;
			index--;

			int newCountGroup = countGroup - 1;
			GROUP* newGroups = new GROUP[newCountGroup];

			for (int i = 0, j = 0; i < countGroup; ++i) {
				if (i != index) {
					newGroups[j++] = groups[i];
				}
			}

			delete[] groups;
			groups = newGroups;
			countGroup = newCountGroup;

			sortGroupsByNumber(groups, countGroup);
			system("pause");
		}

		if (choose == 3) {
			system("cls");
			
			for (int i = 0; i < countGroup; ++i) {
				std::cout << i + 1 << ") \n";
				std::cout << "Group number: " << groups[i].getGroupNumber() << std::endl;
				groups[i].printStudets();
				std::cout << std::endl;
			}

			system("pause");
		}

		if (choose == 4) {
			system("cls");
			
			for (int i = 0; i < countGroup; ++i) {
				std::cout << "Number group: " << groups[i].getGroupNumber() << std::endl;
				if (!groups[i].displayHighAchievers()) {
					std::cout << "No high achievers found." << std::endl;
				}
			}

			system("pause");
		}

		if (choose == 5) {
			system("cls");
			run = false;
			system("pause");
		}

		if (choose > 5 or choose < 1) {
			system("cls");
			std::cout << "Invalid index\n";
			system("pause");
		}
	}

	return 0;
}