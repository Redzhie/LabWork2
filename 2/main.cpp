#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("text.txt"); // ��������� ���� ��� ������
    if (!file.is_open()) {
        std::cerr << "�� ������� ������� ����" << std::endl;
        return 1;
    }

    std::string line, currentWord, previousWord;
    bool hasPrevious = false;

    while (std::getline(file, line)) { // ������ ������ �� �����
        std::istringstream iss(line);

        while (iss >> currentWord) {
            if (hasPrevious) {
                // ������� ���� ���� � �������� �������
                std::cout << currentWord << " " << previousWord << " ";
                hasPrevious = false;
            }
            else {
                hasPrevious = true;
                previousWord = currentWord;
            }
        }

        if (hasPrevious) {
            // ���� �������� ���� �����, ������� ���
            std::cout << previousWord << " ";
            hasPrevious = false;
        }

        std::cout << std::endl;
    }

    file.close(); // ��������� ����
    return 0;
}
