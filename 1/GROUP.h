#pragma once
#include "STUDENT.h"

class GROUP {
public:
    GROUP() : quantityStudent(0), students(new STUDENT[0]) {
        std::cout << "GROUP default constructor called" << std::endl;
    }

    GROUP(const GROUP& other) : quantityStudent(other.quantityStudent), groupNumber(other.groupNumber), students(new STUDENT[other.quantityStudent]) {
        for (int i = 0; i < other.quantityStudent; ++i) {
            students[i] = other.students[i];
        }
    }

    GROUP& operator=(const GROUP& other) {
        if (this != &other) {
            delete[] students;
            quantityStudent = other.quantityStudent;
            students = new STUDENT[quantityStudent];
            for (int i = 0; i < quantityStudent; ++i) {
                students[i] = other.students[i];
            }
            groupNumber = other.groupNumber;
        }
        return *this;
    }

    ~GROUP() {
        std::cout << "GROUP destructor called" << std::endl;
    }

    void push(const STUDENT& student) {
        int newQuantityStudent = quantityStudent + 1;
        STUDENT* newStudents = new STUDENT[newQuantityStudent];

        for (int i = 0; i < quantityStudent; ++i) {
            newStudents[i] = students[i];
        }
        newStudents[quantityStudent] = student;

        delete[] students;
        students = newStudents;
        quantityStudent = newQuantityStudent;
    }

    void pop() {
        if (quantityStudent == 0) {
            return;
        }
        quantityStudent--;
    }

    bool displayHighAchievers() const {
        bool found = false;
        for (int i = 0; i < quantityStudent; ++i) {
            if (students[i].getAverageGrade() > 4.0) {
                std::cout << students[i].getName() << std::endl;
                std::cout << "Avarage grade: " << students[i].getAverageGrade();
                found = true;
            }
        }
        return found;
    }

    void setGroupNumber(std::string& number) {
        groupNumber = number;
    }

    std::string getGroupNumber() {
        return groupNumber;
    }

    void printStudets() {

        if (quantityStudent == 0) {
            std::cout << "Quantity students 0";
            return;
        }

        for (int i = 0; i < quantityStudent; ++i) {
            std::cout << students[i];
            std::cout << "Avarage grade: " << students[i].getAverageGrade() << std::endl;
        }

    }

private:
    STUDENT* students;
    int quantityStudent;
    std::string groupNumber;
};