#pragma once
#include "student.h"

class Roster
{
private:
    int lastIndex = -1;                     // Keeps track of the last index in the array
    const static int numStudents = 5;       // The number of students in the roster
    Student *classRosterArray[numStudents]; // Array of pointers to Student objects

public:
    // Add a new student to the roster
    void add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    // Remove a student from the roster by studentID
    void remove(std::string studentID);

    // Print all students in the roster
    void printAll();

    // Print average days in course for a given student
    void printAverageDaysInCourse(std::string studentID);

    // Print Bad emails
    void printInvalidEmails();

    // Print students by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Destructor to free  memory
    ~Roster();
};
