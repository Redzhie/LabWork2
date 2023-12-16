#pragma once
#include <iostream>
#include <string>

#include "GRADES.h"

class STUDENT {
public:
    STUDENT() {
        std::cout << "STUDENT default constructor called" << std::endl;
    }

    STUDENT(const std::string& _name, GRADES _grades) : name(_name), grades(_grades){
        std::cout << "STUDENT parameterized constructor called" << std::endl;
    }

    STUDENT(const STUDENT& other) : name(other.name), grades(other.grades) {
        std::cout << "STUDENT copy constructor called" << std::endl;
    }

    ~STUDENT() {
        std::cout << "STUDENT destructor called" << std::endl;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    std::string getName() const {
        return name;
    }

    void setGrades(GRADES& newGrades) {
        grades = newGrades;
    }

    const GRADES& getGrades() const {
        return grades;
    }

    float getAverageGrade() const {
        float sum = 0.0f;
        int size = grades.getSize();
        for (int i = 0; i < grades.getSize(); ++i) {
            sum += grades.getGrade(i);
        }
        
        return sum / grades.getSize();
    }

    friend std::ostream& operator<<(std::ostream& out, const STUDENT& student);
    friend std::istream& operator>>(std::istream& in, STUDENT& student);

private:
    std::string name;
    GRADES grades;
};

std::ostream& operator<<(std::ostream& out, const STUDENT& student) {
    out << "Name: " << student.name << "\nGrades: ";
    for (int i = 0; i < student.grades.getSize(); ++i) {
        out << student.grades.getGrade(i) << " ";
    }
    out << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, STUDENT& student) {
    std::cout << "Enter name: ";
    in >> student.name;

    int size;
    std::cout << "Enter quantity grades: ";
    in >> size;

    std::cout << "Enter " << size << " grades:" << std::endl;

    GRADES grades;
    int grade;
    for (int i = 0; i < size; ++i) {
        in >> grade;
        grades.push(grade);
    }
    student.setGrades(grades);
    
    return in;
}