#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("text.txt"); // Открываем файл для чтения
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    std::string line, currentWord, previousWord;
    bool hasPrevious = false;

    while (std::getline(file, line)) { // Читаем строку из файла
        std::istringstream iss(line);

        while (iss >> currentWord) {
            if (hasPrevious) {
                // Выводим пару слов в обратном порядке
                std::cout << currentWord << " " << previousWord << " ";
                hasPrevious = false;
            }
            else {
                hasPrevious = true;
                previousWord = currentWord;
            }
        }

        if (hasPrevious) {
            // Если осталось одно слово, выводим его
            std::cout << previousWord << " ";
            hasPrevious = false;
        }

        std::cout << std::endl;
    }

    file.close(); // Закрываем файл
    return 0;
}
