#pragma once
#include <string>
#include "degree.h" // This is needed to use the DegreeProgram enum

class Student
{
private:
    // Instance variables for student details
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3]; // Array for days to complete each course
    DegreeProgram degreeProgram;

public:
    // Constructor
    Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

    // Accessor (getter) functions
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmail() const;
    int getAge() const;
    const int *getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;

    // Mutator (setter) functions
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print function to display student data
    void print() const;
};
